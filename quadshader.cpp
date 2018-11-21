#include "quadshader.h"

QuadShader::QuadShader() : Shader() {}

QuadShader::~QuadShader(){}

const char* QuadShader::getShaderName()
{
    return "QuadShader";
}

void QuadShader::compile()
{
    Shader::compile(":/Shaders/quad.vert",":/Shaders/quad.frag");
}
