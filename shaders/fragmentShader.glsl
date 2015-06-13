#version 410 core
in vec4 fragmentColor;
in vec3 cubeColor;
in float fragmentAo;
in vec3 _vertexWidth;

in float _vertexColorIndex;

in vec4 viewSpace;

out vec4 color;

uniform sampler2D myTextureSampler;

const vec3 fogColor = vec3(0.5, 0.5,0.5);

void main()
{
    float ao = fragmentAo;
    ao = min(1.0, ao);
    
    color  = fragmentColor;
    
    float dist = length(viewSpace);
    
    float fogFactor = (80 - dist*2)/(80 - 20);
    
    color.a = .1;
    {
        color  = vec4(0.0, 1.0, 0.0, 1.0);
        
        if(fragmentColor.r<1.0 && mod(fragmentColor.r*2*_vertexWidth.x/16.0,2/16.0)<0.01)
            color  = vec4(0.0, 0.0, 0.0, 1.0);
        else if(fragmentColor.g<1.0 && mod(fragmentColor.g*2*_vertexWidth.y/16.0,2/16.0)<0.01)
            color  = vec4(0.0, 0.0, 0.0, 1.0);
        else if(fragmentColor.b<1.0 && mod(fragmentColor.b*2*_vertexWidth.z/16.0,2/16.0)<0.01)
            color  = vec4(0.0, 0.0, 0.0, 1.0);
        else
            color  = vec4(cubeColor, 1.0);
        color = clamp(vec4(color * ao), vec4(0.0), vec4(1.0));
    }

    color.a = 1;
    
    fogFactor = clamp( fogFactor, 0.0, 1.0 );
    
    vec3 lightColor = vec3(color.rgb);
    vec3 finalColor = mix(fogColor, lightColor, fogFactor);
    color = vec4(finalColor, 1);

}