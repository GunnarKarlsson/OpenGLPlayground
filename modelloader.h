#ifndef MODELLOADER_H
#define MODELLOADER_H

#include "assimp/scene.h"
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>
#include <QString>

class ModelLoader
{
public:
    ModelLoader();
    ~ModelLoader();
    bool Load(QString pathToFile);
};

#endif // MODELLOADER_H
