#ifndef MODELLOADER_H
#define MODELLOADER_H

#include "assimp/scene.h"
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>
#include <QString>
#include <vector>

class aiMesh;

class ModelLoader
{
public:
    ModelLoader();
    ~ModelLoader();
    bool Load(QString pathToFile);
private:
    std::vector<aiMesh*> meshes;
};

#endif // MODELLOADER_H
