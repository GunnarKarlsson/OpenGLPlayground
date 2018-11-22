#include "assetmanager.h"
#include "common.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <ft2build.h>
#include FT_FREETYPE_H

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

    QTemporaryDir tempDir;
    QString str = getResPath(tempDir, "/Fonts","Aero.ttf");
    qDebug() << "fontpath: " << str;
    const char *fontPath = str.toStdString().c_str();

    FT_Face face;
    //const char *fontPath = "/Users/gunnarkarlsson/git/OpenGLPlayground/aero.ttf";
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

    QString cubePathStr = getResPath(tempDir, "/Textures", "cube.png");
    const char *filePathCube = cubePathStr.toStdString().c_str();
    loadTexture(filePathCube, cubeTextureId);

    QString quadPathStr = getResPath(tempDir, "/Textures", "panel.png");
    const char *quadTexturePath = quadPathStr.toStdString().c_str();
    loadTexture(quadTexturePath, quadTextureId);

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
}

void AssetManager::loadTexture(const char *filePath, unsigned int &textureId)
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

unsigned int AssetManager::loadSkyboxTextures(const std::vector<std::string> faces) {
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

const QString AssetManager::getResPath(QTemporaryDir &tempDir, QString resFolder, QString fileName)
{
    const QString tempFile = tempDir.path() + "/" + fileName;
    if (tempDir.isValid()) {
        const QString tempFile = tempDir.path() + "/" + fileName;
        if (QFile::copy(":" + resFolder + "/" + fileName, tempFile)) {
            qDebug() << "copy success";
        } else {
             qDebug() << "copy fail";
             ABORT_APP
        }
    } else {
        qDebug() << "invalid tempDir";
        ABORT_APP
    }
    return tempFile;
}

