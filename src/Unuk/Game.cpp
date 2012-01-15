#include "Game.h"
#include "../libUnuk/Engine/NPC.h"
#include "../libUnuk/Engine/WorldManager.h"

Game::Game(void) {
  Debug::logger->message("Creating characters..");
  _player = new Player(&_map);

  _runGameReturnValue = gameMainMenu;
}

Game::~Game(void) {
  Debug::logger->message("\n----- Cleaning Up ------");
  // cleaning _player up caused a nice seg fault. I'll look later.
  //delete _player;
}

gameNavVal_t Game::Run(const string savegameIDArg) {
  _player->SetXY(50, 50);
	_player->LoadSprites("../Data/Media/Images/Characters/Player.png", 40, 45);

  LoadSavegame(savegameIDArg);

  int fps = 0;
  int frame = 0;
  int nextGameTick = SDL_GetTicks();

  Timer frameTimer;
  frameTimer.Start();

  Timer fpsCalc;
  fpsCalc.Start();

  Timer renderTimer;
  Timer updateTimer;

  _gameRenderTime.SetXY(10, 10);
  _gameRenderTime.SetTextBlended("Render - XX", vsmall, COLOUR_BLACK);

  _gameUpdateTime.SetXY(10, 30);
	_gameUpdateTime.SetTextBlended("Update - XX", vsmall, COLOUR_BLACK);

  stringstream playerXYString;
  _playerXY.SetXY(10, 50);
  _playerXY.SetTextBlended("Player coords - XX XX", vsmall, COLOUR_BLACK);

  stringstream playerHealth;
  _playerHealth.SetXY(10, 80);
  _playerHealth.SetTextBlended("Player Health - XX", vsmall, COLOUR_BLACK);

  stringstream npcHealth;
  _npcHealth.SetXY(10, 100);
	_npcHealth.SetTextBlended("NPC X Health - XX", vsmall, COLOUR_BLACK);

  _gameRunning = true;
  while(_gameRunning) {
		bool stillRunning = true;

    updateTimer.Start();
    while((int)SDL_GetTicks() > nextGameTick) {
      HandleInput();
			if (!_gameRunning) {
        stillRunning = false;
        break;
			}

			UpdateGame();

      nextGameTick += SKIP_TICKS;
    }
    updateTimer.Pause();

    if (!stillRunning) {
	    break;
    }

    renderTimer.Start();
    Render();
    renderTimer.Pause();

    // Calculate and display our FPS.
    if(fpsCalc.GetTicks() >= 1000) {
      fps = frame / (fpsCalc.GetTicks() / 1000);

      stringstream caption;
      caption << "Unuk - FPS: " << fps;

      SDL_WM_SetCaption(caption.str().c_str(), NULL);

      fpsCalc.Start();
      frame = 0;

      // Check to see if we are allowed to display debug info.
      if(debugEnabled) {
        _gameUpdateTime.SetTextBlended("Update - " + updateTimer.GetTicksStr(), vsmall, COLOUR_BLACK);
        _gameRenderTime.SetTextBlended("Render - " + renderTimer.GetTicksStr(), vsmall, COLOUR_BLACK);

        playerXYString.str("");
        playerXYString << "Player coords: x" << _player->GetX() << ", y" << _player->GetY();
        _playerXY.SetTextBlended(playerXYString.str(), vsmall, COLOUR_BLACK);

        playerHealth.str("");
        playerHealth << "Player Health: " << _player->GetHealth();
        _playerHealth.SetTextBlended(playerHealth.str(), vsmall, COLOUR_BLACK);

        int npc0Health = 0;
        if(_map.GetWorld().GetNPCCount() == 0) {
          npc0Health = 0;
        }
        else {
          npc0Health = _map.GetWorld().GetNPC(0)->GetHealth();
        }

        npcHealth.str("");
        npcHealth << "NPC 0 Health: " << npc0Health;
        _npcHealth.SetTextBlended(npcHealth.str(), vsmall, COLOUR_BLACK);
      }
    }
    // Restrict the fps.
    if(1000 / MAX_FPS > frameTimer.GetTicks()) {
      // SDL_Delay does not accept a float so for higher framerate
      // limits there's an innacuracy. This is as much as 3fps
      // at a limit of 60fps.
      SDL_Delay((1000 / MAX_FPS) - frameTimer.GetTicks());
    }
    frameTimer.Start();
    frame++;
  }
  return _runGameReturnValue;
}

void Game::HandleInput(void) {
  if(_ingameMenu.GetStatus() == false) {
    while(SDL_PollEvent(&event)) {
      _player->HandleInput();

      if(event.key.type == SDL_KEYDOWN) {
        if(event.key.keysym.sym == SDLK_ESCAPE)
          _ingameMenu.SetStatus(true);
        if(event.key.keysym.sym == SDLK_p)
          debugEnabled = !debugEnabled;
      }
      else if(event.type == SDL_QUIT) {
        _gameRunning = false;
        _runGameReturnValue = gameQuitGame;
        break;
      }
    }
  } else {
    switch(_ingameMenu.HandleInput()) {
    case ingameMenuNothing:
      break;
    case ingameMenuResume:
      _ingameMenu.SetStatus(false);
      break;
    case ingameMenuSaveGame:
      SaveSavegame();
      _ingameMenu.SetStatus(false);
      Debug::logger->message("Game Saved!");
      break;
    case ingameMenuLoadGame:
      LoadSavegame(_saveGameID);
      _ingameMenu.SetStatus(false);
      Debug::logger->message("Game Loaded!");
      break;
    case ingameMenuOptions:
      break;
    case ingameMenuMainMenu:
      _gameRunning = false;
      break;
    }

    if(event.type == SDL_QUIT) {
      _gameRunning = false;
      _ingameMenu.SetStatus(false);
      _runGameReturnValue = gameQuitGame;
    }
  }
}

void Game::UpdateGame(void) {
  if(_ingameMenu.GetStatus() == false) {
    _map.Update();
    _player->Update();
  } else {
    // :D
  }
}

void Game::Render(void) {
	// SDL_FillRect(screen, NULL, 0); //  You might want to clear the buffer! --konom
  if(_ingameMenu.GetStatus() == false) {
    _map.Render();
    _player->Render();

    if(debugEnabled) {
      _gameRenderTime.RenderLiteral();
      _gameUpdateTime.RenderLiteral();
      _playerXY.RenderLiteral();
      _playerHealth.RenderLiteral();
      _npcHealth.RenderLiteral();
    }
  } else {
    _ingameMenu.Render();
  }
  SDL_Flip(screen);
}

void Game::LoadSavegame(const string savegameIDArg) {
  _saveGameID = savegameIDArg;
  string saveFilename = "../Save/" + _saveGameID;

  // Converting to XML ftw!
  TiXmlDocument mapFile(saveFilename.c_str());
  assert(mapFile.LoadFile() == true);
  
  TiXmlElement* rootElem = NULL;
  TiXmlElement* dataElem = NULL;
  
  // <save> - Grab a save file.
  rootElem = mapFile.FirstChildElement("save");
  assert(rootElem != NULL);
  if(rootElem) {
    // <name> - Parse the player name.
    dataElem = rootElem->FirstChildElement("name");
    assert(dataElem != NULL);

    // Overloaded new/delete operator takes this out of scope..
    // TODO: Fix.
    //_player->SetName(dataElem->GetText());
    // </name>
    
    // <x> - Parse the player x coord.
    dataElem = dataElem->NextSiblingElement("x");
    assert(dataElem != NULL);
    int playerX = atoi(dataElem->GetText());
    // </x>
    
    // <y> - Parse the player y coord.
    dataElem = dataElem->NextSiblingElement("y");
    assert(dataElem != NULL);
    int playerY = atoi(dataElem->GetText());
    // </y>
    
    _player->SetXY((float)playerX, (float)playerY);
    
    // <map> - Parse the map file.
    dataElem = dataElem->NextSiblingElement("map");
    assert(dataElem != NULL);
    _map.Load(dataElem->GetText());
    // </map>
  }
  // <save>
  
  // </save>
}

void Game::SaveSavegame(void) {
  string saveFilename = "../Save/" + _saveGameID;

  TiXmlDocument doc;

  TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");

  TiXmlElement* saveElement = new TiXmlElement("save");

  TiXmlElement* nameElement = new TiXmlElement("name");
  TiXmlText* nameText = new TiXmlText("Allanis"); //TODO: replace with _player->GetName() when it works. --konom
  nameElement->LinkEndChild(nameText);

  std::stringstream xString;
  xString << _player->GetX();

  TiXmlElement* xElement = new TiXmlElement("x");
  TiXmlText* xText = new TiXmlText(xString.str().c_str());
  xElement->LinkEndChild(xText);

  std::stringstream yString;
  yString << _player->GetY();

  TiXmlElement* yElement = new TiXmlElement("y");
  TiXmlText* yText = new TiXmlText(yString.str().c_str());
  yElement->LinkEndChild(yText);

  TiXmlElement* mapElement = new TiXmlElement("map");
  TiXmlText* mapText = new TiXmlText("map"); //TODO: replace with actual map name.
  mapElement->LinkEndChild(mapText);

  saveElement->LinkEndChild(nameElement);
  saveElement->LinkEndChild(xElement);
  saveElement->LinkEndChild(yElement);
  saveElement->LinkEndChild(mapElement);

  doc.LinkEndChild(decl);
  doc.LinkEndChild(saveElement);

  doc.SaveFile(saveFilename.c_str());
}
