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


glm::vec3 Ray::move(int i)
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

