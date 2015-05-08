#include <cstdlib>

#include "Buffer.h"
// Start of user code includes
// End of user code

Buffer::Buffer(GLuint _id)
{
	id = _id;
}

Buffer::Buffer()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

Buffer::~Buffer()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code




GLuint Buffer::getId()
{
	// Start of user code getId
	// End of user code
	return id;
}

void Buffer::setId(GLuint _id)
{
	id = _id;
}

void Buffer::init()
{
	// Start of user code init
    glGenBuffers(1, &id);
	// End of user code
}

