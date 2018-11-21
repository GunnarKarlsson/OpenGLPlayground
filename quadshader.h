#ifndef QUADSHADER_H
#define QUADSHADER_H

#include "shader.h"

class QuadShader : public Shader
{
public:
    QuadShader();
    ~QuadShader();
    const char* getShaderName();
    void compile();
};

#endif // QUADSHADER_H
