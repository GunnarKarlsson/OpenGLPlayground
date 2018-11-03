#include "gamescene.h"
#include <QKeyEvent>

GameScene::GameScene()
{

}

GameScene::~GameScene()
{
    delete assetManager;
    delete basicShader;
    delete camera;
    delete entity;
    delete modelLoader;
}

void GameScene::init()
{
    lightPos = glm::vec3(3.0, 3.0, 1.0);
    lightColor = glm::vec3(1.0, 1.0, 1.0);

    assetManager = new AssetManager();
    assetManager->loadAssets();

    camera = new Camera(glm::vec3(2.0f, 2.0f, 7.0f));

    basicShader = new BasicShader();
    basicShader->compile();

    lightboxShader = new LightboxShader();
    lightboxShader->compile();

    entity = new Entity();
    entity->initialize(0.0f, 0.0f, 0.0f);
    entity->setVisible(true);
    entity->setTextureId(assetManager->cubeTextureId);

    lightBox = new Entity();
    lightBox->initialize(lightPos.x, lightPos.y, lightPos.z);
    lightBox->setVisible(true);
    lightBox->setSize(glm::vec3(0.2f, 0.2f, 0.2f));

    modelLoader = new ModelLoader();
    modelLoader->Load("/Users/gunnarkarlsson/git/PlaygroundModule/spaceCraft4.obj");

    glEnable(GL_DEPTH_TEST);
}

void GameScene::update()
{

}

void GameScene::render()
{
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.4, 0.6, 0.8, 1.0);
    glm::mat4 view = camera->GetViewMatrix();
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, (float)NEAR_LIMIT, (float)FAR_LIMIT);

    entity->render(view, projection, lightPos, lightColor, basicShader);
    lightBox->render(view, projection, lightPos, lightColor, lightboxShader);
}

void GameScene::handleEvent(QEvent* event)
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
    }
}
