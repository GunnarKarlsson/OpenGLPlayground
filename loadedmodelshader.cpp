#include "loadedmodelshader.h"

LoadedModelShader::LoadedModelShader() : Shader() {}

LoadedModelShader::~LoadedModelShader() {}

const char* LoadedModelShader::getShaderName()
{
    return "LoadedModel Shader";
}

void LoadedModelShader::compile()
{
    Shader::compile(":/Shaders/loadedmodel.vert",":/Shaders/loadedmodel.frag");
}
