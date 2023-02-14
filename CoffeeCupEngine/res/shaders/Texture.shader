R"(#shader vertex
#version 450 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec4 inColor;
layout(location = 2) in vec2 inTexCoord;
layout(location = 3) in float inTexId;

out vec4 vColor;
out vec2 vTextCoord;
out float vTexId;

uniform mat4 uMVP;

void main() 
{   
    gl_Position = uMVP * vec4(inPosition, 1.0);
    vColor = inColor;
    vTextCoord = inTexCoord;
    vTexId = inTexId;
};


#shader fragment
#version 450 core

layout(location = 0) out vec4 color;

in vec4 vColor;
in vec2 vTextCoord;
in float vTexId;

uniform sampler2D uTextures[32];

void main() 
{   
   color = texture(uTextures[int(vTexId)], vTextCoord) * vColor;
};)"

