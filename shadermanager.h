#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include <map>
#include "shader.h"

class ShaderManager
{
public:
    ShaderManager();
    ~ShaderManager();
    void compileShaders();
    const Shader* getShader(const QString name) const;
private:
    ShaderManager(const ShaderManager&);
    ShaderManager& operator=(const ShaderManager&);
    std::map<QString, Shader*> map;
};

#endif // SHADERMANAGER_H
