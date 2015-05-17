#include <cstdlib>

#include "WorldGenerator.h"
// Start of user code includes
#include "Leaf.h"
#include "Chunk.h"
// End of user code


WorldGenerator::WorldGenerator()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}


// Start of user code methods
// End of user code





Octree* WorldGenerator::generate(int p, int q, int r)
{
	// Start of user code generate
    Octree* octree = new Octree();
    octree->setP(p);
    octree->setQ(q);
    octree->setR(r);
    int size = Chunk::size*Chunk::subsize;
    for(int i =0; i < 8; i++)
    {
        int x = (i%4)&1;
        int y = i >> 2;
        int z = (i%4) >> 1;
        
        octree->setOctreeEntriesAt(generateOctreeEntry(p*size+x*size/2, q*size+y*size/2, r*size+z*size/2, size/2), i);
    }
    //delete octree;
    return octree;
	// End of user code
}
OctreeEntry* WorldGenerator::generateOctreeEntry(int p, int q, int r, int size)
{
	// Start of user code generateOctreeEntry
    Node* node = new Node();
    for(int i =0; i < 8; i++)
    {
        int x = (i%4)&1;
        int y = i >> 2;
        int z = (i%4) >> 1;
        
        if(size==2)
        {
            node->setOctreeEntriesAt(new Leaf(getCubeType(p+x, q+y, r+z)), i);
        }
        else
        {
            node->setOctreeEntriesAt(generateOctreeEntry(p+x*size/2, q+y*size/2, r+z*size/2, size/2), i);
        }
    }
    //compression
    Leaf** leaves = new Leaf*[8];
    unsigned char type;
    for(int ii = 7; ii >= 0; ii--)
    {
        leaves[ii] = dynamic_cast<Leaf*>(node->getOctreeEntries()[ii]);
        if(leaves[ii] == NULL)
            return node;
        if(ii==7)
            type = leaves[ii]->getType();
        else
            if(leaves[ii]->getType() != type)
                return node;
    }
    delete node;
    for(int ii = 7; ii >= 0; ii--)
        leaves[ii] = NULL;
    delete[] leaves;
    return new Leaf(type);
    return node;
	// End of user code
}

