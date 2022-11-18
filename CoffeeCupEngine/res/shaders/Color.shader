#shader vertex
#version 330 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec4 inColor;

out vec4 vColor;

uniform mat4 uMVP;

void main() 
{   
    gl_Position = uMVP * vec4(inPosition, 1.0);
    vColor = inColor;
};


#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec4 vColor;

void main() 
{   
    color = vColor;
};
