#ifndef SKYBOX_H
#define SKYBOX_H

#include "common.h"
#include "skyboxshader.h"

class Skybox
{
public:
    Skybox();
    ~Skybox();
    void setTextureId(unsigned int &id);
    void update(const glm::mat4 &view, const glm::mat4 &projection) const;
private:
    unsigned int skyboxTextureId;
    SkyboxShader * skyboxShader;
    unsigned int skyboxVAO;
    unsigned int skyboxVBO;
    unsigned int cubemapTexture;
    const float skyboxVertices[6 * 6 * 3] = {
        // positions
        -500.0f,  500.0f, -500.0f,
        -500.0f, -500.0f, -500.0f,
        500.0f, -500.0f, -500.0f,
        500.0f, -500.0f, -500.0f,
        500.0f,  500.0f, -500.0f,
        -500.0f,  500.0f, -500.0f,

        -500.0f, -500.0f,  500.0f,
        -500.0f, -500.0f, -500.0f,
        -500.0f,  500.0f, -500.0f,
        -500.0f,  500.0f, -500.0f,
        -500.0f,  500.0f,  500.0f,
        -500.0f, -500.0f,  500.0f,

        500.0f, -500.0f, -500.0f,
        500.0f, -500.0f,  500.0f,
        500.0f,  500.0f,  500.0f,
        500.0f,  500.0f,  500.0f,
        500.0f,  500.0f, -500.0f,
        500.0f, -500.0f, -500.0f,

        -500.0f, -500.0f,  500.0f,
        -500.0f,  500.0f,  500.0f,
        500.0f,  500.0f,  500.0f,
        500.0f,  500.0f,  500.0f,
        500.0f, -500.0f,  500.0f,
        -500.0f, -500.0f,  500.0f,

        -500.0f,  500.0f, -500.0f,
        500.0f,  500.0f, -500.0f,
        500.0f,  500.0f,  500.0f,
        500.0f,  500.0f,  500.0f,
        -500.0f,  500.0f,  500.0f,
        -500.0f,  500.0f, -500.0f,

        -500.0f, -500.0f, -500.0f,
        -500.0f, -500.0f,  500.0f,
        500.0f, -500.0f, -500.0f,
        500.0f, -500.0f, -500.0f,
        -500.0f, -500.0f,  500.0f,
        500.0f, -500.0f,  500.0f
    };

};

#endif // SKYBOX_H
