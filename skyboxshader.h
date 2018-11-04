#ifndef SKYBOXSHADER_H
#define SKYBOXSHADER_H


#include "shader.h"

class SkyboxShader : public Shader
{

public:
    SkyboxShader();
    ~SkyboxShader();
    const char* getShaderName();
    void compile();
};

#endif // SKYBOXSHADER_H
