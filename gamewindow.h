#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include "scene.h"
#include <QTimer>

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

    QTimer *timer;
    Scene *scene;
    bool isInit = false;
};

#endif // GAMEWINDOW_H
