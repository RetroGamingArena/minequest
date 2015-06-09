#version 410 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in float ambiant;

layout(location = 2) in vec3 offset;
//layout(location = 3) in float vertexColorIndex;
layout(location = 3) in float vertexWidth;
//layout(location = 5) in float ao;

uniform mat4 MVP;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

out vec4 vertexPosition;
out vec4 fragmentColor;
out vec3 cubeColor;

out float fragmentAo;
out vec3 _vertexWidth;
out float _vertexColorIndex;

void main()
{
    int iWidth = int(vertexWidth);
    int xWidth = (iWidth & 0x1f)+1;
    int yWidth = ((iWidth & 0x3e0) >> 5)+1;
    int zWidth = ((iWidth & 0x7c00) >> 10)+1;
    
    float ao = ((iWidth & 0x18000) >> 15);
    int vertexColorIndex = ((iWidth & 0xfffe0000) >> 17);
    
    vec3 vertexPosition_temp = vec3(vertexPosition_modelspace.x*xWidth, vertexPosition_modelspace.y*yWidth, vertexPosition_modelspace.z*zWidth );

    gl_Position = P * V * M * vec4(vertexPosition_temp+offset,1);
    gl_Position.z = -0.3;

    fragmentAo = 0.3 + ( ambiant ) * 0.7;
    fragmentAo *= ( (3-ao)/6 + 0.5);
    
    fragmentColor.a = 0;
    
    cubeColor = vec3(1.0,1.0,1.0);
    if(vertexColorIndex == 1)
        cubeColor = vec3(0.0,1.0,0.0);
    else if(vertexColorIndex == 2)
        cubeColor = vec3(0.0,0.0,1.0);
    else if(vertexColorIndex == 3)
        cubeColor = vec3(1.0,1.0,0.0);
    else if(vertexColorIndex == 4)
        cubeColor = vec3(0.3,0.3,0.0);
    else if(vertexColorIndex == 5)
        cubeColor = vec3(0.5,0.5,0.5);

    {
        fragmentColor.r = vertexPosition_modelspace.x*16;
        fragmentColor.g = vertexPosition_modelspace.y*16;
        fragmentColor.b = vertexPosition_modelspace.z*16;
        fragmentColor.a = 1;
    }
    
    fragmentColor.a = 1;
    
    vertexPosition = vec4(vertexPosition_temp,1);
    _vertexWidth = vec3(xWidth,yWidth,zWidth);
    
    _vertexColorIndex = vertexColorIndex;
}