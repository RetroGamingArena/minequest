#version 330 core
in vec3 fragmentColor;
in vec3 cubeColor;
//in vec4 fragmentPosition;
in float fragmentAo;
in float _vertexWidth;

out vec4 color;

uniform sampler2D myTextureSampler;

void main()
{
    float ao = fragmentAo;
    ao = min(1.0, ao);
         if(fragmentColor.r<1.0 && mod(fragmentColor.r*2*_vertexWidth/16.0,2/16.0)<0.01)
        color  = vec4(0.0, 0.0, 0.0, 1.0);
    else if(fragmentColor.g<1.0 && mod(fragmentColor.g*2*_vertexWidth/16.0,2/16.0)<0.01)
        color  = vec4(0.0, 0.0, 0.0, 1.0);
    else if(fragmentColor.b<1.0 && mod(fragmentColor.b*2*_vertexWidth/16.0,2/16.0)<0.01)
        color  = vec4(0.0, 0.0, 0.0, 1.0);
    else
        color  = vec4(cubeColor, 1.0);
    
    color = clamp(vec4(color * ao), vec4(0.0), vec4(1.0));
    color.a = 1;
}