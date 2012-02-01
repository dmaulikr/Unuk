#include "Player.h"
#include "Globals.h"
#include "../libUnuk/UI/EventHistory.h"

// Pixels * 60 / sec.
const float Player::PLAYER_SPEED = Character::CHARACTER_SPEED + 0.5f;

// Amount of Exp needed to level up from 1 to 2
const int Player::BASE_EXP_NEEDED = 10;

Player::Player(LevelGen *mapArg) : Character(mapArg) {
    _level = 1;
    _exp = 0;
    _expNeeded = BASE_EXP_NEEDED;
}

Player::~Player(void) {

}

void Player::HandleInput(void) {
  if(event.key.type == SDL_KEYDOWN) {
    switch(event.key.keysym.sym) {
    case SDLK_w:
    case SDLK_UP:
      yVel -= PLAYER_SPEED;
      xVel = 0;
      directionFacing = FACING_UP;
      break;
    case SDLK_s:
    case SDLK_DOWN:
      yVel += PLAYER_SPEED;
      xVel = 0;
      directionFacing = FACING_DOWN;
      break;
    case SDLK_a:
    case SDLK_LEFT:
      xVel -= PLAYER_SPEED;
      yVel = 0;
      directionFacing = FACING_LEFT;
      break;
    case SDLK_d:
    case SDLK_RIGHT:
      xVel += PLAYER_SPEED;
      yVel = 0;
      directionFacing = FACING_RIGHT;
      break;
    case SDLK_SPACE:
      attacking = true;
      attackTimer.Start();
      map->GetWorld().OnPlayerAttack(this);
      break;
    default:
      break;
    }
  }
  else if(event.key.type == SDL_KEYUP) {
    switch(event.key.keysym.sym) {
    case SDLK_w: case SDLK_UP:      yVel = 0; break;
    case SDLK_s: case SDLK_DOWN:    yVel = 0; break;
    case SDLK_a: case SDLK_LEFT:    xVel = 0; break;
    case SDLK_d: case SDLK_RIGHT:   xVel = 0; break;
    default: break;
    }
  }
  else if(event.type == SDL_MOUSEBUTTONDOWN) {
    if(event.button.button == SDL_BUTTON_LEFT) {
      attacking = true;
      attackTimer.Start();
      map->GetWorld().OnPlayerAttack(this);
    }
  }
}

void Player::Update(void) {
  Move();
  AddSpeachBubble("Woot, My name is Allanis, welcome to my home. Just testing some more text to see if this works..");

  // For now The camera will be static.
  //SetCamera();

  _healthBar.SetProgress((float)GetHealth() / 100.0f);
}

void Player::SetName(string nameArg) {
  _name = nameArg;
}

void Player::SetCamera(void) {
  camera.x = (Sint16)((x + w / 2) - SCREEN_WIDTH  / 2);
  camera.y = (Sint16)((y + h / 2) - SCREEN_HEIGHT / 2);

  if(camera.x < 0)
    camera.x = 0;
  if(camera.y < 0)
    camera.y = 0;

  if(camera.x > levelWidth - camera.w)
    camera.x = levelWidth - camera.w;
  if(camera.y > levelHeight - camera.h)
    camera.y = levelHeight = camera.h;
}

void Player::Move() {
  Character::Move();
  if(map->GetMapTransitionName(tileX, tileY) != "null") {
    SetXY((float)map->GetMapTransitionX(tileX, tileY), (float)map->GetMapTransitionY(tileX, tileY));
    map->Load(map->GetMapTransitionName(tileX, tileY));
  }
}

void Player::SetLevel(int level) {
  _level = level;
  _exp = _exp - _expNeeded;
  if(_exp < 0) {
    _exp = 0;
  }
  _expNeeded = pow(BASE_EXP_NEEDED, _level);
}

void Player::SetExp(int exp) {
  std::stringstream evtMsg;
  evtMsg << "Gained " << exp << " Experience Points.";
  eventHistory->LogEvent(evtMsg.str());
  
  _exp += exp;
  if(_exp >= _expNeeded) {
      eventHistory->LogEvent("Player leveled up!");
      SetLevel(_level + 1);
  } 
}

void Player::SetExpNeeded(int expNeeded) {
  _expNeeded = expNeeded;
}
