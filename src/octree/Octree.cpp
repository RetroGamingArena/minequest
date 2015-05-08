#include <cstdlib>

#include "Octree.h"
// Start of user code includes
// End of user code


Octree::Octree()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

// Start of user code methods
// End of user code





void Octree::bufferize(VertexBuffer * vertexBuffer, float p, float q, float r)
{
	// Start of user code bufferize
    for(int i = 0; i < 8; i++)
    {
        int x = (i%4)%2;
        int y = i/4;
        int z = (i%4)/2;
        
        //bufferize(scene, this->entries[i], p+x*size/2.0, q+y*size/2.0, r+z*size/2.0, size/2.0);
        if(this->octreeEntries[i] != NULL)
            this->octreeEntries[i]->bufferize(buffer, this->p*size+x*size/2.0, this->q*size+y*size/2.0, this->r*size+z*size/2.0, size/2.0);
    }
	// End of user code
}

