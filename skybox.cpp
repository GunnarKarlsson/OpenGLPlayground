#include "skybox.h"

Skybox::Skybox() {
    glGenVertexArrays(1, &skyboxVAO);
    glGenBuffers(1, &skyboxVBO);
    glBindVertexArray(skyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    skyboxShader = new Shader(":/Shaders/Shaders/skybox.vert", ":/Shaders/Shaders/skybox.frag");
    skyboxShader->compile();
}

Skybox::~Skybox() {
    delete skyboxShader;
}

void Skybox::update(const glm::mat4 &view, const glm::mat4 &projection) const {
    glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
    skyboxShader->use();
    skyboxShader->setMat4("view", view);
    skyboxShader->setMat4("projection", projection);
    skyboxShader->setVec3("skyColor", 1.0f, 1.0f, 1.0f);

    // skybox cube
    glBindVertexArray(skyboxVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxTextureId);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glDepthFunc(GL_LESS); // set depth function back to default
}

void Skybox::setTextureId(unsigned int &id) {
    skyboxTextureId = id;
    skyboxShader->setInt("skybox", 0);
}
