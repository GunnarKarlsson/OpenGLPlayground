#ifndef SMOKE_H
#define SMOKE_H

#include "particle.h"
#include "common.h"
#include "shader.h"
#include "assetmanager.h"

class Smoke
{
public:
    Smoke(AssetManager *am);
    ~Smoke();
    void update();
    void render(glm::mat4 &view, glm::mat4 &projection);
    void clear();
private:
    Smoke();
    Shader *shader;
    int particlePoolCount;
    std::vector<Particle*> particles;
    int waitCounter;
    int waitCounterStart;
    bool isInit = false;
    AssetManager *assetManager;
    unsigned int textureId;
};

#endif // SMOKE_H
