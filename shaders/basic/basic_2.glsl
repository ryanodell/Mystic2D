#shader vertex

#version 330 core
layout (location = 0) in vec2 aPosition;
layout (location = 1) in vec4 aColor;

out vec4 oColor;

void main() 
{
	gl_Position = vec4(aPosition.xy, 0.0, 1.0);
    oColor = aColor;
}

#shader fragment

#version 330 core
layout(location = 0) out vec4 color;
in vec4 oColor;
void main() 
{
	color = oColor;
}