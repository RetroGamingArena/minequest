#include <cstdlib>

#include "VertexBuffer.h"
// Start of user code includes
// End of user code

VertexBuffer::VertexBuffer(vector<GLfloat>* _data)
{
	data = _data;
}

VertexBuffer::VertexBuffer()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    data = new vector<GLfloat>();
	// End of user code
}

VertexBuffer::~VertexBuffer()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code

void VertexBuffer::bind()
{
	// Start of user code bind
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*data->size(), &(*data)[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
	// End of user code
}



vector<GLfloat>* VertexBuffer::getData()
{
	// Start of user code getData
	// End of user code
	return data;
}


void VertexBuffer::init()
{
	// Start of user code init
    Buffer::init();
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*data->size(), &(*data)[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
	// End of user code
}

