#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <QFile>

class AssetManager
{
public:
    AssetManager();
    ~AssetManager();
    void loadAssets();

    unsigned int cubeTextureId;
    unsigned int skyboxTextureId;

private:
    void loadTexture(const char* path, unsigned int &textureId);
    unsigned int loadSkyboxTextures(std::vector<std::string> faces);
};

#endif // ASSETMANAGER_H
