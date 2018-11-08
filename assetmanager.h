#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <QFile>
#include "common.h"
#include <map>

class AssetManager
{
public:
    AssetManager();
    ~AssetManager();
    void loadAssets();
    void loadLevelPalette();

    unsigned int cubeTextureId;
    unsigned int skyboxTextureId;

    std::map<GLchar, Character> characters;
private:
    void loadTexture(const char* path, unsigned int &textureId);
    unsigned int loadSkyboxTextures(std::vector<std::string> faces);
    std::map<QString, int> paletteMap;
};

#endif // ASSETMANAGER_H
