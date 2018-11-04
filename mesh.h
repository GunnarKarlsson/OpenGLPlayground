#ifndef MESH_H
#define MESH_H

#include <vector>
#include "common.h"
#include "shader.h"


class Mesh
{
public:
    Mesh(std::vector<float> vertices, std::vector<unsigned int> indices, glm::vec3 color);
    ~Mesh();
    void setPosition(float x, float y, float z);
    void setScale(float x, float y, float z);
    void rotateY(float degrees);
    void render(glm::mat4 &view, glm::mat4 &projection, glm::vec3 lightPos, glm::vec3 lightColor, Shader *shader);

private:
    void init();
    float xPos;
    float yPos;
    float zPos;

    const float SCALE_MODIFIER = 0.1f;
    float xScale;
    float yScale;
    float zScale;

    glm::vec3 size;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    unsigned int VAO, VBO, EBO;
    glm::vec3 objectColor;
};

#endif // MESH_H
