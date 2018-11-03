#-------------------------------------------------
#
# Project created by QtCreator 2018-11-02T20:12:31
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlaygroundModule
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
            "/Users/gunnarkarlsson/git/glm" \
            "/Users/gunnarkarlsson/git/assimp/include" \
            "/Users/gunnarkarlsson/git/assimp/build/include"\
            "/Users/gunnarkarlsson/git/glm"

LIBS += "/Users/gunnarkarlsson/git/assimp/build/code/libassimp.dylib"

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
    loadedmodelshader.cpp

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
    loadedmodelshader.h

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
    rockFormationLarge.mtl

RESOURCES += \
    resources.qrc
