LIBS += -lGL \
    -lSDL \
    -lGLU
RESOURCES += 
OTHER_FILES += ../src/libUnuk/Vec2.o \
    ../src/libUnuk/ImageLoader.o \
    ../src/libUnuk/GlxWindow.o \
    ../src/libUnuk/Sprite.o \
    ../src/libUnuk/Debug.o
HEADERS += ../src/libUnuk/ImageLoader.h \
    ../src/libUnuk/Sprite.h \
    ../src/libUnuk/Debug.h \
    ../src/Libs/wglext.h \
    ../src/Libs/glxext.h \
    ../src/Unuk/Game.h \
    ../src/Unuk/Player.h \
    ../src/libUnuk/Static.h \
    ../src/libUnuk/Geometry.h \
    ../src/libUnuk/Entity.h \
    ../src/libUnuk/EntityType.h \
    ../src/libUnuk/Input.h
SOURCES += ../src/libUnuk/Sprite.cpp \
    ../src/libUnuk/ImageLoader.cpp \
    ../src/libUnuk/Debug.cpp \
    ../src/Unuk/Player.cpp \
    ../src/Unuk/main.cpp \
    ../src/Unuk/Game.cpp \
    ../src/libUnuk/Entity.cpp \
    ../src/libUnuk/Input.cpp