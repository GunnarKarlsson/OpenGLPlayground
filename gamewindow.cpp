#include "gamewindow.h"
#include <QKeyEvent>
#include <QDebug>
#include "gamescene.h"

GameWindow::GameWindow() : QOpenGLWindow(QOpenGLWindow::NoPartialUpdate)
{
    installEventFilter(this);
}

GameWindow::~GameWindow()
{
    delete scene;
}

void GameWindow::initializeGL()
{
    initializeOpenGLFunctions();

    qDebug() << "version: " << QLatin1String(reinterpret_cast<const char*>(glGetString(GL_VERSION)));
    qDebug() << "GSLS version: " << QLatin1String(reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION)));

    scene = new GameScene();
    scene->init();
    isInit = true;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(20);
}

void GameWindow::resizeGL(int width, int height)
{
    //TODO
    qDebug() << "resize: " << width << " " << height;
}

void GameWindow::paintGL()
{
    updateScene();
    renderScene();
}

void GameWindow::updateScene()
{
    if (isInit) {
        scene->update();
    }
}

void GameWindow::renderScene()
{
    if (isInit) {
        scene->render();
    }
}

bool GameWindow::eventFilter(QObject* object, QEvent* event)
{
    if (isInit) {
         scene->handleEvent(event);
    }
}
