#include <cstdlib>

#include "DoubleBuffer.h"
// Start of user code includes
// End of user code


DoubleBuffer::DoubleBuffer()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    vertexBuffer = new VertexBuffer();
    indiceBuffer = new IndiceBuffer();
	// End of user code
}

// Start of user code methods
// End of user code






VBO* DoubleBuffer::getVBO()
{
	// Start of user code getVBO
	// End of user code
	return vBO;
}

void DoubleBuffer::setVBO(VBO* _vBO)
{
	vBO = _vBO;
}
					
IndiceBuffer* DoubleBuffer::getIndiceBuffer()
{
	// Start of user code getIndiceBuffer
	// End of user code
	return indiceBuffer;
}

void DoubleBuffer::setIndiceBuffer(IndiceBuffer* _indiceBuffer)
{
	indiceBuffer = _indiceBuffer;
}
					
VertexBuffer* DoubleBuffer::getVertexBuffer()
{
	// Start of user code getVertexBuffer
	// End of user code
	return vertexBuffer;
}

void DoubleBuffer::setVertexBuffer(VertexBuffer* _vertexBuffer)
{
	vertexBuffer = _vertexBuffer;
}
					
