#include <cstdlib>

#include "TrackBallCamera.h"
// Start of user code includes
// End of user code

TrackBallCamera::TrackBallCamera(glm::vec3 _position, glm::vec3 _center, glm::vec3 _up)
{
	position = _position;
	center = _center;
	up = _up;
}

TrackBallCamera::TrackBallCamera()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    Camera::Camera();
    view       = glm::lookAt(
                             getPosition(),           // Camera is here
                             getCenter(), // and looks here : at the same position, plus "direction"
                             getUp()                  // Head is up (set to 0,-1,0 to look upside-down)
                             );
    center = glm::vec3(0,0,0);
	up = glm::vec3(0,1,0);
    // End of user code
}

// Start of user code methods
// End of user code




glm::vec3 TrackBallCamera::getPosition()
{
	return position;
}

void TrackBallCamera::setPosition(glm::vec3 _position)
{
	position = _position;
}
glm::vec3 TrackBallCamera::getCenter()
{
	return center;
}

void TrackBallCamera::setCenter(glm::vec3 _center)
{
	center = _center;
}
glm::vec3 TrackBallCamera::getUp()
{
	return up;
}

void TrackBallCamera::setUp(glm::vec3 _up)
{
	up = _up;
}


