#ifndef LOADEDMODELSHADER_H
#define LOADEDMODELSHADER_H

#include "shader.h"

class LoadedModelShader : public Shader
{
public:
    LoadedModelShader();
    ~LoadedModelShader();
    const char* getShaderName();
    void compile();
};

#endif // LOADEDMODELSHADER_H
