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

void LoadedModel::setPosition(const float x, const float y, const float z)
{
    for (int i = 0; i < meshes.size(); i++) {
        meshes[i]->setPosition(x, y, z);
    }
}

void LoadedModel::setRotation(float xDegrees, float yDegrees, float zDegrees)
{
    for (int i = 0; i < meshes.size(); i++) {
        meshes[i]->setRotation(xDegrees, yDegrees, zDegrees);
    }
}

void LoadedModel::setScale(const float x, const float y, const float z) {
    for (int i = 0; i < meshes.size(); i++) {
        meshes[i]->setScale(x, y, z);
    }
}

void LoadedModel::render(const glm::mat4 &view, const glm::mat4 &projection, const glm::vec3 &lightPos, const glm::vec3 &lightColor, const Shader *shader)
{
    for (int i = 0; i < meshes.size(); i++) {
        Mesh *mesh = meshes[i];
        mesh->render(view, projection, lightPos, lightColor, shader);
    }
}

