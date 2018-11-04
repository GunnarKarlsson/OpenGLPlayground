#include "assetmanager.h"
#include "common.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

AssetManager::AssetManager(){}

AssetManager::~AssetManager() {}

void AssetManager::loadAssets()
{
    const char * filePathCube = "/Users/gunnarkarlsson/git/PlaygroundModule/cube.png";
    loadTexture(filePathCube, cubeTextureId);

    std::string basePath = "/Users/gunnarkarlsson/QtProjects/tuts/Breakout/";
    std::string SKY_LEFT = basePath + "SKY_LEFT.png";
    std::string SKY_RIGHT = basePath + "SKY_RIGHT.png";
    std::string SKY_UP = basePath + "SKY_UP.png";
    std::string SKY_DOWN = basePath + "SKY_DOWN.png";
    std::string SKY_FRONT = basePath + "SKY_FRONT.png";
    std::string SKY_BACK = basePath + "SKY_BACK.png";

    std::vector<std::string> faces {
                SKY_LEFT,
                SKY_RIGHT,
                SKY_UP,
                SKY_DOWN,
                SKY_FRONT,
                SKY_BACK
            };
    skyboxTextureId = loadSkyboxTextures(faces);
}

void AssetManager::loadTexture(const char* filePath, unsigned int &textureId)
{
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filePath, &width, &height, &nrChannels, STBI_rgb_alpha);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        qDebug() << "Texture loaded successfully" << endl;
    }
    else
    {
        qDebug() << "Failed to load texture" << endl;
    }
    stbi_image_free(data);
}

unsigned int AssetManager::loadSkyboxTextures(std::vector<std::string> faces) {
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    int width, height, nrChannels;
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
            qDebug() << "Skybox texture loaded successfully" << endl;
        }
        else
        {
            qDebug() << "Skybox texture failed to load" << endl;
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}


