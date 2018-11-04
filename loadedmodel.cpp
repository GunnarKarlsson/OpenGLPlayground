#include "loadedmodel.h"

LoadedModel::LoadedModel()
{

}

LoadedModel::~LoadedModel()
{
    //TODO: delete data
}

void LoadedModel::addMesh(Mesh *mesh)
{
    meshes.push_back(mesh);
}

void LoadedModel::setPosition(float x, float y, float z)
{
    for (int i = 0; i < meshes.size(); i++) {
        meshes[i]->setPosition(x, y, z);
    }
}

void LoadedModel::setScale(float x, float y, float z) {
    for (int i = 0; i < meshes.size(); i++) {
        meshes[i]->setScale(x, y, z);
    }
}

void LoadedModel::render(glm::mat4 &view, glm::mat4 &projection, glm::vec3 lightPos, glm::vec3 lightColor, Shader *shader)
{
    for (int i = 0; i < meshes.size(); i++) {
        Mesh *mesh = meshes[i];
        mesh->render(view, projection, lightPos, lightColor, shader);
    }
}

