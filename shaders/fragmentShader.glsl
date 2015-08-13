#version 410 core
in vec4 fragmentColor;
in vec3 cubeColor;
in float fragmentAo;
in vec3 _vertexWidth;

in float _vertexColorIndex;

in vec4 viewSpace;
in vec4 vertexPosition;

out vec4 color;

uniform sampler2D myTextureSampler;

const vec3 fogColor = vec3(0.5, 0.5,0.5);

void main()
{
    
    
    color = vec4(fragmentColor.r, fragmentColor.g, fragmentColor.b, 1);
    
    /*float ao = fragmentAo;
    ao = min(1.0, ao);
    
    color  = fragmentColor;
    
    float dist = length(viewSpace);
    
    float fogFactor = (80 - dist*2)/(80 - 20);
    
    float gridFade = 0.2;
    vec4 gridColor = clamp(vec4(cubeColor.r-gridFade, cubeColor.g-gridFade, cubeColor.b-gridFade, 1.0), vec4(0.0), vec4(1.0));
    
    {
        float gridWidth = 0.0025;
        float startGrid = gridWidth;
        float endGrid = 0.125-gridWidth;
        
        if(fragmentColor.g == 0)
        {
            float modr = mod(fragmentColor.r*2*_vertexWidth.x/16.0,2/16.0);
            float modb = mod(fragmentColor.b*2*_vertexWidth.x/16.0,2/16.0);
            
            if(fragmentColor.r<1.0 && (modr<startGrid || modr>endGrid))
                color  = gridColor;
            else if(fragmentColor.b<1.0 && (modb<startGrid || modb>endGrid))
                color  = gridColor;
            else
                color  = vec4(cubeColor, 1.0);
        }
        else if(fragmentColor.r == 0)
        {
            float modg = mod(fragmentColor.g*2*_vertexWidth.y/16.0,2/16.0);
            float modb = mod(fragmentColor.b*2*_vertexWidth.y/16.0,2/16.0);
            
            if(fragmentColor.g<1.0 && (modg<startGrid || modg>endGrid))
                color  = gridColor;
            else if(fragmentColor.b<1.0 && (modb<startGrid || modb>endGrid))
                color  = gridColor;
            else
                color  = vec4(cubeColor, 1.0);
        }
        else if(fragmentColor.b == 0)
        {
            float modr = mod(fragmentColor.r*2*_vertexWidth.z/16.0,2/16.0);
            float modg = mod(fragmentColor.g*2*_vertexWidth.y/16.0,2/16.0);
            
            if(fragmentColor.r<1.0 && (modr<startGrid || modr>endGrid))
                color  = gridColor;
            else if(fragmentColor.g<1.0 && (modg<startGrid || modg>endGrid))
                color  = gridColor;
            else
                color  = vec4(cubeColor, 1.0);
        }
        else if( vertexPosition.y >= 0.999999 )
        {
            float modr = mod(fragmentColor.r*2*_vertexWidth.x/16.0,2/16.0);
            float modb = mod(fragmentColor.b*2*_vertexWidth.x/16.0,2/16.0);
            
            if(fragmentColor.r<1.0 && (modr<startGrid || modr>endGrid))
                color  = gridColor;
            else if(fragmentColor.b<1.0 && (modb<startGrid || modb>endGrid))
                color  = gridColor;
            else
                color  = vec4(cubeColor, 1.0);
        }
        else
        {
            float modg = mod(fragmentColor.g*2*_vertexWidth.y/16.0,2/16.0);
            float modrb = mod(fragmentColor.r*fragmentColor.b*2*_vertexWidth.y/16.0,2/16.0);
            if(fragmentColor.g<1.0 && (modg<startGrid || modg>endGrid))
                color  = gridColor;
            else if(fragmentColor.r*fragmentColor.b<1.0 && (modrb<startGrid || modrb>endGrid ))
                color  = gridColor;
            else
                color = vec4(cubeColor, 1.0);
        }
        
        color = clamp(vec4(color * ao), vec4(0.0), vec4(1.0));
    }
    
    fogFactor = clamp( fogFactor, 0.0, 1.0 );
    
    vec3 lightColor = vec3(color.rgb);
    vec3 finalColor = mix(fogColor, lightColor, fogFactor);
    color = vec4(finalColor, 1);*/

}