#ifndef MESH_H
#define MESH_H

#include <vector>
#include "common.h"
#include "shader.h"

struct Vertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
};

class Mesh
{
public:
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
    ~Mesh();
    void render(glm::mat4 &view, glm::mat4 &projection, glm::vec3 lightPos, glm::vec3 lightColor, Shader *shader);

private:
    void init();
    float yPos;
    float xPos;
    float zPos;
    glm::vec3 size;
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    unsigned int VAO, VBO, EBO;
    glm::vec3 objectColor;
};

#endif // MESH_H
