#include "gamewindow.h"
#include <QKeyEvent>

GameWindow::GameWindow() : QOpenGLWindow(QOpenGLWindow::NoPartialUpdate)
{
    installEventFilter(this);
}

GameWindow::~GameWindow()
{
    delete assetManager;
    delete basicShader;
    delete timer;
    delete camera;
    delete entity;
}

void GameWindow::initializeGL()
{
    initializeOpenGLFunctions();

    qDebug() << "version: " << QLatin1String(reinterpret_cast<const char*>(glGetString(GL_VERSION)));
    qDebug() << "GSLS version: " << QLatin1String(reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION)));

    lightPos = glm::vec3(0.0, 0.0, 3.0);
    lightColor = glm::vec3(1.0, 1.0, 1.0);

    assetManager = new AssetManager();
    assetManager->loadAssets();

    camera = new Camera(glm::vec3(2.0f, 2.0f, 7.0f));

    basicShader = new BasicShader();
    basicShader->compile();

    entity = new Entity();
    entity->initialize(0.0f, 0.0f, 0.0f);
    entity->setVisible(true);
    entity->setTextureId(assetManager->cubeTextureId);

    scene = new Scene();

    glEnable(GL_DEPTH_TEST);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(20);
}

void GameWindow::resizeGL(int width, int height)
{
    //TODO
}

void GameWindow::paintGL()
{
    updateScene();
    renderScene();
}

void GameWindow::updateScene()
{
    //TODO: update data/model
    scene->update();
}

void GameWindow::renderScene()
{
    scene->render();
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.4, 0.6, 0.8, 1.0);
    glm::mat4 view = camera->GetViewMatrix();
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, (float)NEAR_LIMIT, (float)FAR_LIMIT);

    entity->render(view, projection, lightPos, lightColor, basicShader);
}

bool GameWindow::eventFilter( QObject* object, QEvent* event)
{
    switch(event->type()) {
    case QEvent::KeyPress:{
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        switch (keyEvent->key()) {
            case Qt::Key_Right:
            //TODO
            entity->moveRight();
            break;
        case Qt::Key_Left:
            //TODO
            entity->moveLeft();
            break;
        case Qt::Key_Up:
            entity->moveUp();
            break;
        case Qt::Key_Down:
            entity->moveDown();
            break;
        case Qt::Key_P:
           //TODO
            break;
        case Qt::Key_Escape:
            exit(0);
            break;
        default:
            break;
        }
    }
        return true;
    }
}
