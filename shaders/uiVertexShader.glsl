#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec2 vertexPosition;
//layout(location = 1) in vec3 vertexColor;
layout(location = 1) in vec2 vertexUV;

//out vec3 fragmentColor;
out vec2 UV;

uniform mat4 MVP;

void main()
{
    vec2 vertexPosition_homoneneousspace = vertexPosition - vec2(1920, 1080);
    vertexPosition_homoneneousspace /= vec2(1920, 1080);
    gl_Position =  vec4(vertexPosition_homoneneousspace,0,1);
    
    UV = vertexUV;
}