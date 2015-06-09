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

DoubleBuffer::~DoubleBuffer()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code





void DoubleBuffer::bufferizeIndice(float indice)
{
	// Start of user code bufferizeIndice
    int size = indiceBuffer->getData()->size()/36;
    indiceBuffer->getData()->push_back(indice);//size*8+indice);
	// End of user code
}
void DoubleBuffer::bufferizeVertex(float x, float y, float z, float type, float ao)
{
	// Start of user code bufferizeVertex
    getVertexBuffer()->getData()->push_back(x);
    getVertexBuffer()->getData()->push_back(y);
    getVertexBuffer()->getData()->push_back(z);
    getVertexBuffer()->getData()->push_back(ao);
    
    // End of user code
}
void DoubleBuffer::bufferizeSquare(float x1, float y1, float z1, float x2, float y2, float z2, float type, float* ao)
{
	// Start of user code bufferizeSquare
    if(x1==x2)
    {
        bufferizeVertex(x1, y1, z1, type, ao[0]);
        bufferizeVertex(x1, y1, z2, type, ao[1]);
        bufferizeVertex(x1, y2, z1, type, ao[2]);
        bufferizeVertex(x1, y2, z2, type, ao[3]);
    }
    else if(y1==y2)
    {
        bufferizeBaseVertex(x1, y1, z1, ao[0]);
        bufferizeBaseVertex(x1, y1, z2, ao[1]);
        bufferizeBaseVertex(x2, y1, z1, ao[2]);
        bufferizeBaseVertex(x2, y1, z2, ao[3]);
    }
    else if(z1==z2)
    {
        bufferizeVertex(x1, y1, z1, type, ao[0]);
        bufferizeVertex(x1, y2, z1, type, ao[1]);
        bufferizeVertex(x2, y1, z1, type, ao[2]);
        bufferizeVertex(x2, y2, z1, type, ao[3]);
    }
	// End of user code
}
void DoubleBuffer::bufferizeBaseVertex(float x, float y, float z, float ao)
{
	// Start of user code bufferizeBaseVertex
    vertexBuffer->getBase()->push_back(x);
    vertexBuffer->getBase()->push_back(y);
    vertexBuffer->getBase()->push_back(z);
    vertexBuffer->getBase()->push_back(ao);
	// End of user code
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
					
