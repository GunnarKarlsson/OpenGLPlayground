#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <QFile>
#include <QTemporaryDir>
#include "common.h"

class AssetManager
{
public:
    AssetManager();
    ~AssetManager();
    void loadAssets();
    const QString getWavefrontResPath(QTemporaryDir &tempDir, QString resFolder, QString fileName);

    unsigned int cubeTextureId;
    unsigned int skyboxTextureId;
    unsigned int quadTextureId;
    unsigned int smoke01TextureId;
    unsigned int smoke02TextureId;
    unsigned int smoke03TextureId;

    std::map<GLchar, Character> characters;
private:
    AssetManager(const AssetManager&);
    AssetManager& operator=(const AssetManager&);
    const QString getResPath(QTemporaryDir &tempDir, QString resFolder, QString fileName);
    void loadTexture(const char *path, unsigned int &textureId);
    unsigned int loadSkyboxTextures(const std::vector<std::string> faces);
};

#endif // ASSETMANAGER_H
