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
    void setPosition(float x, float y, float z);
    void setScale(float x, float y, float z);
    void setRotation(float xDegrees, float yDegrees, float zDegrees);
    void render(glm::mat4 &view, glm::mat4 &projection, glm::vec3 lightPos, glm::vec3 lightColor, Shader *shader);
private:
    std::vector<Mesh*> meshes;
};

#endif // LOADEDMODEL_H
