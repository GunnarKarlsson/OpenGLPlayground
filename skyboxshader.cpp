#include "skyboxshader.h"

SkyboxShader::SkyboxShader() : Shader() {}

SkyboxShader::~SkyboxShader() {}

const char* SkyboxShader::getShaderName() {
    return "Skybox Shader";
}

void SkyboxShader::compile() {
    Shader::compile(":/Shaders/skybox.vert", ":/Shaders/skybox.frag");
}
