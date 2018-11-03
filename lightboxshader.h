#ifndef LIGHTBOXSHADER_H
#define LIGHTBOXSHADER_H


#include "shader.h"

class LightboxShader : public Shader
{

public:
    LightboxShader();
    ~LightboxShader();
    const char* getShaderName();
    void compile();
};

#endif // LIGHTBOXSHADER_H
