#include <cstdlib>

#include "ItemCamera.h"
// Start of user code includes
#include "Chunk.h"
// End of user code


ItemCamera::ItemCamera()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    angleZ = 3*PI/2;
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
    if(oldX >= 0 && oldY >= 0)
    {
        double dx = (xpos-oldX)/100;
        double dy = (ypos-oldY)/100;

        angleZ += dx;
        angleY -= dy;
        if(dy<0)
            angleY = max(-PI/2.0,(double)angleY);
        else
            angleY = min(PI/2.0,(double)angleY);
        fireEvent(events[0]);
        look();
    }
    oldX = xpos;
	oldY = ypos;
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
    position = item->getPosition();
    position /= Chunk::subsize;
    position.y += 2;
    position.x += 0.5 + cos(angleZ)*3;
    position.z += 0.5 + sin(angleZ)*3;
    return InputCamera::getPosition();
	// End of user code
}
glm::vec3 ItemCamera::getCenter()
{
	// Start of user code getCenter
    center = item->getPosition();//item->getLook();
    center /= Chunk::subsize;
    center.y += 2 + sin(angleY);
    center.x = (item->getPosition().x / Chunk::subsize) + 0.5 + cos(angleZ+PI)*cos(angleY);
    center.z = (item->getPosition().z / Chunk::subsize) + 0.5 + sin(angleZ+PI)*cos(angleY);
    return InputCamera::getCenter();
	// End of user code
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
}
					
