#ifndef TEXTSHADER_H
#define TEXTSHADER_H


#include "shader.h"

class TextShader : public Shader
{

public:
    TextShader();
    ~TextShader();
    const char* getShaderName();
    void compile();
};

#endif // TEXTSHADER_H
