#include <cstdlib>

#include "Player.h"
// Start of user code includes
#include "Chunk.h"
// End of user code

Player::Player(bool _falling)
{
	falling = _falling;
}

Player::Player()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    x=0;
    y=8*Chunk::subsize;
    z=0;
    
    lx=0;
	ly=0;
    lz=0;
    
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
    
    buffer->getData()->push_back(4);
    
    buffer->getData()->push_back(16);
    buffer->getData()->push_back(16);
    buffer->getData()->push_back(16);
    
    buffer->getData()->push_back(0.6);
    
    buffer->getData()->push_back(x/Chunk::subsize);
    buffer->getData()->push_back(y/Chunk::subsize+1);
    buffer->getData()->push_back(z/Chunk::subsize);
    
    buffer->getData()->push_back(4);
    
    buffer->getData()->push_back(16);
    buffer->getData()->push_back(16);
    buffer->getData()->push_back(16);
    
    buffer->getData()->push_back(0.6);
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



