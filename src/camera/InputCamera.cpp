#include <cstdlib>

#include "InputCamera.h"
// Start of user code includes
// End of user code

InputCamera::InputCamera(float _oldY, float _oldX)
{
	oldY = _oldY;
	oldX = _oldX;
}

InputCamera::InputCamera()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}


// Start of user code methods
// End of user code

glm::vec3 InputCamera::getPosition()
{
	// Start of user code getPosition
    return position;
	// End of user code
}
glm::vec3 InputCamera::getCenter()
{
	// Start of user code getCenter
    return center;
	// End of user code
}
glm::vec3 InputCamera::getUp()
{
	// Start of user code getUp
    return glm::vec3(0,1,0);
	// End of user code
}



float InputCamera::getOldY()
{
	// Start of user code getOldY
	// End of user code
	return oldY;
}

void InputCamera::setOldY(float _oldY)
{
	oldY = _oldY;
}

float InputCamera::getOldX()
{
	// Start of user code getOldX
	// End of user code
	return oldX;
}

void InputCamera::setOldX(float _oldX)
{
	oldX = _oldX;
}



