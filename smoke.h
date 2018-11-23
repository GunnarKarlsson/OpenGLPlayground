#ifndef SMOKE_H
#define SMOKE_H

#include "particle.h"

class Smoke
{
public:
    Smoke();
    ~Smoke();
    void update();
    void render();
private:
    std::vector<Particle*> particles;
};

#endif // SMOKE_H
