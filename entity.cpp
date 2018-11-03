#include "entity.h"

Entity::Entity()
{
    xPos = 0;
    yPos = 0;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    //normals
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

Entity::~Entity()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Entity::setTextureId(unsigned int &id)
{
    textureId = id;
}

void Entity::setVelocity(int velocity)
{
    this->velocity = velocity;
}

void Entity::setSize(glm::vec3 size)
{
    this->size =  size;
}

bool Entity::setVisible(bool value)
{
    this->visible = value;
}

void Entity::render(glm::mat4 &view, glm::mat4 &projection, glm::vec3 lightPos, glm::vec3 lightColor, Shader *shader)
{
  if (visible) {
    shader->setInt("texture0", 0);
    glm::mat4 model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(xPos, yPos, zPos));
    model = glm::scale(model, size);
    shader->use();
    shader->setMat4("model", model);
    shader->setMat4("view", view);
    shader->setMat4("projection", projection);
    shader->setVec3("objectColor", objectColor);
    shader->setVec3("lightPos", lightPos);
    shader->setVec3("lightColor", lightColor);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindTexture(GL_TEXTURE_2D, 0);
   }
}

void Entity::initialize(float x, float y, float z)
{
    xPos = x;
    yPos = y;
    zPos = z;
    visible = true;
}


void Entity::moveLeft()
{
    xPos -= 1.0;
}

void Entity::moveRight()
{
    xPos += 1.0;
}

void Entity::moveUp()
{
    yPos += 1.0;
}

void Entity::moveDown()
{
    yPos -= 1.0;
}

bool Entity::isVisible()
{
    return visible;
}

