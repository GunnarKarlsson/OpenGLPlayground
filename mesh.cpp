#include "mesh.h"

#include <QtMath>

Mesh::Mesh(std::vector<float> vertices, std::vector<unsigned int> indices, glm::vec3 color)
{
    this->vertices = vertices;
    this->indices = indices;

    xPos = 0.0f;
    yPos = 0.0f;
    zPos = 0.0f;

    xScale = SCALE_MODIFIER;
    yScale = SCALE_MODIFIER;
    zScale = SCALE_MODIFIER;

    xRotationRadians = 0.0f;
    yRotationRadians = 0.0f;
    zRotationRadians = 0.0f;

    size = glm::vec3(0.1f, 0.1f, 0.1f);

    objectColor = color;

    init();
}

Mesh::~Mesh()
{
    vertices.clear();
    indices.clear();
}

void Mesh::init()
{
    // create buffers/arrays
         glGenVertexArrays(1, &VAO);
         glGenBuffers(1, &VBO);
         glGenBuffers(1, &EBO);

         glBindVertexArray(VAO);
         // load data into vertex buffers
         glBindBuffer(GL_ARRAY_BUFFER, VBO);
         // A great thing about structs is that their memory layout is sequential for all its items.
         // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
         // again translates to 3/2 floats which translates to a byte array.
         glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
         glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

         // set the vertex attribute pointers
         // vertex Positions
         glEnableVertexAttribArray(0);
         glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
         // vertex normals
         glEnableVertexAttribArray(1);
         glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

         glBindVertexArray(0);
}

void Mesh::setPosition(float x, float y, float z)
{
    xPos = x;
    yPos = y;
    zPos = z;
}

void Mesh::setScale(float x, float y, float z)
{
    xScale = x * SCALE_MODIFIER;
    yScale = y * SCALE_MODIFIER;
    zScale = z * SCALE_MODIFIER;
}

void Mesh::setRotation(float xDegrees, float yDegrees, float zDegrees)
{
    xRotationRadians = M_PI/180.0f * xDegrees;
    yRotationRadians = M_PI/180.0f * yDegrees;
    zRotationRadians = M_PI/180.0f * zDegrees;
}

void Mesh::render(const glm::mat4 &view, const glm::mat4 &projection, const glm::vec3 lightPos, const glm::vec3 lightColor, const Shader *shader)
{
    glm::mat4 model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(xPos, yPos, zPos));
    model = glm::scale(model, glm::vec3(xScale, yScale, zScale));
    model = glm::rotate(model, xRotationRadians, glm::vec3(1.0, 0.0, 0.0));
    model = glm::rotate(model, yRotationRadians, glm::vec3(0.0, 1.0, 0.0));
    model = glm::rotate(model, zRotationRadians, glm::vec3(0.0, 0.0, 1.0));
    shader->use();
    shader->setMat4("model", model);
    shader->setMat4("view", view);
    shader->setMat4("projection", projection);
    shader->setVec3("objectColor", objectColor);
    shader->setVec3("lightPos", lightPos);
    shader->setVec3("lightColor", lightColor);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

