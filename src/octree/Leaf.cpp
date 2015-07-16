#include <cstdlib>

#include "Leaf.h"
// Start of user code includes
#include "Chunk.h"
#include "Engine.h"
#include "World.h"
// End of user code

Leaf::Leaf(unsigned char _type, unsigned char _occlusion)
{
	type = _type;
	occlusion = _occlusion;
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
        if(!world->isCubeInFrustum(p/Chunk::subsize,q/Chunk::subsize,r/Chunk::subsize,(p+size)/Chunk::subsize,(q+size)/Chunk::subsize,(r+size)/Chunk::subsize))
            return;
        
        if(world->isCubeVisible(p,q,r,size))
        {
            world->bufferizeEntry(vertexBuffer, getType(), p/Chunk::subsize, q/Chunk::subsize, r/Chunk::subsize, size, size, size, occlusion);
            world->setOccludedCount(world->getOccludedCount()+1);
        }
        else
            world->setInstanceCount(world->getInstanceCount()+1);
        world->setCubeCount(world->getCubeCount()+size*size*size);
    }
	// End of user code
}
OctreeEntry* Leaf::getLeafAbs(int x, int y, int z, int size)
{
	// Start of user code getLeafAbs
    return this;
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

unsigned char Leaf::getOcclusion()
{
	// Start of user code getOcclusion
	// End of user code
	return occlusion;
}

void Leaf::setOcclusion(unsigned char _occlusion)
{
	occlusion = _occlusion;
}



