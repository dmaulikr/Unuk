LIBS += -lGL \
    -lSDL \
    -lSDL_ttf \
    -lSDL_image \
    -lSDL_gfx \
    -ltinyxml \
    -lGLU
HEADERS += ../src/Libs/wglext.h \
    ../src/Libs/glxext.h \
    ../src/libUnuk/Engine/WorldManager.h \
    ../src/libUnuk/Engine/ParticleEmitter.h \
    ../src/libUnuk/Engine/NPC.h \
    ../src/libUnuk/Engine/MemManager.h \
    ../src/libUnuk/Engine/MemClass.h \
    ../src/libUnuk/Engine/Collision.h \
    ../src/libUnuk/Engine/Character.h \
    ../src/libUnuk/Engine/AStarBase.h \
    ../src/libUnuk/Engine/AStar.h \
    ../src/libUnuk/Map/MapTile.h \
    ../src/libUnuk/Map/MapEntities.h \
    ../src/libUnuk/Map/MapElement.h \
    ../src/libUnuk/Map/Map.h \
    ../src/libUnuk/Sprite/TextureManager.h \
    ../src/libUnuk/Sprite/Texture.h \
    ../src/libUnuk/Sprite/ImageLoader.h \
    ../src/libUnuk/Sprite/ApplySurface.h \
    ../src/libUnuk/System/Rect.h \
    ../src/libUnuk/System/Input.h \
    ../src/libUnuk/System/FPS.h \
    ../src/libUnuk/System/Debug.h \
    ../src/libUnuk/System/Timer.h \
    ../src/libUnuk/Ui/MainMenu.h \
    ../src/libUnuk/Ui/IngameMenu.h \
    ../src/libUnuk/Ui/Font.h \
    ../src/libUnuk/Ui/ButtonToggle.h \
    ../src/libUnuk/Ui/ButtonGroup.h \
    ../src/libUnuk/Ui/Button.h \
    ../src/libUnuk/Ui/Text.h \
    ../src/Unuk/Globals.h \
    ../src/Unuk/Game.h \
    ../src/Unuk/Constants.h \
    ../src/Unuk/Player.h
SOURCES += ../src/libUnuk/Engine/WorldManager.cpp \
    ../src/libUnuk/Engine/ParticleEmitter.cpp \
    ../src/libUnuk/Engine/NPC.cpp \
    ../src/libUnuk/Engine/MemManager.cpp \
    ../src/libUnuk/Engine/Collision.cpp \
    ../src/libUnuk/Engine/Character.cpp \
    ../src/libUnuk/Engine/AStar.cpp \
    ../src/libUnuk/Map/MapEntities.cpp \
    ../src/libUnuk/Map/MapElement.cpp \
    ../src/libUnuk/Map/Map.cpp \
    ../src/libUnuk/Sprite/TextureManager.cpp \
    ../src/libUnuk/Sprite/Texture.cpp \
    ../src/libUnuk/Sprite/ImageLoader.cpp \
    ../src/libUnuk/Sprite/ApplySurface.cpp \
    ../src/libUnuk/System/Timer.cpp \
    ../src/libUnuk/System/Rect.cpp \
    ../src/libUnuk/System/Input.cpp \
    ../src/libUnuk/System/FPS.cpp \
    ../src/libUnuk/System/Debug.cpp \
    ../src/libUnuk/Ui/Text.cpp \
    ../src/libUnuk/Ui/MainMenu.cpp \
    ../src/libUnuk/Ui/IngameMenu.cpp \
    ../src/libUnuk/Ui/Font.cpp \
    ../src/libUnuk/Ui/ButtonToggle.cpp \
    ../src/libUnuk/Ui/ButtonGroup.cpp \
    ../src/libUnuk/Ui/Button.cpp \
    ../src/Unuk/Player.cpp \
    ../src/Unuk/main.cpp \
    ../src/Unuk/Globals.cpp \
    ../src/Unuk/Game.cpp
OTHER_FILES += 
