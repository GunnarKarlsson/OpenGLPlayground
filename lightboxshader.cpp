#include "lightboxshader.h"

LightboxShader::LightboxShader() : Shader() {}

LightboxShader::~LightboxShader() {}

const char* LightboxShader::getShaderName()
{
    return "Lightbox Shader";
}

void LightboxShader::compile()
{
    Shader::compile(":/Shaders/lightbox.vert", ":/Shaders/lightbox.frag");
}
