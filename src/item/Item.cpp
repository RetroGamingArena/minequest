#include <cstdlib>

#include "Item.h"
// Start of user code includes
#include "Engine.h"
// End of user code

Item::Item(float _x, float _y, float _z, float _lx, float _ly, float _lz, float _dx, float _dy, float _dz, float _weight, float _g)
{
	x = _x;
	y = _y;
	z = _z;
	lx = _lx;
	ly = _ly;
	lz = _lz;
	dx = _dx;
	dy = _dy;
	dz = _dz;
	weight = _weight;
	g = _g;
}

Item::Item()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    dx = 0;
    dy = 0;
    dz = 0;
	// End of user code
}


// Start of user code methods
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
// End of user code



float Item::g = 9.80665;	

float Item::getX()
{
	// Start of user code getX
	// End of user code
	return x;
}

void Item::setX(float _x)
{
	x = _x;
}

float Item::getY()
{
	// Start of user code getY
	// End of user code
	return y;
}

void Item::setY(float _y)
{
	y = _y;
}

float Item::getZ()
{
	// Start of user code getZ
	// End of user code
	return z;
}

void Item::setZ(float _z)
{
	z = _z;
}

float Item::getLx()
{
	// Start of user code getLx
	// End of user code
	return lx;
}

void Item::setLx(float _lx)
{
	lx = _lx;
}

float Item::getLy()
{
	// Start of user code getLy
	// End of user code
	return ly;
}

void Item::setLy(float _ly)
{
	ly = _ly;
}

float Item::getLz()
{
	// Start of user code getLz
	// End of user code
	return lz;
}

void Item::setLz(float _lz)
{
	lz = _lz;
}

float Item::getDx()
{
	// Start of user code getDx
	// End of user code
	return dx;
}

void Item::setDx(float _dx)
{
	dx = _dx;
}

float Item::getDy()
{
	// Start of user code getDy
	// End of user code
	return dy;
}

void Item::setDy(float _dy)
{
	dy = _dy;
}

float Item::getDz()
{
	// Start of user code getDz
	// End of user code
	return dz;
}

void Item::setDz(float _dz)
{
	dz = _dz;
}

float Item::getWeight()
{
	// Start of user code getWeight
	// End of user code
	return weight;
}

void Item::setWeight(float _weight)
{
	weight = _weight;
}


glm::vec3 Item::getPosition()
{
	// Start of user code getPosition
    return glm::vec3(x, y, z);
	// End of user code
}
glm::vec3 Item::getLook()
{
	// Start of user code getLook
    return glm::vec3(lx, ly, lz);
	// End of user code
}
bool Item::tryMove()
{
	// Start of user code tryMove
    World* world = Engine::getInstance()->getWorld();
    if(dx == 0 && dy == 0 && dz == 0)
        return false;
    if(!falling)
    {
        unsigned char type = world->getCube(x, y+dy, z);
        if(type == 0)
        {
            falling = true;
        }
    }
    if(world->getCube(x+dx, y+dy, z+dz) > 0)
    {
        dx = 0;
        dy = 0;
        dz = 0;
        falling = false;
        return false;
    }
    
    if( abs(dx) >= 1 )
    {
        x += dx;
        dx = 0;
    }
    if( abs(dy) > 1 )
    {
        y += dy;
        dy = 0;
    }
    if( abs(dz) >= 1 )
    {
        z += dz;
        dz = 0;
    }
    return true;
    // End of user code
}

