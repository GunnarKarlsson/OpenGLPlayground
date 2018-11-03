#include "mesh.h"

Mesh::Mesh(std::vector<float> vertices, std::vector<unsigned int> indices, glm::vec3 color)
{
    this->vertices = vertices;
    this->indices = indices;

    xPos = 0.0f;
    yPos = 0.0f;
    zPos = 0.0f;

    size = glm::vec3(10.0f, 10.0f, 10.0f);

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

void Mesh::render(glm::mat4 &view, glm::mat4 &projection, glm::vec3 lightPos, glm::vec3 lightColor, Shader *shader)
{
    glm::mat4 model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(xPos, yPos, -1.0));
    size = glm::vec3(20.0f,20.0f,20.0f);
    float PI = 3.1415926f;
    model = glm::rotate(model, 35.264f * (PI/180), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, 45.0f * (PI/180), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, 90.0f * (PI/180), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, size);

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

