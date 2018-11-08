#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <QFile>
#include "common.h"
#include <map>

typedef std::pair<int,int> intPair;

class AssetManager
{
public:
    AssetManager();
    ~AssetManager();
    void loadAssets();
    void loadLevelPalette();
    void loadLevel();

    unsigned int cubeTextureId;
    unsigned int skyboxTextureId;

    std::map<GLchar, Character> characters;
    std::map<intPair, int> levelMap;
    int levelWidth = 0;
    int levelDepth = 0;
private:
    void loadTexture(const char* path, unsigned int &textureId);
    unsigned int loadSkyboxTextures(std::vector<std::string> faces);
    std::map<QString, int> paletteMap;
};

#endif // ASSETMANAGER_H
