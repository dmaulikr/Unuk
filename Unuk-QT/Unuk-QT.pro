unix {
	QMAKE_CXXFLAGS += -m32
}
CONFIG -= qt
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
    ../src/libUnuk/Engine/Collision.h \
    ../src/libUnuk/Engine/Character.h \
    ../src/libUnuk/Sprite/TextureManager.h \
    ../src/libUnuk/Sprite/Texture.h \
    ../src/libUnuk/Sprite/ImageLoader.h \
    ../src/libUnuk/Sprite/ApplySurface.h \
    ../src/libUnuk/System/Serialiser.h \
    ../src/libUnuk/System/Serialisable.h \
    ../src/libUnuk/System/Rect.h \
    ../src/libUnuk/System/Input.h \
    ../src/libUnuk/System/FPS.h \
    ../src/libUnuk/System/Debug.h \
    ../src/libUnuk/System/Timer.h \
    ../src/libUnuk/UI/MainMenu.h \
    ../src/libUnuk/UI/IngameMenu.h \
    ../src/libUnuk/UI/Font.h \
    ../src/libUnuk/UI/ButtonToggle.h \
    ../src/libUnuk/UI/ButtonGroup.h \
    ../src/libUnuk/UI/Button.h \
    ../src/libUnuk/UI/Text.h \
    ../src/Unuk/Globals.h \
    ../src/Unuk/Game.h \
    ../src/Unuk/Constants.h \
    ../src/Unuk/Player.h \
    ../src/libUnuk/LevelGen/LevelGen.h \
    ../src/libUnuk/LevelGen/MapEntities.h \
    ../src/libUnuk/LevelGen/MapElement.h \
    ../src/libUnuk/LevelGen/MapTile.h \
    ../src/libUnuk/LevelGen/AStarTile.h \
    ../src/libUnuk/UI/EventHistory.h \
    ../src/libUnuk/UI/Bar.h \
    ../src/libUnuk/System/Vec2.h \
    ../src/libUnuk/System/MathBox.h \
    ../src/libUnuk/Engine/Pathfinding.h \
    ../src/libUnuk/UI/SavegameMenu.h \
    ../src/libUnuk/Engine/Spells.h \
    ../src/libUnuk/Engine/MemManager.h
SOURCES += ../src/libUnuk/Engine/WorldManager.cpp \
    ../src/libUnuk/Engine/ParticleEmitter.cpp \
    ../src/libUnuk/Engine/NPC.cpp \
    ../src/libUnuk/Engine/Collision.cpp \
    ../src/libUnuk/Engine/Character.cpp \
    ../src/libUnuk/Sprite/TextureManager.cpp \
    ../src/libUnuk/Sprite/Texture.cpp \
    ../src/libUnuk/Sprite/ImageLoader.cpp \
    ../src/libUnuk/Sprite/ApplySurface.cpp \
    ../src/libUnuk/System/Serialiser.cpp \
    ../src/libUnuk/System/Timer.cpp \
    ../src/libUnuk/System/Rect.cpp \
    ../src/libUnuk/System/Input.cpp \
    ../src/libUnuk/System/FPS.cpp \
    ../src/libUnuk/System/Debug.cpp \
    ../src/libUnuk/UI/Text.cpp \
    ../src/libUnuk/UI/MainMenu.cpp \
    ../src/libUnuk/UI/IngameMenu.cpp \
    ../src/libUnuk/UI/Font.cpp \
    ../src/libUnuk/UI/ButtonToggle.cpp \
    ../src/libUnuk/UI/ButtonGroup.cpp \
    ../src/libUnuk/UI/Button.cpp \
    ../src/Unuk/Player.cpp \
    ../src/Unuk/main.cpp \
    ../src/Unuk/Globals.cpp \
    ../src/Unuk/Game.cpp \
    ../src/libUnuk/LevelGen/LevelGen.cpp \
    ../src/libUnuk/LevelGen/MapEntities.cpp \
    ../src/libUnuk/LevelGen/MapElement.cpp \
    ../src/libUnuk/LevelGen/MapTile.cpp \
    ../src/libUnuk/LevelGen/AStarTile.cpp \
    ../src/libUnuk/UI/EventHistory.cpp \
    ../src/libUnuk/UI/Bar.cpp \
    ../src/libUnuk/System/Vec2.cpp \
    ../src/libUnuk/UI/SavegameMenu.cpp \
    ../src/libUnuk/Engine/Spells.cpp \
    ../src/libUnuk/Engine/MemManager.cpp
