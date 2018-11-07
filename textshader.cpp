#include "textshader.h"

TextShader::TextShader() : Shader() {}

TextShader::~TextShader() {}

const char* TextShader::getShaderName() {
    return "Skybox Shader";
}

void TextShader::compile() {
    Shader::compile(":/Shaders/text.vert", ":/Shaders/text.frag");
}
