#include <cstdlib>

#include "VBO.h"
// Start of user code includes
// End of user code

VBO::VBO(unsigned int _size)
{
	size = _size;
}

VBO::VBO()
{
	// Start of user code constructor
	// End of user code
}

// Start of user code methods
// End of user code



unsigned int VBO::getSize()
{
	return size;
}

void VBO::setSize(unsigned int _size)
{
	size = _size;
}


vector<Attribute*> VBO::getAttributes()
{
	// Start of user code getAttributes
	// End of user code
	return attributes;
}

