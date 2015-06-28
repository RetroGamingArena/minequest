#include <cstdlib>

#include "Ray.h"
// Start of user code includes
// End of user code

Ray::Ray(glm::vec3 _start, glm::vec3 _direction)
{
	start = _start;
	direction = _direction;
}

Ray::Ray()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

Ray::~Ray()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code




glm::vec3 Ray::getStart()
{
	// Start of user code getStart
	// End of user code
	return start;
}

void Ray::setStart(glm::vec3 _start)
{
	start = _start;
}

glm::vec3 Ray::getDirection()
{
	// Start of user code getDirection
	// End of user code
	return direction;
}

void Ray::setDirection(glm::vec3 _direction)
{
	direction = _direction;
}


glm::vec3 Ray::move(double i)
{
	// Start of user code move
    glm::vec3 d = getNormalizedPoint();
    d *= i;
    d = d + start;
    return d;
	// End of user code
}
glm::vec3 Ray::getNormalizedPoint()
{
	// Start of user code getNormalizedPoint
    glm::vec3 d = (direction - start);
    
    float coef = abs(d.x);
    coef = max(coef, abs(d.y));
    coef = max(coef, abs(d.z));
    
    if(coef == 0)
    {
        int a = 2;
    }
    
    d/=coef;
    return d;
	// End of user code
}
double Ray::enterCube(double x1, double y1, double z1, double x2, double y2, double z2)
{
	// Start of user code enterCube
    glm::vec3 d = getNormalizedPoint();
    double i = 0;
    double x = 0;
    double y = 0;
    double z = 0;

    double iLeft = 0;
    i = (x1 - start.x )/d.x;
    y = start.y + d.y * i;
    z = start.z + d.z * i;
    if( y<y1 || y>=y2 || z<z1 || z>=z2 )
        iLeft = 100;
    else
        iLeft = i;
       
    double iRight = 0;
    i = (x2*0.99 - start.x )/d.x;
    
    double xTest = start.x + d.x * i;
    y = start.y + d.y * i;
    z = start.z + d.z * i;
    if( y<y1 || y>=y2 || z<z1 || z>=z2 )
        iRight = 100;
    else
        iRight = i;

    double iTop = 0;
    i = (y2*0.99 - start.y )/d.y;
    x = start.y + d.y * i;
    z = start.z + d.z * i;
    if( x<x1 || x>=x2 || z<z1 || z>=z2 )
        iTop = 100;
    else
        iTop = i;

    double iBottom = 0;
    i = (y1 - start.y )/d.y;
    x = start.x + d.x * i;
    z = start.z + d.z * i;
    if( x<x1 || x>=x2 || z<z1 || z>=z2 )
        iBottom = 100;
    else
        iBottom = i;

    double iFront = 0;
    i = (z2*0.99 - start.z )/d.z;
    x = start.x + d.x * i;
    y = start.y + d.y * i;
    if( x<x1 || x>=x2 || y<y1 || y>=y2 )
        iFront = 100;
    else
        iFront = i;

    double iBack = 0;
    i = (z1 - start.z )/d.z;
    x = start.x + d.x * i;
    y = start.y + d.y * i;
    if( x<x1 || x>=x2 || y<y1 || y>=y2 )
        iBack = 100;
    else
        iBack = i;

    double res = iLeft;
    res = min(res, iRight);
    res = min(res, iTop);
    res = min(res, iBottom);
    res = min(res, iFront);
    res = min(res, iBack);
    
    if(res <0)
        res = 0;
    
    return res;
	// End of user code
}

