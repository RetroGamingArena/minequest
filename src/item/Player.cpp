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
    x=(World::size)*Chunk::subsize*Chunk::size+128;
    y=Chunk::size*Chunk::subsize;
    z=(World::size)*Chunk::subsize*Chunk::size+128;
    
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
        dy += -3.0*g*dt*dt*Chunk::subsize;
    }
    return tryMove();
	// End of user code
}
void Player::draw(VertexBuffer * buffer)
{
	// Start of user code draw
    
    /*
     
     int pInt = (int)p;
     double pDecimal = p-pInt;
     
     int qInt = (int)q;
     double qDecimal = q-qInt;
     
     int rInt = (int)r;
     double rDecimal = r-rInt;
     
     vector<GLuint>* data = vertexBuffer->getData();
     
     unsigned int _offset =  (   (int)(pDecimal / 0.0625) + (int)((pInt%8) << 4) + ((pInt/8) << 7) +
     (((int)(qDecimal / 0.0625) + (int)((qInt%8) << 4) + ((qInt/8) << 7)) << 10) +
     ( (( (int)(rDecimal / 0.0625) + (int)((rInt%8) << 4) + ((rInt/8) << 7) )) << 20) );
     
     data->push_back(_offset);
     
     unsigned int size = (type << 20) + (occlusion << 18) + ((widthP-1) << 12) + ((widthQ-1) << 6) + (widthR-1);
     
     data->push_back(size);
     return;
    
    */
    
    int pInt = (int)(x/Chunk::subsize);
    double pDecimal = (x/Chunk::subsize)-pInt;
    
    int qInt = (int)(y/Chunk::subsize);
    double qDecimal = (y/Chunk::subsize)-qInt;
    
    int rInt = (int)(z/Chunk::subsize);
    double rDecimal = (z/Chunk::subsize)-rInt;
    
    
    unsigned int _offset =  (   (int)(pDecimal / 0.0625) + (int)((pInt%16) << 4) + ((pInt/16) << 8) +
                             (((int)(qDecimal / 0.0625) + (int)((qInt%16) << 4) + ((qInt/16) << 8)) << 10) +
                             ( (( (int)(rDecimal / 0.0625) + (int)((rInt%16) << 4) + ((rInt/16) << 8) )) << 20) );
    
    buffer->getData()->push_back(_offset);
    
    buffer->getData()->push_back( (4 << 11) + (1 << 9) + (16-1));
    
    pInt = (int)(x/Chunk::subsize);
    pDecimal = (x/Chunk::subsize)-pInt;
    
    qInt = (int)(1+y/Chunk::subsize);
    qDecimal = (1+y/Chunk::subsize)-qInt;
    
    rInt = (int)(z/Chunk::subsize);
    rDecimal = (z/Chunk::subsize)-rInt;
    
    _offset =  (   (int)(pDecimal / 0.0625) + (int)((pInt%16) << 4) + ((pInt/16) << 8) +
                             (((int)(qDecimal / 0.0625) + (int)((qInt%16) << 4) + ((qInt/16) << 8)) << 10) +
                             ( (( (int)(rDecimal / 0.0625) + (int)((rInt%16) << 4) + ((rInt/16) << 8) )) << 20) );
    
    buffer->getData()->push_back(_offset);
    
    buffer->getData()->push_back( (4 << 11) + (1 << 9) + (16-1));
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



