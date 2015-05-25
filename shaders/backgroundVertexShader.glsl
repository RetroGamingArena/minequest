#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
//layout(location = 1) in vec3 vertexColor;

void main()
{
    gl_Position.xyz = vertexPosition_modelspace;//.xy, 0);
    //gl_Position.z = 0;
    gl_Position.w = 1;
}