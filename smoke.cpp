#include "smoke.h"

Smoke::Smoke(int n) : particlePoolCount(n)
{
    shader = new Shader(":/Shaders/Shaders/particle.vert",":/Shaders/Shaders/particle.frag");

    for (int i = 0; i < particlePoolCount; i++) {
        particles.push_back(new Particle());
    }
}

Smoke::~Smoke()
{
    particles.clear();
}

void Smoke::update()
{
    for (int i = 0; i < particlePoolCount; i++) {
        particles[i]->update();
    }
}

void Smoke::clear()
{
    particles.clear();
}

void Smoke::render(glm::mat4 &view, glm::mat4 &projection)
{
    for (int i = 0; i < particles.size(); i++){
           particles[i]->render(view, projection, shader);
    }
}
