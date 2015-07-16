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
    return octree;
	// End of user code
}
OctreeEntry* WorldGenerator::generateOctreeEntry(int p, int q, int r, int size)
{
	// Start of user code generateOctreeEntry
    unsigned char _type = 0;
    
    bool isCompressible = true;
    
    int x = 0;
    int y = 0;
    int z = 0;
    
    OctreeEntry* _tempOctreeEntry[8];
    for(int i = 0; i < 8; i++)
        _tempOctreeEntry[i] = NULL;
    
    int size_2 = size >> 1;
    
    //0
    if(size==2)
    {
        _type = getCubeType(p+x, q+y, r+z);
        if(_type > 0)
            _tempOctreeEntry[0] = new Leaf(_type, getOcclusion(p+x, q+y, r+z));
    }
    else
    {
        _tempOctreeEntry[0] = generateOctreeEntry(p+x*size_2, q+y*size_2, r+z*size_2, size_2);
    }

    for(int i =1; i < 8; i++)
    {
        x = (*xs)[i];
        y = (*ys)[i];
        z = (*zs)[i];
        
        if(size==2)
        {            
            _type = getCubeType(p+x, q+y, r+z);
            if(_type > 0)
                _tempOctreeEntry[i] = new Leaf(_type, getOcclusion(p+x, q+y, r+z));
        }
        else
        {
            _tempOctreeEntry[i] = generateOctreeEntry(p+x*size_2, q+y*size_2, r+z*size_2, size_2);
        }

        if(isCompressible)
        {
            if( (_tempOctreeEntry[i] == NULL && _tempOctreeEntry[i-1]!=NULL) || (_tempOctreeEntry[i] != NULL && _tempOctreeEntry[i-1] == NULL) )
                isCompressible = false;
            else if(_tempOctreeEntry[i-1]!=NULL && _tempOctreeEntry[i]!=NULL)
            {
                Leaf* leaf1 = dynamic_cast<Leaf*>(_tempOctreeEntry[i]);
                Leaf* leaf2 = dynamic_cast<Leaf*>(_tempOctreeEntry[i-1]);
                
                if(leaf1==NULL || leaf2==NULL)
                    isCompressible=false;
                else if(leaf1->getType() != leaf2->getType() || leaf1->getOcclusion() != leaf2->getOcclusion())
                    isCompressible = false;
            }
        }
    }

    if(isCompressible)
    {
        OctreeEntry* res = _tempOctreeEntry[0];
        for(int i =1; i < 8; i++)
            delete _tempOctreeEntry[i];
        return res;
    }
    else
    {
        Node* node = new Node();
        for(int i =0; i < 8; i++)
            node->setOctreeEntriesAt(_tempOctreeEntry[i], i);
        return node;
    }
    return NULL;
    // End of user code
}
unsigned char WorldGenerator::getOcclusion(int x, int y, int z)
{
	// Start of user code getOcclusion
    float ao = 0;
    if( getCubeType(x-1, y+1, z) > 0 )
        ao += 1;
    if( getCubeType(x, y+1, z-1) > 0 )
        ao += 1;
    if( getCubeType(x-1, y+1, z-1) > 0 )
        ao += 1;
    return ao;
	// End of user code
}

