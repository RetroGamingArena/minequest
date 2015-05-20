#version 410 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
//layout(location = 1) in float vertexColorIndex;
layout(location = 1) in float ambiant;

layout(location = 2) in vec3 offset;
layout(location = 3) in float vertexColorIndex;
layout(location = 4) in vec3 vertexWidth;
layout(location = 5) in float ao;

uniform mat4 MVP;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

out mat4 PVM = P * V * M;
out vec4 vertexPosition;
out vec4 fragmentColor;
out vec3 cubeColor;

out float fragmentAo;
out vec3 _vertexWidth;


out float _vertexColorIndex;

uniform mat4x3 cameraUnprojection;

uniform vec3 cameraPosition;

/*out VertexData
{
    vec3 offset;
    vec3 cubeColor;
    vec3 fragmentColor;
    float vertexWidth;
    float ao;
} VertexOut;*/

void main()
{
    vec3 vertexPosition_temp = vec3(vertexPosition_modelspace.x*vertexWidth.x, vertexPosition_modelspace.y*vertexWidth.y, vertexPosition_modelspace.z*vertexWidth.z);

    gl_Position = P * V * M * vec4(vertexPosition_temp+offset,1);
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
    
    //fragmentColor.rgb = cubeColor;
    //fragmentColor.a = 1;
    
    /*if(vertexColorIndex != 2)
    {
        fragmentColor.r = vertexPosition_modelspace.x*16;
        fragmentColor.g = vertexPosition_modelspace.y*16;
        fragmentColor.b = vertexPosition_modelspace.z*16;
        fragmentColor.a = 1;
    }
    else*/
    //if(vertexColorIndex == 2)
    {
        //fragmentColor.rgb = cubeColor;
        //fragmentColor.a = 0.7;
    }
    //else
    {
        fragmentColor.r = vertexPosition_modelspace.x*16;
        fragmentColor.g = vertexPosition_modelspace.y*16;
        fragmentColor.b = vertexPosition_modelspace.z*16;
        fragmentColor.a = 1;
    }
    
    fragmentColor.a = 1;
    
    
    vertexPosition = vec4(vertexPosition_temp,1);
    _vertexWidth = vertexWidth;
    
    /*VertexOut.fragmentColor = fragmentColor;
    VertexOut.cubeColor = cubeColor;
    VertexOut.ao = fragmentAo;
    VertexOut.vertexWidth = vertexWidth;*/
    
    _vertexColorIndex = vertexColorIndex;
}