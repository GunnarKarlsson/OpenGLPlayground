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

private:
    void loadTexture(const char* path, unsigned int &textureId);
};

#endif // ASSETMANAGER_H
