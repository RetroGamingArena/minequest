#include <cstdlib>

#include "VBO.h"
// Start of user code includes
// End of user code

VBO::VBO(unsigned int _headerSize, unsigned int _instanceSize)
{
	headerSize = _headerSize;
	instanceSize = _instanceSize;
}

VBO::VBO()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

VBO::~VBO()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code




unsigned int VBO::getHeaderSize()
{
	// Start of user code getHeaderSize
	// End of user code
	return headerSize;
}

void VBO::setHeaderSize(unsigned int _headerSize)
{
	headerSize = _headerSize;
}

unsigned int VBO::getInstanceSize()
{
	// Start of user code getInstanceSize
	// End of user code
	return instanceSize;
}

void VBO::setInstanceSize(unsigned int _instanceSize)
{
	instanceSize = _instanceSize;
}



vector<Attribute*> VBO::getAttributes()
{
	// Start of user code getAttributes
	// End of user code
	return attributes;
}

void VBO::setAttributesAt(Attribute* _attributes, int indice)
{
	attributes[indice] = _attributes;
}

