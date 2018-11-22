#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QEvent>
#include "scene.h"
#include "assetmanager.h"
#include "loadedmodelshader.h"
#include "camera.h"
#include "cube.h"
#include "modelloader.h"
#include "skybox.h"
#include "textrenderer.h"
#include "quad.h"
#include "shader.h"

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

    Shader *basicShader;
    Shader *lightboxShader;
    Shader *loadedModelShader;
    Shader *textShader;
    Shader *quadShader;

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
