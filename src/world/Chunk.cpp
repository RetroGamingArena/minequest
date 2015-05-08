#include <cstdlib>

#include "Chunk.h"
// Start of user code includes
#include "Cube.h"
// End of user code

Chunk::Chunk(float _p, float _q, float _r, int _size, int _subsize)
{
	p = _p;
	q = _q;
	r = _r;
	size = _size;
	subsize = _subsize;
}

Chunk::Chunk()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

Chunk::~Chunk()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
Chunk::Chunk(float _p, float _q, float _r)
{
    this->vertexBuffer = new VertexBuffer();
    
    this->p=_p;
    this->q=_q;
    this->r=_r;
    
    this->octree = new Octree();
    Octree::size = Chunk::size*Chunk::subsize;
    Octree::subSize = Chunk::subsize;
    
    octree->setP(p);
    octree->setQ(q);
    octree->setR(r);
}
// End of user code



int Chunk::size = 16;	
int Chunk::subsize = 16;	

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

void Chunk::generate(WorldGenerator * worldGenerator)
{
	// Start of user code generate
    float pp = p * Chunk::size * Chunk::subsize * Cube::size;
    float rr = r * Chunk::size * Chunk::subsize * Cube::size;
    
    unsigned char type = 0;
    
    octree->generate(worldGenerator, p*Chunk::size * Chunk::subsize, q, r*Chunk::size * Chunk::subsize, size*subsize);
	// End of user code
}
void Chunk::bufferize()
{
	// Start of user code bufferize
    octree->bufferize(vertexBuffer, 0, 0, 0);
	// End of user code
}

VertexBuffer* Chunk::getVertexBuffer()
{
	// Start of user code getVertexBuffer
	// End of user code
	return vertexBuffer;
}

void Chunk::setVertexBuffer(VertexBuffer* _vertexBuffer)
{
	vertexBuffer = _vertexBuffer;
}
					
Octree* Chunk::getOctree()
{
	// Start of user code getOctree
	// End of user code
	return octree;
}

void Chunk::setOctree(Octree* _octree)
{
	octree = _octree;
}
					
