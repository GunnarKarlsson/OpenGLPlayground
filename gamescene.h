#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QEvent>
#include "scene.h"
#include "assetmanager.h"
#include "basicshader.h"
#include "lightboxshader.h"
#include "loadedmodelshader.h"
#include "camera.h"
#include "cube.h"
#include "modelloader.h"
#include "skybox.h"
#include "skyboxshader.h"
#include "textshader.h"
#include "textrenderer.h"
#include "quadshader.h"
#include "quad.h"

class GameScene : public Scene
{
public:
    GameScene();
    ~GameScene();
    void init();
    void update();
    void render();
    void handleEvent(QEvent* event);
private:
    AssetManager *assetManager;
    ModelLoader *modelLoader;

    BasicShader *basicShader;
    LightboxShader *lightboxShader;
    LoadedModelShader *loadedModelShader;
    TextShader *textShader;
    QuadShader *quadShader;

    Camera *camera;

    glm::vec3 lightPos;
    glm::vec3 lightColor;

    Cube *texturedCube;
    Cube *lightBox;
    LoadedModel *spaceShip;
    LoadedModel *largeRock;

    Skybox *skybox;

    TextRenderer *textRenderer;

    Quad *quad;

    int lastMouseX;
    int lastMouseY;
};

#endif // GAMESCENE_H
