#include <cstdlib>

#include "TrackBallCamera.h"
// Start of user code includes
// End of user code

TrackBallCamera::TrackBallCamera(glm::vec3 _position, glm::vec3 _center, glm::vec3 _up, float _angleY, float _angleZ, float _distance)
{
	position = _position;
	center = _center;
	up = _up;
	angleY = _angleY;
	angleZ = _angleZ;
	distance = _distance;
}

TrackBallCamera::TrackBallCamera()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    Camera::Camera();
    
    angleY = 3.14/8;
    angleZ = 3.14/4;
    distance = 70;
    
    center = glm::vec3(0,0,0);
    up = glm::vec3(0,1,0);
    
    view       = glm::lookAt(
                             getPosition(),           // Camera is here
                             getCenter(), // and looks here : at the same position, plus "direction"
                             getUp()                  // Head is up (set to 0,-1,0 to look upside-down)
                             );
    
    // End of user code
}

TrackBallCamera::~TrackBallCamera()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code




glm::vec3 TrackBallCamera::getPosition()
{
	// Start of user code getPosition
    position = glm::vec3 (
                       cos(angleY) * sin(angleZ) * distance,
                       sin(angleY) * distance,
                       cos(angleY) * cos(angleZ) * distance
                       );
    
	// End of user code
	return position;
}

void TrackBallCamera::setPosition(glm::vec3 _position)
{
	position = _position;
}
glm::vec3 TrackBallCamera::getCenter()
{
	// Start of user code getCenter
	// End of user code
	return center;
}

void TrackBallCamera::setCenter(glm::vec3 _center)
{
	center = _center;
}
glm::vec3 TrackBallCamera::getUp()
{
	// Start of user code getUp
	// End of user code
	return up;
}

void TrackBallCamera::setUp(glm::vec3 _up)
{
	up = _up;
}
float TrackBallCamera::getAngleY()
{
	// Start of user code getAngleY
	// End of user code
	return angleY;
}

void TrackBallCamera::setAngleY(float _angleY)
{
	angleY = _angleY;
}
float TrackBallCamera::getAngleZ()
{
	// Start of user code getAngleZ
	// End of user code
	return angleZ;
}

void TrackBallCamera::setAngleZ(float _angleZ)
{
	angleZ = _angleZ;
}
float TrackBallCamera::getDistance()
{
	// Start of user code getDistance
	// End of user code
	return distance;
}

void TrackBallCamera::setDistance(float _distance)
{
	distance = _distance;
}


