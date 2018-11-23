#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QEvent>
#include "scene.h"
#include "assetmanager.h"
#include "camera.h"
#include "cube.h"
#include "modelloader.h"
#include "skybox.h"
#include "textrenderer.h"
#include "quad.h"
#include "shader.h"
#include "shadermanager.h"
#include "smoke.h"

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
    GameScene(const GameScene&);
    GameScene& operator=(const GameScene&);
    AssetManager *assetManager;
    ShaderManager *shaderManager;
    ModelLoader *modelLoader;

    Camera *camera;

    glm::vec3 lightPos;
    glm::vec3 lightColor;

    Cube *texturedCube;
    Cube *lightBox;
    LoadedModel *spaceShip;
    LoadedModel *largeRock;
    LoadedModel *crater;

    Skybox *skybox;

    TextRenderer *textRenderer;

    Quad *quad;

    Smoke *smoke;

    int lastMouseX;
    int lastMouseY;
};

#endif // GAMESCENE_H
