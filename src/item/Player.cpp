#include <cstdlib>

#include "Player.h"
// Start of user code includes
#include "Chunk.h"
#include "Engine.h"
// End of user code

Player::Player(bool _falling, float _hRotation)
{
	falling = _falling;
	hRotation = _hRotation;
}

Player::Player()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    x=(World::size+4)*Chunk::subsize;
    y=8*Chunk::subsize;
    z=(World::size+4)*Chunk::subsize;
    
    lx=0;
    ly=1*Chunk::subsize;
    lz=1*Chunk::subsize;
    
    dx=0;
    dy=0;
    dz=0;
    // End of user code
}

Player::~Player()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code

bool Player::live(double dt)
{
	// Start of user code live
    if(falling)
    {
        dy += -0.5*g*dt*dt*Chunk::subsize;
    }
    return tryMove();
	// End of user code
}
void Player::draw(VertexBuffer * buffer)
{
	// Start of user code draw
    
    buffer->getData()->push_back(x/Chunk::subsize);
    buffer->getData()->push_back(y/Chunk::subsize);
    buffer->getData()->push_back(z/Chunk::subsize);
    
    buffer->getData()->push_back( (4 << 17) + (1 << 15) + ((16-1) << 10) + ((16-1) << 5) + (16-1));
    
    buffer->getData()->push_back(x/Chunk::subsize);
    buffer->getData()->push_back(y/Chunk::subsize+1);
    buffer->getData()->push_back(z/Chunk::subsize);
    
    buffer->getData()->push_back( (4 << 17) + (1 << 15) + ((16-1) << 10) + ((16-1) << 5) + (16-1));
	// End of user code
}



bool Player::getFalling()
{
	// Start of user code getFalling
	// End of user code
	return falling;
}

void Player::setFalling(bool _falling)
{
	falling = _falling;
}

float Player::getHRotation()
{
	// Start of user code getHRotation
	// End of user code
	return hRotation;
}

void Player::setHRotation(float _hRotation)
{
	hRotation = _hRotation;
}



