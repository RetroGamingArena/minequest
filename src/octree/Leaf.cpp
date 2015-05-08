#include <cstdlib>

#include "Leaf.h"
// Start of user code includes
#include "Chunk.h"
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

void Leaf::generate(WorldGenerator * worldGenerator, int p, int q, int r, int size)
{
	// Start of user code generate
    float height = worldGenerator->getY(p, r)*Chunk::size*Chunk::subsize/2;
    
    if( q > height )
    {
        setType(0);
        return;
    }
    
    int j = q;//height+1-size;
    //for(int j = 0; j <= height; j++)
    {
        unsigned char type;
        
        if(j<16*Chunk::size*Chunk::subsize/32)
            type = 2; //dirt
        else if(j<18*Chunk::size*Chunk::subsize/32)
            type = 3; //sand
        else if(j<20*Chunk::size*Chunk::subsize/32)
            type = 1; //grass
        else if(j<25*Chunk::size*Chunk::subsize/32)
            type = 4; //dirt
        else if(j<28*Chunk::size*Chunk::subsize/32)
            type = 5; //rock
        else
            type = 6; //snow
        setType(type);
    }
	// End of user code
}
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



unsigned char Leaf::getType()
{
	return type;
}

void Leaf::setType(unsigned char _type)
{
	type = _type;
}


