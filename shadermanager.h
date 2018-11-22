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
    Shader* getShader(QString name);
private:
    std::map<QString, Shader*> map;
};

#endif // SHADERMANAGER_H
