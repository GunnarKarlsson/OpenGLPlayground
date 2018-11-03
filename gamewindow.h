#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QTimer>
#include <vector>
#include "assetmanager.h"
#include "basicshader.h"
#include "camera.h"
#include "entity.h"

class GameWindow : public QOpenGLWindow, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GameWindow();
    ~GameWindow();
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    bool eventFilter(QObject *object, QEvent *event);

private:
    void updateScene();
    void renderScene();

    AssetManager *assetManager;
    BasicShader *basicShader;

    QTimer *timer;
    Camera *camera;

    glm::vec3 lightPos;
    glm::vec3 lightColor;

    Entity *entity;

};

#endif // GAMEWINDOW_H
