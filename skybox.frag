#version 330 core
out vec4 FragColor;

in vec3 TexCoords;

uniform samplerCube skybox;
uniform vec3 skyColor;

void main()
{
    FragColor = texture(skybox, TexCoords) * vec4(skyColor.x, skyColor.y, skyColor.z, 1.0);
}
