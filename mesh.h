#ifndef MESH_H
#define MESH_H

#include <vector>
#include "common.h"
#include "shader.h"


class Mesh
{
public:
    explicit Mesh(std::vector<float> &vertices, std::vector<unsigned int> &indices, const glm::vec3 &color);
    ~Mesh();
    void setPosition(const float x, const float y, const float z);
    void setScale(const float x, const float y, const float z);
    void setRotation(const float xDegrees, const float yDegrees, const float zDegrees);
    void render(const glm::mat4 &view, const glm::mat4 &projection, const glm::vec3 lightPos, const glm::vec3 lightColor, const Shader *shader);

private:
    void init();
    float xPos;
    float yPos;
    float zPos;

    const float SCALE_MODIFIER = 0.1f;
    float xScale;
    float yScale;
    float zScale;

    float xRotationRadians;
    float yRotationRadians;
    float zRotationRadians;

    glm::vec3 size;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    unsigned int VAO, VBO, EBO;
    glm::vec3 objectColor;
};

#endif // MESH_H
