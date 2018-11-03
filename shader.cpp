#include "shader.h"
#include <QFile>

static void printShaderLog(GLuint shader)
{
    char buf[2048];
    memset(buf, 0, sizeof(buf));
    LOGE("Getting info log for shader %u", shader);
    glGetShaderInfoLog(shader, sizeof(buf) - 1, NULL, buf);
    qDebug() << "Shader error log: " << buf << endl;
}

static void printProgramLog(GLuint program)
{
    char buf[2048];
    memset(buf, 0, sizeof(buf));
    LOGE("Getting info log for program %u", program);
    glGetProgramInfoLog(program, sizeof(buf) - 1, NULL, buf);
    LOGE("Info log:\n%s", buf);
}

Shader::Shader()
{

}

Shader::~Shader() {}

const char* getShaderName()
{
    return "no shader name - base class";
}

void Shader::compile()
{
    //Do nothing
}

void Shader::compile(const char* vertPath, const char* fragPath)
{
    GLint status = 0;

    std::string vertStr;
    loadShader(vertPath, vertStr);
    const char* vertSource = vertStr.c_str();

    std::string fragStr;
    loadShader(fragPath, fragStr);
    const char* fragSource = fragStr.c_str();

    qDebug() << "vert source: " << vertSource << endl;
    qDebug() << "frag source: " << fragSource << endl;

    vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    if (!vertexShaderId || !fragmentShaderId) {
        LOGE("Failed to create shader id");
        ABORT_APP;
    }
    glShaderSource(vertexShaderId, 1, &vertSource, NULL);
    glCompileShader(vertexShaderId);
    glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &status);
    if (status == 0) {
        LOGE("Vertex shader compilation failed");
        printShaderLog(vertexShaderId);
        ABORT_APP;
    } else {
        LOGD("Vertex shader compilation successful");
    }
    glShaderSource(fragmentShaderId, 1, &fragSource, NULL);
    glCompileShader(fragmentShaderId);
    glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &status);
    if (status == 0) {
        LOGE("Fragment shader compilation failed");
        printProgramLog(fragmentShaderId);
        ABORT_APP;
    } else {
        LOGD("Fragment shader compilation successful");
    }
    programId = glCreateProgram();
    if (!programId) {
        LOGE("Failed to create program");
        printProgramLog(programId);
        ABORT_APP;
    }
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    glLinkProgram(programId);
    glGetProgramiv(programId, GL_LINK_STATUS, &status);
    if (status == 0) {
        LOGE("Shader program link failed %d, status");
        char buf[2048];
        memset(buf, 0, sizeof(buf));
        LOGE("*** Getting info log for program %u", programId);
        glGetProgramInfoLog(programId, sizeof(buf) - 1, NULL, buf);
        qDebug() << "error log: " << buf << endl;
        ABORT_APP;
    }
    LOGD("Program linking successful");
}

void Shader::loadShader(const char* filePath, std::string &source)
{
    QFile file(filePath);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Error opening file" << endl;
    }
    QTextStream in(&file);
    QString s = in.readAll();
    qDebug() << "s: " << s << endl;
    source = s.toStdString();
}

void Shader::printShaderLog(GLuint shader)
{
    char buf[2048];
    memset(buf, 0, sizeof(buf));
    LOGE("Getting info log for shader %u", shader);
    glGetShaderInfoLog(shader, sizeof(buf) - 1, NULL, buf);
    qDebug() << "Shader error log: " << buf << endl;
}

void Shader::printProgramLog(GLuint program)
{
    char buf[2048];
    memset(buf, 0, sizeof(buf));
    LOGE("Getting info log for program %u", program);
    glGetProgramInfoLog(program, sizeof(buf) - 1, NULL, buf);
    LOGE("Info log:\n%s", buf);
}

void Shader::use()
{
    //qDebug() << "programId: " << programId << endl;
    glUseProgram(programId);
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(programId, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(programId, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(programId, name.c_str()), value);
}

void Shader::setVec2(const std::string &name, const glm::vec2 &value) const
{
    glUniform2fv(glGetUniformLocation(programId, name.c_str()), 1, &value[0]);
}

void Shader::setVec2(const std::string &name, float x, float y) const
{
    glUniform2f(glGetUniformLocation(programId, name.c_str()), x, y);
}

void Shader::setVec3(const std::string &name, const glm::vec3 &value) const
{
    glUniform3fv(glGetUniformLocation(programId, name.c_str()), 1, &value[0]);
}

void Shader::setVec3(const std::string &name, float x, float y, float z) const
{
    glUniform3f(glGetUniformLocation(programId, name.c_str()), x, y, z);
}

void Shader::setVec4(const std::string &name, const glm::vec4 &value) const
{
    glUniform4fv(glGetUniformLocation(programId, name.c_str()), 1, &value[0]);
}

void Shader::setVec4(const std::string &name, float x, float y, float z, float w)
{
    glUniform4f(glGetUniformLocation(programId, name.c_str()), x, y, z, w);
}

void Shader::setMat2(const std::string &name, const glm::mat2 &mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(programId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat3(const std::string &name, const glm::mat3 &mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(programId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(programId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
