#include "shadermanager.h"

ShaderManager::ShaderManager()
{

}

ShaderManager::~ShaderManager()
{
    map.clear();
}

void ShaderManager::compileShaders()
{
    Shader *basicShader = new Shader(":/Shaders/Shaders/basic.vert", ":/Shaders/Shaders/basic.frag");
    map.insert(std::make_pair("basicShader", basicShader));

    Shader *lightboxShader = new Shader(":/Shaders/Shaders/lightbox.vert", ":/Shaders/Shaders/lightbox.frag");
    map.insert(std::make_pair("lightboxShader", lightboxShader));

    Shader *loadedModelShader = new Shader(":/Shaders/Shaders/loadedmodel.vert",":/Shaders/Shaders/loadedmodel.frag");
    map.insert(std::make_pair("loadedModelShader", loadedModelShader));

    Shader *textShader = new Shader(":/Shaders/Shaders/text.vert", ":/Shaders/Shaders/text.frag");
    map.insert(std::make_pair("textShader", textShader));

    Shader *quadShader = new Shader(":/Shaders/Shaders/quad.vert",":/Shaders/Shaders/quad.frag");
    map.insert(std::make_pair("quadShader", quadShader));
}

const Shader* ShaderManager::getShader(const QString name) const
{
    std::map<QString,Shader*>::const_iterator it = map.find(name);
    return it->second;
}
