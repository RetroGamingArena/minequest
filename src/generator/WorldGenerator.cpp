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



Octree<Voxel*>* WorldGenerator::generate(int p, int q, int r)
{
	// Start of user code generate
    Octree<Voxel*>* octree = new Octree<Voxel*>();
    octree->setP(p);
    octree->setQ(q);
    octree->setR(r);
    int size = Chunk::size*Chunk::subsize;
    for(int i =0; i < 8; i++)
    {
        int x = (*xs)[i];
        int y = (*ys)[i];
        int z = (*zs)[i];
        
        GenerationResult generationResult = generateOctreeEntry(p*size+x*size/2, q*size+y*size/2, r*size+z*size/2, size/2);
        if(generationResult.type>0 && generationResult.octreeEntry == NULL)
            octree->setOctreeEntriesAt(new Leaf<Voxel*>(new Voxel(p*size+x*size/2, q*size+y*size/2, r*size+z*size/2, size/2, generationResult.occlusion, generationResult.type, true)), i);
        else
            octree->setOctreeEntriesAt(generationResult.octreeEntry, i);
    }
    return octree;
	// End of user code
}
GenerationResult/*OctreeEntry**/ WorldGenerator::generateOctreeEntry(int p, int q, int r, int size)
{
	// Start of user code generateOctreeEntry
    GenerationResult res;
    
    int x = 0;
    int y = 0;
    int z = 0;

    GenerationResult generationResults[8];
    
    int size_2 = size >> 1;
    
    Node<Voxel*>* node;
    
    int i;
    
    for(i = 0; i < 8; i++)
    {
        x = (*xs)[i];
        y = (*ys)[i];
        z = (*zs)[i];

        if(size==2)
        {
            generationResults[i].octreeEntry = NULL;
            generationResults[i].type = getCubeType(p+x, q+y, r+z);
            unsigned char occlusion = getOcclusion(p+x, q+y, r+z);
            generationResults[i].occlusion = occlusion;
        }
        else
        {
            generationResults[i] = generateOctreeEntry(p+x*size_2, q+y*size_2, r+z*size_2, size_2);
        }
    }
    
    if(   generationResults[0].equals(generationResults[1])
       && generationResults[1].equals(generationResults[2])
       && generationResults[2].equals(generationResults[3])
       && generationResults[3].equals(generationResults[4])
       && generationResults[4].equals(generationResults[5])
       && generationResults[5].equals(generationResults[6])
       && generationResults[6].equals(generationResults[7]) )
    {
        res.octreeEntry = NULL;
        res.type = generationResults[0].type;
        res.occlusion = generationResults[0].occlusion;
    }
    else
    {
        node = new Node<Voxel*>();
        for(i = 0; i < 8; i++)
        {
            x = (*xs)[i];
            y = (*ys)[i];
            z = (*zs)[i];
            
            if(generationResults[i].octreeEntry == NULL)
            {
                if(generationResults[i].type > 0)
                    node->setOctreeEntriesAt(new Leaf<Voxel*>(new Voxel(p+x*size_2, q+y*size_2, r+z*size_2, size_2, generationResults[i].occlusion, generationResults[i].type, true)), i);
                else
                    node->setOctreeEntriesAt(NULL, i);
            }
            else
                node->setOctreeEntriesAt(generationResults[i].octreeEntry, i);
        }
        
        res.octreeEntry = node;
        res.type = 0;
        res.occlusion = 0;
    }
    
    return res;
    
    // End of user code
}
unsigned char WorldGenerator::getOcclusion(int x, int y, int z)
{
	// Start of user code getOcclusion
    if( getCubeType(x-1, y+1, z-1) == 0 &&
        getCubeType(x-1, y+1, z)   == 0 &&
        getCubeType(x-1, y+1, z+1) == 0 &&
        getCubeType(x, y+1, z-1)   == 0 &&
        getCubeType(x, y+1, z)     == 0 &&
        getCubeType(x, y+1, z+1)   == 0 &&
        getCubeType(x+1, y+1, z-1) == 0 &&
        getCubeType(x+1, y+1, z)   == 0 &&
        getCubeType(x+1, y+1, z+1) == 0)
    {
        return 0;
    }
    
    if( getCubeType(x-1, y+1, z-1) > 0 &&
       getCubeType(x-1, y+1, z)   > 0 &&
       getCubeType(x-1, y+1, z+1) > 0 &&
       getCubeType(x, y+1, z-1)   > 0 &&
       getCubeType(x, y+1, z)     > 0 &&
       getCubeType(x, y+1, z+1)   > 0 &&
       getCubeType(x+1, y+1, z-1) > 0 &&
       getCubeType(x+1, y+1, z)   > 0 &&
       getCubeType(x+1, y+1, z+1) > 0)
    {
        return 0;
    }
    
    
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

