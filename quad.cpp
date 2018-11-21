#include "quad.h"
#include "common.h"

Quad::Quad(const float x, const float y, const float scale) : xPos(x), yPos(y), size(scale)
{
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
}

Quad::~Quad()
{

}

void Quad::setTextureId(unsigned int &id)
{
    textureId = id;
}


void Quad::render(Shader *shader)
{
    glm::mat4 model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(xPos, yPos, 0.0));
    model = glm::scale(model, glm::vec3((float)size, (float)size, -1.0));
    shader->use();
    shader->setMat4("model", model);

    glEnable (GL_BLEND);
    glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindTexture(GL_TEXTURE_2D, 0);

     glDisable(GL_BLEND);
}
