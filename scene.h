#ifndef SCENE_H
#define SCENE_H

#include <QEvent>

class Scene
{
public:
    Scene();
    virtual ~Scene();
    virtual void init();
    virtual void update();
    virtual void render();
    virtual void handleEvent(QObject* object, QEvent* event);
};

#endif // SCENE_H
