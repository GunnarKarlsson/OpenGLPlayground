#ifndef PARTICLE_H
#define PARTICLE_H

#include "common.h"
#include "shader.h"

class Particle
{
public:
    Particle(float x, float y, float z, float inDx, float inDy, float inDz);
    ~Particle();
    void setTextureId(unsigned int &id);
    void setVelocity(int velocity);
    void setSize(float size);
    void update();
    void render(glm::mat4 &view, glm::mat4 &projection, Shader *shader);
    void hide();
    void show();
    bool isVisible();
    void setXPos(float x);
    void setYPos(float y);
    void setZPos(float z);
    void setDx(float aDx);
    void setDy(float aDy);
    void setDz(float aDz);
    float getXPos();
    float getYPos();
    float getZPos();
    float getDx();
    float getDy();
    float getDz();

private:
    Particle();
    float xPos;
    float yPos;
    float zPos;
    float dx;
    float dy;
    float dz;
    int velocity;
    float size;
    float stepSize;

    glm::mat4 model;
    bool visible;
    unsigned int VBO, VAO, EBO;
    unsigned int textureId;
    float vertices[4*8] = {
        // positions         // texture coords
        // positions         // texture coords
        0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,  0.0f, 1.0f  // top left
    };
    unsigned int indices[6] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    bool isInit = false;

};

#endif // PARTICLE_H
