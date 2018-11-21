#ifndef QUAD_H
#define QUAD_H

#include "shader.h"

class Quad
{
public:
    explicit Quad(const float x, const float y, const float scale);
    ~Quad();
    void render(Shader *shader);
    void setTextureId(unsigned int &id);
private:
    unsigned int VBO, VAO, EBO;
    unsigned int textureId;
    float vertices[4*5] = {
        // positions          // texture coords
        0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // top left
    };

    unsigned int indices[6] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    float xPos;
    float yPos;
    float size;
};

#endif // QUAD_H
