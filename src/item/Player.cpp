#include <cstdlib>

#include "Player.h"
// Start of user code includes
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
    y=8;
    z=0;
    
    lx=0;
	ly=0;
    lz=0;
    // End of user code
}

Player::~Player()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code

void Player::draw(VertexBuffer * buffer)
{
	// Start of user code draw
    buffer->getData()->push_back(x);
    buffer->getData()->push_back(y);
    buffer->getData()->push_back(z);
    
    buffer->getData()->push_back(4);
    
    buffer->getData()->push_back(16);
    buffer->getData()->push_back(16);
    buffer->getData()->push_back(16);
    
    buffer->getData()->push_back(0.6);
    
    buffer->getData()->push_back(x);
    buffer->getData()->push_back(y+1);
    buffer->getData()->push_back(z);
    
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



