#include "assetmanager.h"
#include "common.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <QPixmap>
#include <QRgb>

AssetManager::AssetManager(){}

AssetManager::~AssetManager() {}

void AssetManager::loadAssets()
{

    //start font load
    FT_Library ft;
    if (FT_Init_FreeType(&ft)) {
        qDebug() << "ERROR::FREETYPE: Could not init FreeType Library" << endl;
    } else {
        qDebug() << "FREETYPE: init FreeType Library" << endl;
    }

    FT_Face face;
    const char* fontPath = "/Users/gunnarkarlsson/git/OpenGLPlayground/aero.ttf";
    if (FT_New_Face(ft, fontPath, 0, &face)) {
        qDebug() << "ERROR::FREETYPE: Failed to load font" << endl;
    } else {
           qDebug() << "FREETYPE: loaded font" << endl;
    }

    // Set size to load glyphs as
    FT_Set_Pixel_Sizes(face, 0, 48);

    // Disable byte-alignment restriction
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // Load first 128 characters of ASCII set
        for (GLubyte c = 0; c < 128; c++)
        {
            // Load character glyph
            if (FT_Load_Char(face, c, FT_LOAD_RENDER))
            {
                qDebug() << "ERROR::FREETYTPE: Failed to load Glyph" << endl;
                continue;
            }
            // Generate texture
            GLuint texture;
            glGenTextures(1, &texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RED,
                face->glyph->bitmap.width,
                face->glyph->bitmap.rows,
                0,
                GL_RED,
                GL_UNSIGNED_BYTE,
                face->glyph->bitmap.buffer
            );
            // Set texture options
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            // Now store character for later use
            Character character = {
                texture,
                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                static_cast<GLuint>(face->glyph->advance.x)
            };
            characters.insert(std::pair<GLchar, Character>(c, character));
        }
        glBindTexture(GL_TEXTURE_2D, 0);
        // Destroy FreeType once we're finished
        FT_Done_Face(face);
        FT_Done_FreeType(ft);


        //end font load

    const char * filePathCube = "/Users/gunnarkarlsson/git/OpenGLPlayground/cube.png";
    loadTexture(filePathCube, cubeTextureId);

    std::string basePath = "/Users/gunnarkarlsson//git/OpenGLPlayground/";
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

    loadLevelPalette();
    loadLevel();
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

void AssetManager::loadLevelPalette() {
    QPixmap pixmap(":/Images/palette.png");
    QImage tmp = pixmap.toImage();
    qDebug() << "palette Width:  " << tmp.width();
    qDebug() << "palette Heigth: " << tmp.height();
    for(int y = 0; y < tmp.height(); y++) {
        for(int x= 0; x < tmp.width(); x++) {
            QRgb rgb = tmp.pixelColor(x, y).rgb();
            QString valueInHex= QString("%1").arg(rgb , 0, 16);
            qDebug() << valueInHex;
            paletteMap.insert ( std::pair<QString,int>(valueInHex,x) );
        }
    }
}

void AssetManager::loadLevel() {
    QPixmap pixmap(":/Images/map001.png");
    QImage tmp = pixmap.toImage();
    qDebug() << "map Width:  " << tmp.width();
    qDebug() << "map Heigth: " << tmp.height();
    levelWidth = tmp.width();
    levelDepth = tmp.height();
    for(int y = 0; y < tmp.height(); y++) {
        for(int x= 0; x < tmp.width(); x++) {
            QRgb rgb = tmp.pixelColor(x, y).rgb();
            QString valueInHex= QString("%1").arg(rgb , 0, 16);
            //qDebug() << valueInHex;
            int value = paletteMap.at(valueInHex);
            intPair xy = intPair(x, y);
            levelMap.insert(std::pair<intPair,int>(xy,value));
        }
    }
}


