#ifndef MODELLOADER_H
#define MODELLOADER_H

#include "assimp/scene.h"
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>
#include <QString>
#include <vector>
#include "loadedmodel.h"

class aiMesh;

class ModelLoader
{
public:
    ModelLoader();
    ~ModelLoader();
    LoadedModel* Load(const QString resDir, const QString fileName);
private:
    std::vector<aiMesh*> meshes;
};

#endif // MODELLOADER_H
