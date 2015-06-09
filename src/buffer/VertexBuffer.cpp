#include <cstdlib>

#include "VertexBuffer.h"
// Start of user code includes
// End of user code

VertexBuffer::VertexBuffer(vector<GLfloat>* _data, vector<GLfloat>* _base)
{
	data = _data;
	base = _base;
}

VertexBuffer::VertexBuffer()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    data = new vector<GLfloat>();
    base = new vector<GLfloat>();
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data->size(), &(*data)[0], GL_STREAM_DRAW);
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
	// End of user code
}



vector<GLfloat>* VertexBuffer::getData()
{
	// Start of user code getData
	// End of user code
	return data;
}


vector<GLfloat>* VertexBuffer::getBase()
{
	// Start of user code getBase
	// End of user code
	return base;
}



void VertexBuffer::init()
{
	// Start of user code init
    Buffer::init();
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(unsigned int)*data->size(), &(*data)[0], GL_STREAM_DRAW);
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
	// End of user code
}

