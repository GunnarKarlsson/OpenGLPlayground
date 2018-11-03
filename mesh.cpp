#include "mesh.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
{
    this->vertices = vertices;
    this->indices = indices;

    xPos = 3.0f;
    yPos = 0.0f;
    zPos = 1.0f;

    size = glm::vec3(0.1f, 0.1f, 0.1f);

    objectColor = glm::vec3(1.0f, 1.0f, 1.0f);//TODO set from loaded model

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
         glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
         glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

         // set the vertex attribute pointers
         // vertex Positions
         glEnableVertexAttribArray(0);
         glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
         // vertex normals
         glEnableVertexAttribArray(1);
         glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));

         glBindVertexArray(0);
}

void Mesh::render(glm::mat4 &view, glm::mat4 &projection, glm::vec3 lightPos, glm::vec3 lightColor, Shader *shader)
{
    glm::mat4 model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(xPos, yPos, zPos));
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

