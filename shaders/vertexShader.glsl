#version 410 core

layout(location = 0) in uvec3 vertexPosition_modelspace;
layout(location = 1) in uint ambiant;

layout(location = 2) in uint _offset;
//layout(location = 3) in float vertexColorIndex;
layout(location = 3) in uint vertexWidth;
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

out vec4 viewSpace;

void main()
{
    uint iWidth = uint(vertexWidth);
    uint xWidth = (iWidth & uint(0x1ff))+1;
    uint yWidth = xWidth;//((iWidth & uint(0xfc0)) >> 6)+1;
    uint zWidth = xWidth;//((iWidth & uint(0x3f000)) >> 12)+1;

    float ao = ((iWidth & uint(0x600)) >> 18);
    int vertexColorIndex = int((iWidth & uint(0xf800)) >> 20);
    
    vec3 vertexPosition_temp = vec3(vertexPosition_modelspace.x*xWidth/16.0, vertexPosition_modelspace.y*yWidth/16.0, vertexPosition_modelspace.z*zWidth/16.0 );
    
    int iOffset = int(_offset);
    vec3 offset;
    
    float x = ((iOffset      & 0x300) >> 8)*16 +  ((iOffset      & 0xf0) >> 4) +  float(((iOffset) & 0xf)/16.0);
    float y = (((iOffset>>10) & 0x300) >> 8)*16 + (((iOffset>>10) & 0xf0) >> 4) + float(((iOffset>>10) & 0xf)/16.0);
    float z = (((iOffset>>20) & 0x300) >> 8)*16 + (((iOffset>>20) & 0xf0) >> 4) + float(((iOffset>>20) & 0xf)/16.0);
    
    offset.x = x;
    offset.y = y;
    offset.z = z;
    
    viewSpace = V * M * vec4(vertexPosition_temp+offset,1);
    gl_Position = P * viewSpace;
    
    ao = ao / 2.0;
    
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
    
    if(cubeColor == vec3(0.0,0.0,1.0))
        fragmentColor = vec4(cubeColor, 0.1);
    else
        fragmentColor = vec4(cubeColor, 1);
    
    fragmentColor.r = 0;
    fragmentColor.g = 0;
    fragmentColor.b = 0;
    
    if(vertexPosition_modelspace.x == 1)
    {
        fragmentColor.g = vertexPosition_modelspace.y;
        fragmentColor.b = vertexPosition_modelspace.z;
    }
    if(vertexPosition_modelspace.z == 1)
    {
        fragmentColor.g = vertexPosition_modelspace.y;
        fragmentColor.b = vertexPosition_modelspace.x;
    }
    
    vertexPosition = vec4(vertexPosition_modelspace, 1);//vertexPosition_temp,1);
    _vertexWidth = vec3(xWidth,yWidth,zWidth);
    
    _vertexColorIndex = vertexColorIndex;
}