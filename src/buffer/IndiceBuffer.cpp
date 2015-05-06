#include <cstdlib>

#include "IndiceBuffer.h"
// Start of user code includes
// End of user code

IndiceBuffer::IndiceBuffer(vector<unsigned int> _data)
{
	data = _data;
}

IndiceBuffer::IndiceBuffer()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    Buffer::Buffer();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*data.size(), &data[0] , GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	// End of user code
}

// Start of user code methods
// End of user code




vector<unsigned int> IndiceBuffer::getData()
{
	return data;
}



