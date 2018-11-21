#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QEvent>

class Scene
{
public:
    Scene();
    virtual ~Scene();
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void handleEvent(QEvent* event) = 0;
};

#endif // SCENE_H
