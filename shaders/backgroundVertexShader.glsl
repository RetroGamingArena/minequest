#version 330 core

layout(location = 0) in uvec3 vertexPosition_modelspace;
layout(location = 1) in uvec3 vertexColor;

out vec3 _color;

void main()
{
    gl_Position.xyz = vertexPosition_modelspace;
    gl_Position.x--;
    gl_Position.y--;
    gl_Position.z = 0.5;
    gl_Position.w = 1;
    
    _color = vec3(vertexColor.r/256.0, vertexColor.g/256.0, vertexColor.b/256.0);
}