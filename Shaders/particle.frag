#version 410 core
in vec2 TexCoord;
uniform sampler2D texture0;
out vec4 FragColor;
void main()
{
    //FragColor = vec4(0.0f, 1.0f, 1.0f, 1.0f);
    FragColor = texture(texture0, TexCoord);
}
