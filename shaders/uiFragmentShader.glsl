#version 330 core
//in vec3 fragmentColor;

in vec2 UV;
out vec4 color;

uniform sampler2D myTextureSampler;

void main()
{
    color = texture( myTextureSampler, UV );//vec3(0,1,0); //fragmentColor;//
}