#version 330

layout (points) in;
layout (points) out;
layout (max_vertices = 1) out;

struct vData
{
    vec3 normal;
    vec4 color;
};

in vData vertices[];
out vData frag;


void main()
{
    int i;
    for(i = 0;i < gl_in.length();i++)
    {
        frag.normal = vertices[i].normal;
        frag.color = vertices[i].color;
        gl_Position = gl_in[i].gl_Position;
        EmitVertex();
    }
    EndPrimitive();
}