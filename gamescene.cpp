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

    textShader = new TextShader();
    textShader->compile();

    entity = new Cube();
    entity->initialize(-1.0f, 1.0f, 0.0f);
    entity->setVisible(true);
    entity->setTextureId(assetManager->cubeTextureId);

    lightBox = new Cube();
    lightBox->initialize(lightPos.x, lightPos.y, lightPos.z);
    lightBox->setVisible(true);
    lightBox->setSize(glm::vec3(0.2f, 0.2f, 0.2f));

    modelLoader = new ModelLoader();
    spaceShip = modelLoader->Load("/Users/gunnarkarlsson/git/OpenGLPlayground/spaceCraft4.obj");
    spaceShip->setPosition(4.0, 0.0, -1.0);
    spaceShip->setRotation(0.0f, 180.0f, 0.0f);

    largeRock = modelLoader->Load("/Users/gunnarkarlsson/git/OpenGLPlayground/rockFormationLarge.obj");
    largeRock->setPosition(3.0f, -2.0f, -4.0f);
    largeRock->setScale(5.0f, 5.0f, 5.0f);

    skybox = new Skybox();
    skybox->setTextureId(assetManager->skyboxTextureId);

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

    spaceShip->render(view, projection, lightPos, lightColor, loadedModelShader);

    largeRock->render(view, projection, lightPos, lightColor, loadedModelShader);

    lightBox->render(view, projection, lightPos, lightColor, lightboxShader);

    glm::mat4 skyboxView = glm::mat4(glm::mat3(camera->GetViewMatrix())); // remove translation from the view matrix
    skybox->update(skyboxView, projection);//TODO: rename to skybox->render
}

void GameScene::handleEvent(QEvent* event)
{
    switch(event->type()) {

    case QEvent :: MouseButtonRelease: {
        lastMouseX = 0;
        lastMouseY = 0;
        break;
    }

    case QEvent::MouseButtonPress: {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if(mouseEvent->buttons() == Qt::LeftButton) {
            lastMouseX = mouseEvent->x();
            lastMouseY = mouseEvent->y();
        }
        break;
    }

    case QEvent :: MouseMove: {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if(mouseEvent->buttons() == Qt::LeftButton) {

            float dx = mouseEvent->x() - lastMouseX;
            float dy = mouseEvent->y() - lastMouseY;

            camera->ProcessMouseMovement(dx, -dy);

            lastMouseX = mouseEvent->x();
            lastMouseY = mouseEvent->y();
        }
        break;
    }

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
