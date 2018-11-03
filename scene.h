#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QEvent>

class Scene
{
public:
    Scene();
    virtual ~Scene();
    virtual void init();
    virtual void update();
    virtual void render();
    virtual void handleEvent(QEvent* event);
};

#endif // SCENE_H
