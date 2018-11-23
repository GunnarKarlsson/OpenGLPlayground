#include "particle.h"

Particle::Particle(float x, float y, float z, float inDx, float inDy, float inDz, unsigned int &texId)
{
    textureId = texId;

    isInit = false;
    xPos = x;
    yPos = y;
    zPos = z;
    dx = inDx;
    dy = inDy;
    dz = inDz;
    visible = true;

    size = 3.0f;

    srand(time(0));
    int r = (rand() % 100) + 1;
    rotationZ = r; //"random number"

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    isInit = true;
}

Particle::Particle(){}


Particle::~Particle()
{

}

void Particle::setTextureId(unsigned int &id)
{
    textureId = id;
}

void Particle::setVelocity(int vel)
{
    velocity = vel;
}

void Particle::setSize(float s)
{
    size = s;
}

void Particle::update()
{
    if (isInit) {
        xPos += dx;
        yPos += dy;
        zPos += dz;
    }
}

void Particle::render(glm::mat4 &view, glm::mat4 &projection, Shader *shader)
{
    if (isInit && visible) {
        glBindTexture(GL_TEXTURE_2D, textureId);
        glm::mat4 model = glm::mat4(1.0);
        model = glm::translate(model, glm::vec3(xPos, yPos, zPos));
        model = glm::scale(model, glm::vec3((float)size, (float)size, 1.0));

        shader->use();
        shader->setMat4("model", model);
        shader->setMat4("view", view);
        shader->setMat4("projection", projection);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
}

void Particle::hide()
{
    visible = false;
}

void Particle::show()
{
    visible = true;
}

bool Particle::isVisible()
{
    return visible;
}

void Particle::setXPos(float x)
{
    xPos = x;
}

void Particle::setYPos(float y)
{
    yPos = y;
}

void Particle::setZPos(float z)
{
    zPos = z;
}

void Particle::setDx(float inDx)
{
    dx = inDx;
}

void Particle::setDy(float inDy)
{
    dy = inDy;
}

void Particle::setDz(float inDz)
{
    dz = inDz;
}

float Particle::getXPos()
{
    return xPos;
}

float Particle::getYPos()
{
    return yPos;
}

float Particle::getZPos()
{
    return zPos;
}

float Particle::getDx()
{
    return dx;
}

float Particle::getDy()
{
    return dy;
}

float Particle::getDz()
{
    return dz;
}
