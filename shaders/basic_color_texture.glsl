#shader vertex
#version 330 core
layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTexCoord;

out vec2 texCoord;
out vec4 color;

void main(void)
{
    texCoord = vec2(aTexCoord.x, aTexCoord.y);
    color = vec4(aColor, 1.0);
    gl_Position = vec4(aPosition, 1.0);
}

#shader fragment
#version 330
out vec4 outputColor;
in vec2 texCoord;
in vec4 color;
uniform sampler2D texture1;

void main()
{
    vec4 texColor = texture(texture1, texCoord);
    if (texColor.rgb == vec3(1.0, 0.0, 1.0)) 
    {
        discard;
    }
    outputColor = texture(texture1, texCoord) * color;
}