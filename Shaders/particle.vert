#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 TexCoord;
void main()
{

    //gl_Position = projection * view * model * vec4(aPos, 1.0);

    mat4 vm = view * model;
    vm[0][0] = 1;
    vm[0][1] = 0;
    vm[0][2] = 0;

    vm[2][0] = 0;
    vm[2][1] = 0;
    vm[2][2] = 1;

    gl_Position = projection * vm * vec4(aPos, 1.0);
    TexCoord = aTexCoord;
}
