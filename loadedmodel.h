#ifndef LOADEDMODEL_H
#define LOADEDMODEL_H

#include <vector>
#include "mesh.h"
#include "shader.h"

class LoadedModel
{
public:
    LoadedModel();
    ~LoadedModel();
    void addMesh(Mesh *mesh);
    void setPosition(const float x, const float y, const float z);
    void setScale(const float x, const float y, const float z);
    void setRotation(const float xDegrees, const float yDegrees, const float zDegrees);
    void render(const glm::mat4 &view, const glm::mat4 &projection, const glm::vec3 lightPos, const glm::vec3 lightColor, const Shader *shader);
private:
    std::vector<Mesh*> meshes;
};

#endif // LOADEDMODEL_H
