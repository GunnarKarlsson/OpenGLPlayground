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

        qDebug() << "scene has " << scene->mNumMeshes << "meshes " << endl;

        for (int i = 0; i < scene->mNumMeshes; i++) {
                aiMesh *mesh = scene->mMeshes[i];
                meshes.push_back(mesh);
        }

        qDebug() << meshes.size() << " meshes added to 'meshes' vector" << endl;

        return true;
    } else {
        qDebug() << "No meshes found" << endl;;
        return false;
    }
}
