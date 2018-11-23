QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlaygroundModule
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

-L"$$PWD/sqlite3"

INCLUDEPATH += \
            "$$_PRO_FILE_PWD_/../glm" \
            "$$_PRO_FILE_PWD_/../assimp/include" \
            "$$_PRO_FILE_PWD_/../assimp/build/include"\
            "$$_PRO_FILE_PWD_/../glm"\
            "$$_PRO_FILE_PWD_/../freetype/include"

LIBS += "$$_PRO_FILE_PWD_/../assimp/build/code/libassimp.dylib"
LIBS += "/usr/local/lib/libfreetype.dylib"

SOURCES += \
        main.cpp \
    gamewindow.cpp \
    assetmanager.cpp \
    shader.cpp \
    scene.cpp \
    gamescene.cpp \
    modelloader.cpp \
    cube.cpp \
    loadedmodel.cpp \
    mesh.cpp \
    skybox.cpp \
    textrenderer.cpp \
    quad.cpp \
    shadermanager.cpp \
    smoke.cpp \
    particle.cpp

HEADERS += \
    stb_image.h \
    gamewindow.h \
    assetmanager.h \
    common.h \
    camera.h \
    shader.h \
    scene.h \
    gamescene.h \
    modelloader.h \
    cube.h \
    loadedmodel.h \
    mesh.h \
    skybox.h \
    textshader.h \
    textrenderer.h \
    quad.h \
    shadermanager.h \
    smoke.h \
    particle.h

FORMS +=

DISTFILES += \
    basic.vert \
    basic.frag \
    lightbox.vert \
    lightbox.frag \
    spaceCraft4.obj \
    spaceCraft4.mtl \
    loadedmodel.vert \
    loadedmodel.frag \
    rockFormationLarge.obj \
    rockFormationLarge.mtl \
    SKY_BACK.png \
    SKY_DOWN.png \
    SKY_FRONT.png \
    SKY_LEFT.png \
    SKY_RIGHT.png \
    SKY_UP.png \
    skybox.vert \
    skybox.frag \
    arial.ttf \
    text.vert \
    text.frag \
    README.md \
    heart.png \
    heart.png \
    quad.vert \
    quad.frag \
    quad_tile.png \
    Textures/cube.png \
    Textures/panel.png \
    Textures/SKY_BACK.png \
    Textures/SKY_DOWN.png \
    Textures/SKY_FRONT.png \
    Textures/SKY_LEFT.png \
    Textures/SKY_RIGHT.png \
    Textures/SKY_UP.png \
    Shaders/text.frag \
    Shaders/text.vert \
    Shaders/basic.frag \
    Shaders/lightbox.frag \
    Shaders/loadedmodel.frag \
    Shaders/quad.frag \
    Shaders/skybox.frag \
    Shaders/basic.vert \
    Shaders/lightbox.vert \
    Shaders/loadedmodel.vert \
    Shaders/quad.vert \
    Shaders/skybox.vert \
    Meshes/rockFormationLarge.obj \
    Meshes/spaceCraft4.obj \
    Meshes/rockFormationLarge.mtl \
    Meshes/spaceCraft4.mtl \
    Fonts/Aero.ttf \
    Textures/smoke_03.png \
    Textures/smoke_04.png \
    Textures/smoke_06.png \
    Shaders/particle.frag \
    Shaders/particle.vert \
    Meshes/crater.obj \
    Meshes/crater.mtl

RESOURCES += \
    resources.qrc
