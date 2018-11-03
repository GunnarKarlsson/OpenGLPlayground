#include "modelloader.h"
#include <QDebug>

ModelLoader::ModelLoader() {}
ModelLoader::~ModelLoader(){}

bool ModelLoader::Load(QString pathToFile) {

    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(pathToFile.toStdString(),
                                             aiProcess_GenSmoothNormals |
                                             aiProcess_CalcTangentSpace |
                                             aiProcess_Triangulate |
                                             aiProcess_JoinIdenticalVertices |
                                             aiProcess_SortByPType
                                             );
    if (!scene) {
        qDebug() << "Error loading file: (assimp:) " << importer.GetErrorString() << endl;
        return false;
    }

    qDebug() << "Scene loaded successfully" << endl;

    if (scene->HasMaterials()) {
        qDebug() << "scene has materials" << endl;
    } else {
        qDebug() << "no materials found" << endl;
    }

    if (scene->HasMeshes()) {
        qDebug() << "scene has meshes" << endl;
        return true;
    } else {
        qDebug() << "No meshed found" << endl;;
        return false;
    }
}
