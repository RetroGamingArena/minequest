#include <cstdlib>

#include "Empty.h"
// Start of user code includes
// End of user code

Empty::Empty(float _x, float _y, float _z, int _size)
{
	x = _x;
	y = _y;
	z = _z;
	size = _size;
}

Empty::Empty()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

Empty::~Empty()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code

bool Empty::isCompressible()
{
	// Start of user code isCompressible
    return false;
	// End of user code
}
int Empty::getCode()
{
	// Start of user code getCode
    return 0;
	// End of user code
}
unsigned char Empty::getAbs(int x, int y, int z, int size)
{
	// Start of user code getAbs
    return 0;
	// End of user code
}
void Empty::bufferize(VertexBuffer * vertexBuffer, float p, float q, float r, float size)
{
	// Start of user code bufferize
	// End of user code
}
OctreeEntry* Empty::getLeafAbs(int x, int y, int z, int size)
{
	// Start of user code getLeafAbs
    return this;
	// End of user code
}



float Empty::getX()
{
	// Start of user code getX
	// End of user code
	return x;
}

void Empty::setX(float _x)
{
	x = _x;
}

float Empty::getY()
{
	// Start of user code getY
	// End of user code
	return y;
}

void Empty::setY(float _y)
{
	y = _y;
}

float Empty::getZ()
{
	// Start of user code getZ
	// End of user code
	return z;
}

void Empty::setZ(float _z)
{
	z = _z;
}

int Empty::getSize()
{
	// Start of user code getSize
	// End of user code
	return size;
}

void Empty::setSize(int _size)
{
	size = _size;
}



