#version 400

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in vec4 _fragmentColor[];
in vec4 _vertexPosition[];
in float _fragmentAo[];
in vec3 _cubeColor[];
in vec3 _vertexWidth[];
in vec4 _viewSpace[];
in mat4 _M[];
in mat4 _V[];
in mat4 _P[];

out vec4 fragmentColor;
out vec4 vertexPosition;
out float fragmentAo;
out vec3 cubeColor;
out vec3 vertexWidth;
out vec4 viewSpace;

void main()
{
    fragmentColor = _fragmentColor[0];
    vertexPosition = _vertexPosition[0];
    fragmentAo = _fragmentAo[0];
    cubeColor = _cubeColor[0];
    vertexWidth = _vertexWidth[0];
    viewSpace = _viewSpace[0];
    
    for(int i = 0; i < 3; i++)
    {
        gl_Position = gl_in[i].gl_Position;
        
        
        
        if(gl_in[i].gl_Position.x>-gl_in[i].gl_Position.w && gl_in[i].gl_Position.y>-gl_in[i].gl_Position.w && gl_in[i].gl_Position.x<gl_in[i].gl_Position.w && gl_in[i].gl_Position.y<gl_in[i].gl_Position.w )
            EmitVertex();
    }
    EndPrimitive();
}