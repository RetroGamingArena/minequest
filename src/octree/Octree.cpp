#include <cstdlib>

#include "Octree.h"
// Start of user code includes
#include "WorldGenerator.h"
// End of user code

Octree::Octree(float _p, float _q, float _r, int _size, int _subSize)
{
	p = _p;
	q = _q;
	r = _r;
	size = _size;
	subSize = _subSize;
}

Octree::Octree()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

Octree::~Octree()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code



int Octree::size = 0;	
int Octree::subSize = 0;	

float Octree::getP()
{
	// Start of user code getP
	// End of user code
	return p;
}

void Octree::setP(float _p)
{
	p = _p;
}

float Octree::getQ()
{
	// Start of user code getQ
	// End of user code
	return q;
}

void Octree::setQ(float _q)
{
	q = _q;
}

float Octree::getR()
{
	// Start of user code getR
	// End of user code
	return r;
}

void Octree::setR(float _r)
{
	r = _r;
}


void Octree::bufferize(VertexBuffer * vertexBuffer, float p, float q, float r)
{
	// Start of user code bufferize
    for(int i = 0; i < 8; i++)
    {
        int x = (*WorldGenerator::getXs())[i];//(i%4)%2;
        int y = (*WorldGenerator::getYs())[i];//i/4;
        int z = (*WorldGenerator::getZs())[i];//(i%4)/2;
        
        //bufferize(scene, this->entries[i], p+x*size/2.0, q+y*size/2.0, r+z*size/2.0, size/2.0);
        if(this->octreeEntries[i] != NULL)
            this->octreeEntries[i]->bufferize(vertexBuffer, this->p*size+x*size/2.0, this->q*size+y*size/2.0, this->r*size+z*size/2.0, size/2);
    }
	// End of user code
}

