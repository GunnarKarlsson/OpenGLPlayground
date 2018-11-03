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
    delete spaceShip;
    delete lightBox;
    delete modelLoader;
    delete lightboxShader;
    delete loadedModelShader;
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

    loadedModelShader = new LoadedModelShader();
    loadedModelShader->compile();

    entity = new Cube();
    entity->initialize(0.0f, 0.0f, 0.0f);
    entity->setVisible(true);
    entity->setTextureId(assetManager->cubeTextureId);

    lightBox = new Cube();
    lightBox->initialize(lightPos.x, lightPos.y, lightPos.z);
    lightBox->setVisible(true);
    lightBox->setSize(glm::vec3(0.2f, 0.2f, 0.2f));

    modelLoader = new ModelLoader();
    spaceShip = modelLoader->Load("/Users/gunnarkarlsson/git/PlaygroundModule/spaceCraft4.obj");
    spaceShip->setPosition(200.0, 200.0, -1.0);

    largeRock = modelLoader->Load("/Users/gunnarkarlsson/git/PlaygroundModule/rockFormationLarge.obj");
    largeRock->setPosition(400.0f, 200.0f, -1.0f);

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
    //glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, (float)NEAR_LIMIT, (float)FAR_LIMIT);

    glm::mat4 projection = glm::ortho(0.0f, (float)SCREEN_WIDTH, 0.0f, (float)SCREEN_HEIGHT, 0.01f, 1000.0f);
    entity->render(view, projection, lightPos, lightColor, basicShader);

    spaceShip->render(view, projection, lightPos, lightColor, loadedModelShader);

    largeRock->render(view, projection, lightPos, lightColor, loadedModelShader);

    lightBox->render(view, projection, lightPos, lightColor, lightboxShader);
}

void GameScene::handleEvent(QEvent* event)
{
    switch(event->type()) {
    case QEvent::KeyPress:{
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        switch (keyEvent->key()) {
        case Qt::Key_Right:
            camera->ProcessKeyboard(RIGHT, 0.1);
            break;
        case Qt::Key_Left:
            camera->ProcessKeyboard(LEFT, 0.1);
            break;
        case Qt::Key_Up:
            camera->ProcessKeyboard(FORWARD, 0.1);
            break;
        case Qt::Key_Down:
            camera->ProcessKeyboard(BACKWARD, 0.1);
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
