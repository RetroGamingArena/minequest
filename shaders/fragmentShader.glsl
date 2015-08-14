#version 410 core
#pragma optionNV (unroll all)

in vec4 fragmentColor;
in vec3 cubeColor;
in float fragmentAo;
in vec3 _vertexWidth;

in float _vertexColorIndex;

in vec4 viewSpace;
in vec4 vertexPosition;

in mat4 _M;
in mat4 _V;
in mat4 _P;
in vec3 _camera;
in vec3 _offsetVec;

out vec4 color;

uniform int rayLength;
uniform sampler2D myTextureSampler;

const vec3 fogColor = vec3(0.5, 0.5, 0.5);

vec3 delta;

vec4 getCollideColor(int i)
{
    vec3 current = _camera - delta*i;
    //if(current.x <= 0)
    return vec4(1.0, 0.0, 1.0, 1.0);
    //else
    //    return vec4(0.5, 0.0, 1.0, 1.0);
}

bool isCollided(int i)
{
    vec3 current = _camera - delta*i;
    bool res = current.x > 0;
    return res;
}

void main()
{
    //discard;
    vec4 viewport = vec4(0,0,1920,1080);
    
    mat4 VM = _V*_M;
    
    mat4 mvp = _P*VM;

    mat4 _inverse = inverse(mvp);
    vec4 tmp = vec4(gl_FragCoord.x, gl_FragCoord.y, 1.0, 1.0);
    tmp.x = (tmp.x - viewport.x) / viewport.z;
    tmp.y = (tmp.y - viewport.y) / viewport.t;
    tmp = tmp * 2 - 1;
    vec4 obj = _inverse * tmp;
    obj /= obj.w;
    vec3 unprojection = obj.xyz;
    
    //int length = 2;
    delta = (_camera - unprojection)/rayLength;
    
    color = vec4(0.0, 0.0, 0.0, 1.0);
    vec4 _color = vec4(0.0, 0.0, 0.0, 1.0);
    
    bool collided = false;
    vec4 collideColor = vec4(0.0, 0.0, 0.0, 1.0);
    
    int i;
    vec4 test;
    i=0;
    vec3 current = _camera - delta*0;
    i=1;
    vec3 current2 = _camera - delta*1;
    if(current.x<=0)
    {
        color = vec4(1.0, 0.0, 0.0, 1.0);
    }
    else if(current2.x<=0)
    {
        color = vec4(1.0, 0.0, 0.0, 1.0);
    }
    else
        discard;
    /*else
    {
        i=1;
        current = _camera - delta*i;
        if(current.x<=0)
        {
            color = vec4(0.0, 1.0, 0.0, 1.0);
        }
        else
            discard;
    }*/
}