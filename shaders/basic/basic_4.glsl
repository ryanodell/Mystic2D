#shader vertex

#version 330 core
layout (location = 0) in vec2 aPosition;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoords;

uniform mat4 transform;

out vec4 oColor;
out vec2 oCoords;

void main() 
{
	gl_Position = transform * vec4(aPosition.xy, 0.0, 1.0);
    oColor = aColor;
	oCoords = aTexCoords;
}

#shader fragment

#version 330 core
layout(location = 0) out vec4 color;
in vec4 oColor;
in vec2 oCoords;

uniform sampler2D texture1;

void main() 
{
	vec4 texColor = texture(texture1, oCoords);
	if (texColor.rgb == vec3(1.0, 0.0, 1.0)) 
    {
        discard;
    }
	color = texture(texture1, oCoords) * oColor;
}