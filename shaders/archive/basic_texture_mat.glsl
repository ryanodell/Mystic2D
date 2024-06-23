#version 330 core
//IMPORTANT - THIS DOESN'T WORK, DON'T USE IT - ALSO, NOT IN RIGHT FORMAT
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoord;
layout(location = 2) in mat4 instanceMatrix;

out vec2 TexCoord;

void main()
{
    gl_Position = instanceMatrix * vec4(aPos, 0.0, 1.0);
    TexCoord = aTexCoord;
}
