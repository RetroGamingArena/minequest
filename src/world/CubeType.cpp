#include <cstdlib>

#include "CubeType.h"
// Start of user code includes
#include "Chunk.h"
// End of user code


CubeType::CubeType()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

// Start of user code methods
// End of user code





unsigned char CubeType::getTypeFromHeight(int height)
{
	// Start of user code getTypeFromHeight
    unsigned char type;
    if(height<16*Chunk::size*Chunk::subsize/32)
        type = 2; //dirt
    else if(height<18*Chunk::size*Chunk::subsize/32)
        type = 3; //sand
    else if(height<20*Chunk::size*Chunk::subsize/32)
        type = 1; //grass
    else if(height<25*Chunk::size*Chunk::subsize/32)
        type = 4; //dirt
    else if(height<28*Chunk::size*Chunk::subsize/32)
        type = 5; //rock
    else
        type = 6; //snow
    return type;
	// End of user code
}

