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
    Shader *basicShader = new Shader(":/Shaders/basic.vert", ":/Shaders/basic.frag");
    map.insert(std::make_pair("basicShader", basicShader));

    Shader *lightboxShader = new Shader(":/Shaders/lightbox.vert", ":/Shaders/lightbox.frag");
    map.insert(std::make_pair("lightboxShader", lightboxShader));

    Shader *loadedModelShader = new Shader(":/Shaders/loadedmodel.vert",":/Shaders/loadedmodel.frag");
    map.insert(std::make_pair("loadedModelShader", loadedModelShader));

    Shader *textShader = new Shader(":/Shaders/text.vert", ":/Shaders/text.frag");
    map.insert(std::make_pair("textShader", textShader));

    Shader *quadShader = new Shader(":/Shaders/quad.vert",":/Shaders/quad.frag");
    map.insert(std::make_pair("quadShader", quadShader));
}

const Shader* ShaderManager::getShader(const QString name) const
{
    std::map<QString,Shader*>::const_iterator it = map.find(name);
    return it->second;
}
