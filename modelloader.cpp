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

        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;

        for(int j = 0; j < aiMesh->mNumVertices; j++) {
            Vertex vertex;
            glm::vec3 vector; // we declare a placeholder vector since assimp uses its own vector class that doesn't directly convert to glm's vec3 class so we transfer the data to this placeholder glm::vec3 first.
            // positions
            vector.x = aiMesh->mVertices[j].x;
            vector.y = aiMesh->mVertices[j].y;
            vector.z = aiMesh->mVertices[j].z;
            vertex.Position = vector;
            // normals
            vector.x = aiMesh->mNormals[j].x;
            vector.y = aiMesh->mNormals[j].y;
            vector.z = aiMesh->mNormals[j].z;
            vertex.Normal = vector;
            vertices.push_back(vertex);
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
