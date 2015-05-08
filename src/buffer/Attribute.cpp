#include <cstdlib>

#include "Attribute.h"
// Start of user code includes
// End of user code

Attribute::Attribute(int _size, int _divisor, const char * _name)
{
	size = _size;
	divisor = _divisor;
	name = _name;
}

Attribute::Attribute()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

Attribute::~Attribute()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code




int Attribute::getSize()
{
	// Start of user code getSize
	// End of user code
	return size;
}

void Attribute::setSize(int _size)
{
	size = _size;
}
int Attribute::getDivisor()
{
	// Start of user code getDivisor
	// End of user code
	return divisor;
}

void Attribute::setDivisor(int _divisor)
{
	divisor = _divisor;
}
const char * Attribute::getName()
{
	// Start of user code getName
	// End of user code
	return name;
}

void Attribute::setName(const char * _name)
{
	name = _name;
}


