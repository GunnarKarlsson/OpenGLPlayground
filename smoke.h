#ifndef SMOKE_H
#define SMOKE_H

#include "particle.h"
#include "common.h"
#include "shader.h"

class Smoke
{
public:
    explicit Smoke(int poolCount);
    ~Smoke();
    void update();
    void render(glm::mat4 &view, glm::mat4 &projection);
    void clear();
private:
    Shader *shader;
    const int particlePoolCount;
    std::vector<Particle*> particles;
};

#endif // SMOKE_H
