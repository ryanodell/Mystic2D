#shader vertex
//IMPORTANT - THIS DOESN'T WORK, DON'T USE IT
#version 330 core
layout (location = 0) in vec2 aPosition;
layout (location = 1) in vec3 aColor;
out vec4 outColor;

void main() 
{
	gl_Position = vec4(aPosition.xy, 0, 1.0);
    outColor = vec4(aColor.xyz, 1.0);
}

#shader fragment

#version 330 core
out vec4 fragColor;
in vec4 outColor;

void main() 
{
    fragColor = outColor;
	//fragColor = vec4(1.0, 0.0, 0.0, 1.0);
}