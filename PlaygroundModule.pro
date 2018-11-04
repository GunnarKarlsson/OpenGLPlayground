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
            "$$_PRO_FILE_PWD_/../glm"

LIBS += "$$_PRO_FILE_PWD_/../assimp/build/code/libassimp.dylib"

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    gamewindow.cpp \
    assetmanager.cpp \
    shader.cpp \
    basicshader.cpp \
    scene.cpp \
    gamescene.cpp \
    lightboxshader.cpp \
    modelloader.cpp \
    cube.cpp \
    loadedmodel.cpp \
    mesh.cpp \
    loadedmodelshader.cpp \
    skybox.cpp \
    skyboxshader.cpp

HEADERS += \
        mainwindow.h \
    stb_image.h \
    gamewindow.h \
    assetmanager.h \
    common.h \
    camera.h \
    shader.h \
    basicshader.h \
    scene.h \
    gamescene.h \
    lightboxshader.h \
    modelloader.h \
    cube.h \
    loadedmodel.h \
    mesh.h \
    loadedmodelshader.h \
    skybox.h \
    skyboxshader.h

FORMS += \
        mainwindow.ui

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
    skybox.frag

RESOURCES += \
    resources.qrc
