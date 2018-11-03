#include "modelloader.h"
#include <QDebug>

ModelLoader::ModelLoader() {}
ModelLoader::~ModelLoader(){}

LoadedModel* ModelLoader::Load(QString pathToFile)
{

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
        return nullptr;
    } else {
        qDebug() << "Scene loaded successfully" << endl;
    }

    if (scene->HasMeshes()) {
        qDebug() << "scene has " << scene->mNumMeshes << "meshes " << endl;
        for (int i = 0; i < scene->mNumMeshes; i++) {
                aiMesh *mesh = scene->mMeshes[i];
                meshes.push_back(mesh);
        }
    } else {
        qDebug() << "No meshes found" << endl;;
        return nullptr;
    }

    LoadedModel *loadedModel = new LoadedModel();

    for (int i = 0; i < meshes.size(); i++) {
        aiMesh *aiMesh = meshes[i];

        std::vector<float> vertices;
        std::vector<unsigned int> indices;

        for(int j = 0; j < aiMesh->mNumVertices; j++) {
            // positions
            vertices.push_back(aiMesh->mVertices[j].x);
            vertices.push_back(aiMesh->mVertices[j].y);
            vertices.push_back(aiMesh->mVertices[j].z);

            // normals
            vertices.push_back(aiMesh->mNormals[j].x);
            vertices.push_back(aiMesh->mNormals[j].y);
            vertices.push_back(aiMesh->mNormals[j].z);
        }

        for(int k = 0; k < aiMesh->mNumFaces; k++) {
            aiFace face = aiMesh->mFaces[k];
            for(unsigned int m = 0; m < face.mNumIndices; m++) {
                indices.push_back(face.mIndices[m]);
            }
        }

        qDebug() << "vertices.size()" << vertices.size();
        qDebug() << "indices.size()" << indices.size();

        Mesh *mesh = new Mesh(vertices, indices);
        loadedModel->addMesh(mesh);
    }

    return loadedModel;
}
