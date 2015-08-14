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

vec4 viewport = vec4(0,0,1920,1080);

void main() {
    bool _discard = false;
    
    for(int i = 0; i < 3; i++)
    {
        if(gl_in[i].gl_Position.x<-gl_in[i].gl_Position.w || gl_in[i].gl_Position.y<-gl_in[i].gl_Position.w || gl_in[i].gl_Position.x>gl_in[i].gl_Position.w || gl_in[i].gl_Position.y>gl_in[i].gl_Position.w )
        {
            _discard = true;
            break;
        }
    }

    if(!_discard)
    {
        for(int i = 0; i < 3; i++)
        {
            gl_Position = gl_in[i].gl_Position;
        
            fragmentColor = _fragmentColor[i];
            vertexPosition = _vertexPosition[i];
            fragmentAo = _fragmentAo[i];
            cubeColor = _cubeColor[i];
            vertexWidth = _vertexWidth[i];
            viewSpace = _viewSpace[i];
        
            EmitVertex();
        }
        EndPrimitive();
    }
}