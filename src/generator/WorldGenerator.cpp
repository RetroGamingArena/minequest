#include <cstdlib>

#include "WorldGenerator.h"
// Start of user code includes
#include "Leaf.h"
#include "Chunk.h"
// End of user code

WorldGenerator::WorldGenerator(vector<int>* _xs, vector<int>* _ys, vector<int>* _zs)
{
	xs = _xs;
	ys = _ys;
	zs = _zs;
}

WorldGenerator::WorldGenerator()
// Start of user code super class
// End of user code
{
	// Start of user code constructor    
    for(int i =0; i < 8; i++)
    {
        xs->push_back((i%4)&1);
        ys->push_back(i >> 2);
        zs->push_back((i%4) >> 1);
    }
	// End of user code
}


// Start of user code methods
// End of user code



vector<int>* WorldGenerator::xs = new vector<int>();	
vector<int>* WorldGenerator::ys = new vector<int>();	
vector<int>* WorldGenerator::zs = new vector<int>();	

vector<int>* WorldGenerator::getXs()
{
	// Start of user code getXs
	// End of user code
	return xs;
}


vector<int>* WorldGenerator::getYs()
{
	// Start of user code getYs
	// End of user code
	return ys;
}


vector<int>* WorldGenerator::getZs()
{
	// Start of user code getZs
	// End of user code
	return zs;
}



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
        int x = (*xs)[i];
        int y = (*ys)[i];
        int z = (*zs)[i];
        
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
    unsigned char type = 0;
    
    bool isCompressible = true;
    
    int x = 0;
    int y = 0;
    int z = 0;
    
    OctreeEntry* octreeEntry= NULL;
    Leaf* leaf = NULL;
    
    for(int i =0; i < 8; i++)
    {
        x = (*xs)[i];
        y = (*ys)[i];
        z = (*zs)[i];
        
        if(size==2)
        {
            octreeEntry = new Leaf(getCubeType(p+x, q+y, r+z));
            //node->setOctreeEntriesAt(new Leaf(getCubeType(p+x, q+y, r+z)), i);
        }
        else
        {
            octreeEntry = generateOctreeEntry(p+x*size/2, q+y*size/2, r+z*size/2, size/2);
            //node->setOctreeEntriesAt(generateOctreeEntry(p+x*size/2, q+y*size/2, r+z*size/2, size/2), i);
        }
        
        if(isCompressible)
        {
            leaf = dynamic_cast<Leaf*>(octreeEntry);
            if(leaf == NULL)
            {
                isCompressible = false;
            }
            else
            {
                if(i == 0)
                {
                    type = leaf->getType();
                }
                else if(leaf->getType() != type)
                {
                    isCompressible = false;
                }
            }
        }
        
        node->setOctreeEntriesAt(octreeEntry, i);
    }
    if(isCompressible)
    {
        delete node;
        return new Leaf(type);
    }
    else
        return node;
    //compression
    /*Leaf** leaves = new Leaf*[8];
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
    return node;*/
	// End of user code
}

