#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include "assetmanager.h"
#include "shader.h"

class TextRenderer
{
public:
    TextRenderer();
    ~TextRenderer();
    void renderText(AssetManager *am, const Shader *s, const std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
private:
    TextRenderer(const TextRenderer&);
    TextRenderer& operator=(const TextRenderer&);
private:
    GLuint VAO, VBO;
};

#endif // TEXTRENDERER_H
