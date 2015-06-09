#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor;

out vec3 _color;

void main()
{
    gl_Position.xyz = vertexPosition_modelspace;
    gl_Position.z = 0.5;
    gl_Position.w = 1;
    
    _color = vec3(vertexColor.rgb);
}