#version 150

layout(triangles) in;
in VertexData
{
    vec3 offset;
    vec3 fragmentColor;
    vec3 cubeColor;
    float vertexWidth;
    float ao;
} VertexIn[];

/*out VertexData
{
    float fragmentColor;
} VertexOut;*/

layout (triangle_strip, max_vertices=3) out;
out vec3 fragmentColor;
out vec3 cubeColor;
out float _vertexWidth;
out float fragmentAo;

void main()
{
    for(int i = 0; i < gl_in.length(); i++)
    {
        // copy attributes
        gl_Position = gl_in[i].gl_Position;
        
        // done with the vertex
        cubeColor = VertexIn[i].cubeColor;
        fragmentColor = VertexIn[i].fragmentColor;
        _vertexWidth = VertexIn[i].vertexWidth;
        fragmentAo = VertexIn[i].ao;
        
        EmitVertex();
    }
}