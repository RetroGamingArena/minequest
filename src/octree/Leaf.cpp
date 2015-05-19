#include <cstdlib>

#include "Leaf.h"
// Start of user code includes
#include "Chunk.h"
#include "Engine.h"
#include "World.h"
// End of user code

Leaf::Leaf(unsigned char _type)
{
	type = _type;
}

Leaf::Leaf()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

Leaf::~Leaf()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code

bool Leaf::isCompressible()
{
	// Start of user code isCompressible
    return false;
	// End of user code
}
int Leaf::getCode()
{
	// Start of user code getCode
    return type;
	// End of user code
}
unsigned char Leaf::getAbs(int x, int y, int z, int size)
{
	// Start of user code getAbs
    return type;
	// End of user code
}
void Leaf::bufferize(VertexBuffer * vertexBuffer, float p, float q, float r, float size)
{
	// Start of user code bufferize
    World* world = Engine::getInstance()->getWorld();
    
    if(getType() > 0)
    {
        if(world->isCubeVisible(p,q,r,size))
        {
            world->bufferizeEntry(vertexBuffer, getType(), p/Chunk::subsize, q/Chunk::subsize, r/Chunk::subsize, size);
        }
    }
	// End of user code
}



unsigned char Leaf::getType()
{
	// Start of user code getType
	// End of user code
	return type;
}

void Leaf::setType(unsigned char _type)
{
	type = _type;
}



