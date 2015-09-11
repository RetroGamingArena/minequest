#include <cstdlib>
#include <iostream>

#include "WorldGenerator.h"
// Start of user code includes
#include "Leaf.h"
#include "World.h"
#include "CubeFace.h"
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
        xs->push_back( ((i%4)&1    ));//*0x1ff );
        ys->push_back( (i >> 2     ));//*0x1ff );
        zs->push_back( ((i%4) >> 1 ));//*0x1ff );
    }

    sizes = new short*[9];
    for(int i = 0; i <=8; i++ )
    {
        sizes[i] = new short[2];
        sizes[i][0] = 0;
        sizes[i][1] = pow(2, i);
    }
    
    // End of user code
}


// Start of user code methods
// End of user code



vector<int>* WorldGenerator::xs = new vector<int>();	
vector<int>* WorldGenerator::ys = new vector<int>();	
vector<int>* WorldGenerator::zs = new vector<int>();
short** WorldGenerator::sizes = NULL;

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

/*void WorldGenerator::generateNode(Node<Voxel*>* node, int p, int q, int r, int size)
{
    int _x = 0;
    int _y = 0;
    int _z = 0;
    
    int xx = 0;
    int yy = 0;
    int zz = 0;
    
    int size_2_size_2 = size * size;
    int j_mod_size_2_size_2 = 0;
    
    unsigned char type = 0;
    unsigned char occlusion = 0;
    unsigned char _type = 0;
    unsigned char _occlusion = 0;
    
    int j = 0;
    
    int x_size;
    int y_size;
    int z_size;
    
    Node<Voxel*>* _node = NULL;
    
    for(int i = 0; i < 8; i++)
    {
        _x = (*xs)[i];
        _y = (*ys)[i];
        _z = (*zs)[i];
        
        x_size = _x*size;
        y_size = _y*size;
        z_size = _z*size;
        
        type = getCubeType(p+x_size, q+y_size, r+z_size);
        occlusion = getOcclusion(p+x_size, q+y_size, r+z_size);
        
        if(size==1)
        {
            node->setOctreeEntriesAt(new Leaf<Voxel*>(new Voxel(p+_x, q+_y, r+_z, 1, occlusion, type, true)), i);
        }
        else
        {
            for(j = 0; j < size*size*size; j++)
            {
                j_mod_size_2_size_2 = j%size_2_size_2;
                
                xx = j_mod_size_2_size_2 % size;
                yy = j/size_2_size_2;
                zz = j_mod_size_2_size_2 / size;
                
                _type = getCubeType(p+x_size+xx, q+y_size+yy, r+z_size+zz);
                _occlusion = getOcclusion(p+x_size+xx, q+y_size+yy, r+z_size+zz);
                
                if(_type != type || _occlusion != occlusion)
                {
                    _node = new Node<Voxel*>();
                    node->setOctreeEntriesAt(_node, i);
                    generateNode(_node, p+x_size, q+y_size, r+z_size, size >> 1);
                    j = -1;
                    break;
                }
            }
            if(j != -1 && type > 0)
                node->setOctreeEntriesAt(new Leaf<Voxel*>(new Voxel(p+x_size, q+y_size, r+z_size, size, occlusion, type, true)), i);
        }
    }
}*/

void WorldGenerator::generateNode(Node<Voxel*>* node, int p, int q, int r, int size)
{

}

bool WorldGenerator::isCubeVisible(int x,int y,int z,int size)
{
    // Start of user code isCubeFree
    char visible = 0;
    
    int maxPosition = (Chunk::size*Chunk::subsize-1);
    int sizeM1 = size-1;
    int yPSize = y+size;
    int chunksWidth = World::size*2+1;
    
    //ground occlusion
    if( y==0 && getCubeType(x, y+size, z) > 0)
        return 0;
    
    //geometry occlusion
    //if(!isCubeFree(x, y, z, size))
    //    return 0;
    
    //side occlusion
    if( x==0 )
    {
        if( getCubeType(x, yPSize, z)>0 )
            return false;
    }
    
    if( (x+sizeM1)==((chunksWidth)*maxPosition))
    {
        if( getCubeType(x, yPSize, z)>0 )
            return 0;
    }
    
    if( (z+sizeM1)==((chunksWidth)*maxPosition))
    {
        if( getCubeType(x, yPSize, z)>0 )
            return 0;
    }
    
    if( z==0 )
    {
        if( getCubeType(x, yPSize, z)>0 )
            return 0;
    }
    
    if(y+size==Chunk::size*Chunk::subsize)
        return true;
    
    //geometry occlusion
    for(int i = size-1; i >= 0; i--)
        for(int j = size-1; j >= 0; j--)
        {
            if(!(visible & LEFT))
                if(getCubeType(x-1, y+i,   z+j) == 0)
                    visible |= LEFT;
            if(!(visible & RIGHT))
                if(getCubeType((x+size-1)+1, y+i,   z+j) == 0)
                    visible |= RIGHT;
            if(!(visible & BOTTOM))
                if(getCubeType(x+i, y-1,   z+j) == 0)
                    visible |= BOTTOM;
            if(!(visible & TOP))
                if(getCubeType(x+i, (y+size-1)+1,   z+j) == 0)
                    visible |= TOP;
            if(!(visible & BACK))
                if(getCubeType(x+i, y+j,   z-1) == 0)
                    visible |= BACK;
            if(!(visible & FRONT))
                if(getCubeType(x+i, y+j,   (z+size-1)+1) == 0)
                    visible |= FRONT;
        }
    
    return visible;
    // End of user code
}

Octree<Voxel*>* WorldGenerator::generate(Chunk* chunk, int p, int q, int r)
{
	// Start of user code generate
    Octree<Voxel*>* octree = new Octree<Voxel*>();
    octree->setP(p);
    octree->setQ(q);
    octree->setR(r);
    int size = Chunk::size*Chunk::subsize;
    
    Node<Voxel*>* node = octree;
    
    Node<Voxel*>** currentEntries = new Node<Voxel*>*[9];
    int currents[9];
    int p_x_sizes[9];
    int q_y_sizes[9];
    int r_z_sizes[9];
    
    unsigned char type = 0;
    unsigned char occlusion = 0;
    
    currentEntries[0] = node;
    currents[0] = 0;
    for(int i = 1; i < 9; i++)
    {
        currents[i] = -1;
        p_x_sizes[i] = 0;
        q_y_sizes[i] = 0;
        r_z_sizes[i] = 0;
    }
    
    int currentPower = 1;
    currents[1] = 0;
    p_x_sizes[0] = p*Chunk::size*Chunk::subsize;
    q_y_sizes[0] = q*Chunk::size*Chunk::subsize;
    r_z_sizes[0] = r*Chunk::size*Chunk::subsize;
    
    int x_size;
    int y_size;
    int z_size;
    
    int _x;
    int _y;
    int _z;
    
    int current = 0;
    int eight_currentPower = 0;
    int currentPower_1 = 0;
    
    Voxel* voxel = NULL;
    
    while(currents[1] > -1)
    {
        while(currents[currentPower] == 8)
        {
            currents[currentPower] = -1;
            currentPower--;
            currents[currentPower]++;
        }
        
        if(currents[1] == -1)
            break;

        current = currents[currentPower];
        eight_currentPower = 8-currentPower;
        currentPower_1 = currentPower-1;
        
        _x = (*xs)[current];
        _y = (*ys)[current];
        _z = (*zs)[current];
        
        x_size = sizes[eight_currentPower][_x];
        y_size = sizes[eight_currentPower][_y];
        z_size = sizes[eight_currentPower][_z];
        
        p_x_sizes[currentPower] = p_x_sizes[currentPower_1]+x_size;
        q_y_sizes[currentPower] = q_y_sizes[currentPower_1]+y_size;
        r_z_sizes[currentPower] = r_z_sizes[currentPower_1]+z_size;
        
        if( getCubeType(p_x_sizes[currentPower]+sizes[eight_currentPower][1]/2,
                        q_y_sizes[currentPower],
                        r_z_sizes[currentPower]+sizes[eight_currentPower][1]/2) !=
           getCubeType(p_x_sizes[currentPower]+sizes[eight_currentPower][1]/2,
                       q_y_sizes[currentPower]+sizes[eight_currentPower][1]-1,
                       r_z_sizes[currentPower]+sizes[eight_currentPower][1]/2) )
        {
            _node = new Node<Voxel*>();
            currentEntries[currentPower_1]->setOctreeEntriesAt(_node, current);
            currentEntries[currentPower] = _node;
            
            currentPower++;
            currents[currentPower] = 0;
        }
        else if(!isCubeFilled(p_x_sizes[currentPower], q_y_sizes[currentPower], r_z_sizes[currentPower], sizes[eight_currentPower][1]))
        {
            unsigned char bottom = getCubeType(p_x_sizes[currentPower]+sizes[eight_currentPower][1]/2,
                                        q_y_sizes[currentPower],
                                        r_z_sizes[currentPower]+sizes[eight_currentPower][1]/2);
            unsigned char top = getCubeType(p_x_sizes[currentPower]+sizes[eight_currentPower][1]/2,
                                            q_y_sizes[currentPower]+sizes[eight_currentPower][1]-1,
                                            r_z_sizes[currentPower]+sizes[eight_currentPower][1]/2);
            if(!isCubeEmpty(p_x_sizes[currentPower], q_y_sizes[currentPower], r_z_sizes[currentPower], sizes[eight_currentPower][1]))
            {
                _node = new Node<Voxel*>();
                currentEntries[currentPower_1]->setOctreeEntriesAt(_node, current);
                currentEntries[currentPower] = _node;
            
                currentPower++;
                currents[currentPower] = 0;
            }
            else
            {
                currents[currentPower]++;
            }
        }
        else
        {
            type = getCubeType(p_x_sizes[currentPower], q_y_sizes[currentPower], r_z_sizes[currentPower]);
            if(type > 0)
            {
                occlusion = getOcclusion(p_x_sizes[currentPower], q_y_sizes[currentPower], r_z_sizes[currentPower]);
                voxel = new Voxel(p_x_sizes[currentPower], q_y_sizes[currentPower], r_z_sizes[currentPower], sizes[eight_currentPower][1], occlusion, type, true);
                currentEntries[currentPower_1]->setOctreeEntriesAt(new Leaf<Voxel*>(voxel), currents[currentPower]);
                //if(isCubeVisible(p_x_sizes[currentPower], q_y_sizes[currentPower], r_z_sizes[currentPower], sizes[eight_currentPower][1]))
                    chunk->voxels.push_back(voxel);
                //else
                //    voxel->visible = false;
                //voxel->occluded = true;
                
            }
            currents[currentPower]++;
        }
        //currents[currentPower]++;
    }

    chunk->setOctree(octree);
    
    //generateNode(octree, p*size, q*size, r*size, 1); //size >> 1);
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
    /*if( getCubeType(x, y+1, z)     > 0)
    {
        return 0;
    }

    if( getCubeType(x-1, y+1, z-1) == 0 &&
        getCubeType(x-1, y+1, z)   == 0 &&
        getCubeType(x-1, y+1, z+1) == 0 &&
        getCubeType(x, y+1, z-1)   == 0 &&
        getCubeType(x, y+1, z+1)   == 0 &&
        getCubeType(x+1, y+1, z-1) == 0 &&
        getCubeType(x+1, y+1, z)   == 0 &&
        getCubeType(x+1, y+1, z+1) == 0)
    {
        return 0;
    }*/
    
    unsigned char ao = 0;
    if( getCubeType(x-1, y+1, z) > 0 )
        ao += 1;
    if( getCubeType(x, y+1, z-1) > 0 )
        ao += 1;
    if( getCubeType(x-1, y+1, z-1) > 0 )
        ao += 1;
    return ao;
	// End of user code
}

