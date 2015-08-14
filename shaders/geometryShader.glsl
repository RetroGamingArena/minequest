#version 400

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in vec4 _fragmentColor[];
in vec4 _vertexPosition[];
in float _fragmentAo[];
in vec3 _cubeColor[];
in vec3 _vertexWidth[];
in vec4 _viewSpace[];

/*fragmentColor' not written by geometry shader
ERROR: Input of fragment shader 'vertexPosition' not written by geometry shader
ERROR: Input of fragment shader 'fragmentAo' not written by geometry shader
ERROR: Input of fragment shader 'cubeColor' not written by geometry shader
ERROR: Input of fragment shader '_vertexWidth' not written by geometry shader
ERROR: Input of fragment shader 'viewSpace' not written by geometry shader*/

out vec4 fragmentColor;
out vec4 vertexPosition;
out float fragmentAo;
out vec3 cubeColor;
out vec3 vertexWidth;
out vec4 viewSpace;

void main() {
    for(int i = 0; i < 3; i++) { // You used triangles, so it's always 3
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