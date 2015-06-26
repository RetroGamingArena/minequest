#include <cstdlib>

#include "TrackBallCamera.h"
// Start of user code includes
#include "Chunk.h"
#include "World.h"
// End of user code

TrackBallCamera::TrackBallCamera(float _distance, bool _hold, float _motionSensitivity, float _scrollSensitivity)
{
	distance = _distance;
	hold = _hold;
	motionSensitivity = _motionSensitivity;
	scrollSensitivity = _scrollSensitivity;
}

TrackBallCamera::TrackBallCamera()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    //Camera::Camera();
    
    angleY = 3.14/8;
    angleZ = 3.14/4;
    distance = 70;
    
    hold = false;
    motionSensitivity = 0.3;
    scrollSensitivity = 1;
    
    oldX=0;
    oldY=0; 
    
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

void TrackBallCamera::onMouseMotion(double xpos, double ypos)
{
	// Start of user code onMouseMotion
    double dx = xpos-oldX;
    double dy = ypos-oldY;
    
    if (hold) //si nous maintenons le bouton gauche enfoncé
    {
        angleZ += dx*motionSensitivity; //mouvement sur X de la souris -> changement de la rotation horizontale
        angleY += dy*motionSensitivity; //mouvement sur Y de la souris -> changement de la rotation verticale
        //pour éviter certains problèmes, on limite la rotation verticale à des angles entre -90° et 90°
        /*if (_angleY > 90)
         _angleY = 90;
         else if (_angleY < -90)
         _angleY = -90;*/
        fireEvent(events[0]);
    }
    
    oldX = xpos;
    oldY = ypos;
	// End of user code
}
void TrackBallCamera::onMouseButton(int button, int action)
{
	// Start of user code onMouseButton
    if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if ((hold)&&(action == GLFW_RELEASE))
        {
            hold = false;
        }
        else if ((!hold)&&(action == GLFW_PRESS))
        {
            hold = true;
        }
    }
	// End of user code
}
void TrackBallCamera::onKeyboard(int key, int scancode, int action, int mods)
{
	// Start of user code onKeyboard
	// End of user code
}
void TrackBallCamera::onMouseWheel(double xoffset, double yoffset)
{
	// Start of user code onMouseWheel
    if (yoffset < 0)
    {
        distance -= scrollSensitivity;
        if (distance < 0.1)
            distance = 0.1;
    }
    else if (yoffset > 0)
    {
        distance += scrollSensitivity;
    }
    fireEvent(events[0]);
	// End of user code
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

bool TrackBallCamera::getHold()
{
	// Start of user code getHold
	// End of user code
	return hold;
}

void TrackBallCamera::setHold(bool _hold)
{
	hold = _hold;
}

float TrackBallCamera::getMotionSensitivity()
{
	// Start of user code getMotionSensitivity
	// End of user code
	return motionSensitivity;
}

void TrackBallCamera::setMotionSensitivity(float _motionSensitivity)
{
	motionSensitivity = _motionSensitivity;
}

float TrackBallCamera::getScrollSensitivity()
{
	// Start of user code getScrollSensitivity
	// End of user code
	return scrollSensitivity;
}

void TrackBallCamera::setScrollSensitivity(float _scrollSensitivity)
{
	scrollSensitivity = _scrollSensitivity;
}


glm::vec3 TrackBallCamera::getCenter()
{
	// Start of user code getCenter
    return glm::vec3(World::size*Chunk::size+4, 0, World::size*Chunk::size+4);
	// End of user code
}
glm::vec3 TrackBallCamera::getPosition()
{
	// Start of user code getPosition
    glm::vec3 res(
                      cos(angleY) * sin(angleZ) * distance,
                      sin(angleY) * distance,
                      cos(angleY) * cos(angleZ) * distance
                      );
    return res;
	// End of user code
}

