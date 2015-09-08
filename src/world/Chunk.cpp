#include <cstdlib>

#include "Chunk.h"
// Start of user code includes
#include "Cube.h"
// End of user code

Chunk::Chunk(float _p, float _q, float _r, int _size, int _subsize, bool _buffered, bool _generated, bool _generating, bool _buffering)
{
	p = _p;
	q = _q;
	r = _r;
	size = _size;
	subsize = _subsize;
	buffered = _buffered;
	generated = _generated;
	generating = _generating;
	buffering = _buffering;
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
    
    this->octree = new Octree<Voxel*>();
    Octree<Voxel*>::size = Chunk::size*Chunk::subsize;
    Octree<Voxel*>::subSize = Chunk::subsize;
    
    octree->setP(p);
    octree->setQ(q);
    octree->setR(r);
    
    buffered = false;
    generated = false;
    
    buffering = false;
    generating = false;
}
// End of user code



int Chunk::size = 16;
int Chunk::subsize = 16;	

float Chunk::getP()
{
	// Start of user code getP
	// End of user code
	return p;
}

void Chunk::setP(float _p)
{
	p = _p;
}

float Chunk::getQ()
{
	// Start of user code getQ
	// End of user code
	return q;
}

void Chunk::setQ(float _q)
{
	q = _q;
}

float Chunk::getR()
{
	// Start of user code getR
	// End of user code
	return r;
}

void Chunk::setR(float _r)
{
	r = _r;
}

bool Chunk::getBuffered()
{
	// Start of user code getBuffered
	// End of user code
	return buffered;
}

void Chunk::setBuffered(bool _buffered)
{
	buffered = _buffered;
}

bool Chunk::getGenerated()
{
	// Start of user code getGenerated
	// End of user code
	return generated;
}

void Chunk::setGenerated(bool _generated)
{
	generated = _generated;
}

bool Chunk::getGenerating()
{
	// Start of user code getGenerating
	// End of user code
	return generating;
}

void Chunk::setGenerating(bool _generating)
{
	generating = _generating;
}

bool Chunk::getBuffering()
{
	// Start of user code getBuffering
	// End of user code
	return buffering;
}

void Chunk::setBuffering(bool _buffering)
{
	buffering = _buffering;
}


//void Chunk::generate(WorldGenerator * worldGenerator)
//{
	// Start of user code generate
    //float pp = p * Chunk::size * Chunk::subsize * Cube::size;
    //float rr = r * Chunk::size * Chunk::subsize * Cube::size;
    
    //unsigned char type = 0;
    
    //octree->generate(worldGenerator, p*Chunk::size * Chunk::subsize, q, r*Chunk::size * Chunk::subsize, size*subsize);
	// End of user code
//}
void Chunk::bufferize()
{
	// Start of user code bufferize
    //octree->bufferize(vertexBuffer, 0, 0, 0);
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
					
Octree<Voxel*>* Chunk::getOctree()
{
	// Start of user code getOctree
	// End of user code
	return octree;
}

void Chunk::setOctree(Octree<Voxel*>* _octree)
{
	octree = _octree;
}
					
