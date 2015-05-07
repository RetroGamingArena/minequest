#include <cstdlib>

#include "Chunk.h"
// Start of user code includes
// End of user code

Chunk::Chunk(float _p, float _q, float _r)
{
	p = _p;
	q = _q;
	r = _r;
}

Chunk::Chunk()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

// Start of user code methods
// End of user code




float Chunk::getP()
{
	return p;
}

void Chunk::setP(float _p)
{
	p = _p;
}
float Chunk::getQ()
{
	return q;
}

void Chunk::setQ(float _q)
{
	q = _q;
}
float Chunk::getR()
{
	return r;
}

void Chunk::setR(float _r)
{
	r = _r;
}


