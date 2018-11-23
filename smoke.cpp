#include "smoke.h"

#include <QDebug>

Smoke::Smoke(AssetManager *am)
{
    assetManager = am;
    textureId = assetManager->smoke01TextureId;
    isInit = false;
    waitCounterStart = 20;
    particlePoolCount = 10;
    waitCounter = 10;
    shader = new Shader(":/Shaders/Shaders/particle.vert",":/Shaders/Shaders/particle.frag");

    //for (int i = 0; i < particlePoolCount; i++) {
    //    particles.push_back(new Particle(0.0f, 0.0f, -5.0f+0.1*i, 0.0f, 0.05f, 0.0f));
    //}
    srand(time(0));  // Initialize random number generator.
    isInit = true;
}

Smoke::~Smoke()
{
    particles.clear();
}

void Smoke::update()
{
    int r = (rand() % 10) + 1;
    if (isInit) {
        for (int i = particles.size()-1; i >= 0; i--) {
            particles[i]->update();
            if (particles[i]->getYPos() > 10) {
                particles.erase(particles.begin()+i);
            }
        }
        --waitCounter;
        if (waitCounter <= 0) {
            waitCounter = waitCounterStart;
            particles.push_back(new Particle(0.0f, 0.0f, -5.0f+0.1f*r, 0.0f, 0.02f, 0.0f));
        }
    }
    qDebug() << "particles.size();" << particles.size();

}

void Smoke::clear()
{
    particles.clear();
}

void Smoke::render(glm::mat4 &view, glm::mat4 &projection)
{
    if (isInit) {
        glDisable(GL_DEPTH_TEST);
       glEnable (GL_BLEND);
        //glEnable(GL_BLEND_COLOR);
        glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);
        //glBlendFunc(GL_BLEND_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, textureId);
        for (int i = 0; i < particles.size(); i++){
            particles[i]->render(view, projection, shader);
        }
        glDisable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);

    }
}
