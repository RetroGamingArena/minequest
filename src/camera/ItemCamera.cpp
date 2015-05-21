#include <cstdlib>

#include "ItemCamera.h"
// Start of user code includes
// End of user code


ItemCamera::ItemCamera()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    
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
	// End of user code
}
void ItemCamera::onKeyboard(int key, int scancode, int action, int mods)
{
	// Start of user code onKeyboard
	// End of user code
}
void ItemCamera::onMouseButton(int button, int action)
{
	// Start of user code onMouseButton
	// End of user code
}
void ItemCamera::onMouseWheel(double xoffset, double yoffset)
{
	// Start of user code onMouseWheel
	// End of user code
}
glm::vec3 ItemCamera::getRealPosition()
{
	// Start of user code getRealPosition
    glm::vec3 position = item->getPosition();
    position.y+=2;
    return position;
	// End of user code
}
glm::vec3 ItemCamera::getRealCenter()
{
	// Start of user code getRealCenter
    glm::vec3 look = item->getLook();
    look.y+=2;
    return look;
	// End of user code
}
glm::vec3 ItemCamera::getRealUp()
{
	// Start of user code getRealUp
    return glm::vec3(0,1,0);
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
					
