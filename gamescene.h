#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QEvent>
#include "scene.h"
#include "assetmanager.h"
#include "basicshader.h"
#include "camera.h"
#include "entity.h"


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
    BasicShader *basicShader;

    Camera *camera;

    glm::vec3 lightPos;
    glm::vec3 lightColor;

    Entity *entity;
};

#endif // GAMESCENE_H
