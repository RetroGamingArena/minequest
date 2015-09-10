#include <cstdlib>

#include "ItemCamera.h"
// Start of user code includes
#include "Chunk.h"
#include "Engine.h"
#include <iostream>
// End of user code


ItemCamera::ItemCamera()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    angleZ = PI;//3*PI/2;
    //angleY = PI;
	// End of user code
}

ItemCamera::~ItemCamera()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code

void ItemCamera::onMouseMotion(double xpos, double ypos)
{
	// Start of user code onMouseMotion
    if(oldX == -1 && oldY == -1)
    {
        oldX = 960;
        oldY = 540;
    }
    //if(oldX >= 0 && oldY >= 0)
    else
    {
        double dx = (xpos-oldX)/100;
        
        double dy = (ypos-oldY)/100;

        angleZ += dx;
        angleY += dy;
        if(dy<0)
            angleY = max(PI/2.0,(double)angleY);
        else
            angleY = min(3*PI/2.0,(double)angleY);
        
        std::cout << angleY << std::endl;
        
        if(abs(oldX-960) > 100)
        {
            glfwSetCursorPos(Engine::getInstance()->getWindow(), 960, ypos);
            oldX = 960;
        }
        else
            oldX = xpos;
        if(abs(oldY-540) > 100)
        {
            glfwSetCursorPos(Engine::getInstance()->getWindow(), xpos, 540);
            oldY = 540;
        }
        else
            oldY = ypos;
        handle(events[0]);
    }
    // End of user code
}
void ItemCamera::onMouseButton(int button, int action)
{
	// Start of user code onMouseButton
	// End of user code
}
void ItemCamera::onKeyboard(int key, int scancode, int action, int mods)
{
	// Start of user code onKeyboard
	// End of user code
}
void ItemCamera::onMouseWheel(double xoffset, double yoffset)
{
	// Start of user code onMouseWheel
	// End of user code
}




glm::vec3 ItemCamera::getPosition()
{
	// Start of user code getPosition
    return InputCamera::getPosition();
	// End of user code
}
glm::vec3 ItemCamera::getCenter()
{
	// Start of user code getCenter
    return InputCamera::getCenter();
	// End of user code
}

void ItemCamera::handle(Event * event)
{
    position = item->getPosition();
    position /= Chunk::subsize;
    position.y += 2;
    position.x += 0.5 + cos(angleZ)*3;
    position.z += 0.5 + sin(angleZ)*3;
    
    center = item->getPosition();//item->getLook();
    center /= Chunk::subsize;
    center.y += 2 + sin(angleY+PI);
    center.x = (item->getPosition().x / Chunk::subsize) + 0.5 + cos(angleZ+PI)*cos(angleY+PI);
    center.z = (item->getPosition().z / Chunk::subsize) + 0.5 + sin(angleZ+PI)*cos(angleY+PI);
    
    fireEvent(events[0]);
}

Item* ItemCamera::getItem()
{
	// Start of user code getItem
	// End of user code
	return item;
}

void ItemCamera::setItem(Item* _item)
{
	item = _item;
    item->addListener(this);
}
					
