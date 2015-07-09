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
        iLeft = 1600;
    else
        iLeft = i;
       
    double iRight = 0;
    i = (x2/**0.999*/ - start.x )/d.x;
    
    y = start.y + d.y * i;
    z = start.z + d.z * i;
    if( y<y1 || y>=y2 || z<z1 || z>=z2 )
        iRight = 1600;
    else
        iRight = i;

    double iTop = 0;
    i = (y2/**0.999*/ - start.y )/d.y;
    x = start.x + d.x * i;
    z = start.z + d.z * i;
    
    double xTest = start.x + d.x * i;
    
    if( x<x1 || x>=x2 || z<z1 || z>=z2 )
        iTop = 1600;
    else
        iTop = i;

    double iBottom = 0;
    i = (y1 - start.y )/d.y;
    x = start.x + d.x * i;
    z = start.z + d.z * i;
    if( x<x1 || x>=x2 || z<z1 || z>=z2 )
        iBottom = 1600;
    else
        iBottom = i;

    double iFront = 0;
    i = (z2/**0.999*/ - start.z )/d.z;
    x = start.x + d.x * i;
    y = start.y + d.y * i;
    if( x<x1 || x>=x2 || y<y1 || y>=y2 )
        iFront = 1600;
    else
        iFront = i;

    double iBack = 0;
    i = (z1 - start.z )/d.z;
    x = start.x + d.x * i;
    y = start.y + d.y * i;
    if( x<x1 || x>=x2 || y<y1 || y>=y2 )
        iBack = 1600;
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
double Ray::exitCube(double x1, double y1, double z1, double x2, double y2, double z2)
{
	// Start of user code exitCube
    glm::vec3 d = getNormalizedPoint();
    double i = 0;
    double x = 0;
    double y = 0;
    double z = 0;
    
    double iLeft = 0;
    i = (x1 - start.x )/d.x;
    y = start.y + d.y * i;
    z = start.z + d.z * i;
    
    double iTest = (x1 - start.x )/d.x;
    double yTest = start.y + d.y * iTest;
    
    if( y<y1 || y>=(y2+1) || z<z1 || z>=(z2+1) )
        iLeft = 0;
    else
        iLeft = ((x1) - start.x )/d.x;//i;//+0.0001;
    
    double iRight = 0;
    i = ((x2+1)/**0.99999*/ - start.x )/d.x;
    
    double xTest = start.x + d.x * i;
    y = start.y + d.y * i;
    z = start.z + d.z * i;
    if( y<y1 || y>=(y2+1) || z<z1 || z>=(z2+1) )
        iRight = 0;
    else
        iRight = ((x2) - start.x )/d.x;//+0.0001;//i;
    
    double iTop = 0;
    i = ((y2+1)/**0.99999*/ - start.y )/d.y;
    x = start.x + d.x * i;
    z = start.z + d.z * i;
    if( x<x1 || x>=(x2+1) || z<z1 || z>=(z2+1) )
        iTop = 0;
    else
        iTop = ((y2) - start.y )/d.y;//+0.0001;//i;
    
    double iBottom = 0;
    i = (y1 - start.y )/d.y;
    x = start.x + d.x * i;
    double testY = start.y + d.y * i;
    z = start.z + d.z * i;
    if( x<x1 || x>=(x2+1) || z<z1 || z>=(z2+1) )
        iBottom = 0;
    else
        iBottom = ((y1) - start.y )/d.y;//i;//+0.0001;
    
    double iFront = 0;
    i = ((z2+1)/**0.99999*/ - start.z )/d.z;
    x = start.x + d.x * i;
    y = start.y + d.y * i;
    if( x<x1 || x>=(x2+1) || y<y1 || y>=(y2+1) )
        iFront = 0;
    else
        iFront = ((z2) - start.z )/d.z;//+0.0001;//i;
    
    double iBack = 0;
    i = (z1  - start.z )/d.z;
    x = start.x + d.x * i;
    y = start.y + d.y * i;
    if( x<x1 || x>=(x2+1) || y<y1 || y>=(y2+1) )
        iBack = 0;
    else
        iBack = ((z1)  - start.z )/d.z;//i;//+0.0001;
    
    double res = iLeft;
    res = max(res, iRight);
    res = max(res, iTop);
    res = max(res, iBottom);
    res = max(res, iFront);
    res = max(res, iBack);
    
    if(res <0)
        res = 0;
    
    x = start.x + d.x * res;
    y = start.y + d.y * res;
    z = start.z + d.z * res;
    
    //TODO changer
    if(res==iLeft || res==iRight)
        x=(int)x;
    if(res==iTop || res==iBottom)
        y=(int)y;
    if(res==iFront || res==iBack)
        z=(int)z;
    
    int iX = x;
    int iY = y;
    int iZ = z;
    
    double decX = 0;
    if(iX==x)
        decX = d.x < 0 ? -1 : 1;
    else
        decX = d.x < 0 ? -(x-iX) : 1-(x-iX);
    double decY = 0;
    if(iY==y)
        decY = d.y < 0 ? -1 : 1;
    else
        decY = d.y < 0 ? -(y-iY) : 1-(y-iY);
    double decZ = 0;
    if(iZ==z)
        decZ = d.z < 0 ? -1 : 1;
    else
        decZ = d.z < 0 ? -(z-iZ) : 1-(z-iZ);
    
    if( x<1 && d.x< 0)
        return -start.x/d.x;
    if( y<1 && d.y< 0)
        return -start.y/d.y;
    if( z<1 && d.z< 0)
        return -start.z/d.z;

    double resX = ((x+decX)-start.x)/d.x;
    double resY = ((y+decY)-start.y)/d.y;
    double resZ = ((z+decZ)-start.z)/d.z;
    
    double res2 = 0;
    if(res==iLeft || res==iRight)//resX>res)
        res2 = resX;//max(res2,resX);
    else if(res==iTop || res==iBottom)//resY>res)
        res2 = resY;//max(res2,resY);
    else if(res==iBack || res==iFront)//resZ>res)
        res2 = resZ;//max(res2,resZ);
    
    if(res2==0)
        return res2;
    
    if( ((start.x + d.x * res2) < 0) )
        return -start.x/d.x;
    if( ((start.y + d.y * res2) < 0) )
        return -start.y/d.y;
    if( ((start.z + d.z * res2) < 0) )
        return -start.z/d.z;
    
    if( ((start.x + d.x * res2) < 0) || ((start.y + d.y * res2) < 0) || ((start.z + d.z * res2) < 0) )
        return res2;
    
    return res2;
	// End of user code
}

