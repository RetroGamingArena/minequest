#include <cstdlib>

#include "TrackBallCamera.h"
// Start of user code includes
// End of user code

TrackBallCamera::TrackBallCamera(glm::vec3 _position, glm::vec3 _center, glm::vec3 _up, float _angleY, float _angleZ, float _distance, float _oldX, float _oldY, bool _hold, float _motionSensitivity, float _scrollSensitivity)
{
	position = _position;
	center = _center;
	up = _up;
	angleY = _angleY;
	angleZ = _angleZ;
	distance = _distance;
	oldX = _oldX;
	oldY = _oldY;
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
    }
    
    oldX = xpos;
    oldY = ypos;
	// End of user code
}
void TrackBallCamera::onKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// Start of user code onKeyboard
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
void TrackBallCamera::onMouseWheel(double xoffset, double yoffset)
{
	// Start of user code onMouseWheel
    if (yoffset < 0) //coup de molette vers le haut
    {
        distance -= scrollSensitivity; //on zoome, donc rapproche la caméra du centre
        if (distance < 0.1) //distance minimale, à changer si besoin (avec un attribut par exemple)
            distance = 0.1;
    }
    else if (yoffset > 0) //coup de molette vers le bas
    {
        distance += scrollSensitivity; //on dézoome donc éloigne la caméra
    }
	// End of user code
}
glm::vec3 TrackBallCamera::getRealPosition()
{
	// Start of user code getRealPosition
    return getPosition();
	// End of user code
}
glm::vec3 TrackBallCamera::getRealCenter()
{
	// Start of user code getRealCenter
    return center;
	// End of user code
}
glm::vec3 TrackBallCamera::getRealUp()
{
	// Start of user code getRealUp
    return up;
	// End of user code
}



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
float TrackBallCamera::getOldX()
{
	// Start of user code getOldX
	// End of user code
	return oldX;
}

void TrackBallCamera::setOldX(float _oldX)
{
	oldX = _oldX;
}
float TrackBallCamera::getOldY()
{
	// Start of user code getOldY
	// End of user code
	return oldY;
}

void TrackBallCamera::setOldY(float _oldY)
{
	oldY = _oldY;
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


