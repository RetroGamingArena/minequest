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
// End of user code



int Control::getX()
{
	return x;
}

void Control::setX(int _x)
{
	x = _x;
}
int Control::getY()
{
	return y;
}

void Control::setY(int _y)
{
	y = _y;
}


