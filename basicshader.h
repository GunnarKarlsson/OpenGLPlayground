#ifndef BASICSHADER_H
#define BASICSHADER_H

#include "shader.h"

class BasicShader : public Shader
{

public:
    BasicShader();
    ~BasicShader();
    const char* getShaderName();
    void compile();
};

#endif // BASICSHADER_H
