#include <cstdlib>

#include "Control.h"
// Start of user code includes
// End of user code

Control::Control(int _x, int _y)
{
	x = _x;
	y = _y;
}

Control::Control()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}


// Start of user code methods
int Control::pixelSize = 2;

void Control::drawRect(std::vector<glm::vec2> &vertices, std::vector<glm::vec2> &UVs, int x, int y, int w, int h)
{
    vertices.push_back(glm::vec2(x*pixelSize, y*pixelSize));
    vertices.push_back(glm::vec2(x*pixelSize, (y-h)*pixelSize));
    vertices.push_back(glm::vec2((x+w)*pixelSize, y*pixelSize));
    
    vertices.push_back(glm::vec2((x+w)*pixelSize, (y-h)*pixelSize));
    vertices.push_back(glm::vec2((x+w)*pixelSize, y*pixelSize));
    vertices.push_back(glm::vec2(x*pixelSize, (y-h)*pixelSize));
    
    UVs.push_back(glm::vec2(-1, -1));
    UVs.push_back(glm::vec2(-1, -1));
    UVs.push_back(glm::vec2(-1, -1));
    
    UVs.push_back(glm::vec2(-1, -1));
    UVs.push_back(glm::vec2(-1, -1));
    UVs.push_back(glm::vec2(-1, -1));
}

// End of user code


int Control::getX()
{
	// Start of user code getX
	// End of user code
	return x;
}

void Control::setX(int _x)
{
	x = _x;
}

int Control::getY()
{
	// Start of user code getY
	// End of user code
	return y;
}

void Control::setY(int _y)
{
	y = _y;
}



