#include <cstdlib>

#include "Item.h"
// Start of user code includes
// End of user code

Item::Item(float _x, float _y, float _z, float _lx, float _ly, float _lz)
{
	x = _x;
	y = _y;
	z = _z;
	lx = _lx;
	ly = _ly;
	lz = _lz;
}

Item::Item()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}


// Start of user code methods
// End of user code




float Item::getX()
{
	// Start of user code getX
	// End of user code
	return x;
}

void Item::setX(float _x)
{
	x = _x;
}

float Item::getY()
{
	// Start of user code getY
	// End of user code
	return y;
}

void Item::setY(float _y)
{
	y = _y;
}

float Item::getZ()
{
	// Start of user code getZ
	// End of user code
	return z;
}

void Item::setZ(float _z)
{
	z = _z;
}

float Item::getLx()
{
	// Start of user code getLx
	// End of user code
	return lx;
}

void Item::setLx(float _lx)
{
	lx = _lx;
}

float Item::getLy()
{
	// Start of user code getLy
	// End of user code
	return ly;
}

void Item::setLy(float _ly)
{
	ly = _ly;
}

float Item::getLz()
{
	// Start of user code getLz
	// End of user code
	return lz;
}

void Item::setLz(float _lz)
{
	lz = _lz;
}


void Item::live(double dt)
{
	// Start of user code live
	// End of user code
}
glm::vec3 Item::getPosition()
{
	// Start of user code getPosition
    return glm::vec3(x, y, z);
	// End of user code
}
glm::vec3 Item::getLook()
{
	// Start of user code getLook
    return glm::vec3(lx, ly, lz);
	// End of user code
}

