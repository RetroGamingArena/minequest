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

    for(int i = 0; i < 8; i++)
    {
        _x = (*xs)[i];
        _y = (*ys)[i];
        _z = (*zs)[i];
        
        x_size = sizes[8-size][_x];
        y_size = sizes[8-size][_y];
        z_size = sizes[8-size][_z];
        
        p_x_size = p+x_size;
        q_y_size = q+y_size;
        r_z_size = r+z_size;
        
        //type = getCubeType(p_x_size, q_y_size, r_z_size);
        //occlusion = getOcclusion(p_x_size, q_y_size, r_z_size);
        
        if(sizes[8-size][1]==1)
        {
            type = getCubeType(p_x_size, q_y_size, r_z_size);
            occlusion = getOcclusion(p_x_size, q_y_size, r_z_size);
            node->setOctreeEntriesAt(new Leaf<Voxel*>(new Voxel(p+_x, q+_y, r+_z, 1, occlusion, type, true)), i);
        }
        else
        {
            if( getCubeType(p_x_size+sizes[8-size][1]/2,q_y_size,r_z_size+sizes[8-size][1]/2) != getCubeType(p_x_size+sizes[8-size][1]/2,q_y_size+sizes[8-size][1]-1,r_z_size+sizes[8-size][1]/2) )
            //if(!isCubeUniform(p_x_size, q_y_size, r_z_size, sizes[8-size][1]))
            {
                _node = new Node<Voxel*>();
                node->setOctreeEntriesAt(_node, i);
                generateNode(_node, p_x_size, q_y_size, r_z_size, size+1);
                continue;
            }
            
            /*bool cubeFilled = true;
            float height = getY(p_x_size,r_z_size);
            if(height < q_y_size+sizes[8-size][1]-1)
                cubeFilled = cubeFilled;
            
            if(cubeFilled)
            {
                for(int _x = p_x_size; _x<p_x_size+sizes[8-size][1]; _x++)
                {
                    for(int _z = r_z_size; _z<r_z_size+sizes[8-size][1]; _z++)
                    {
                        height = getY(_x,_z);
                        if(height<q_y_size+sizes[8-size][1]-1)
                        {
                            cubeFilled = false;
                            break;
                        }
                    }
                    if(!cubeFilled)
                        break;
                }
            }
            if(!cubeFilled)*/
            if(!isCubeFilled(p_x_size, q_y_size, r_z_size, sizes[8-size][1]))
            {
                _node = new Node<Voxel*>();
                node->setOctreeEntriesAt(_node, i);
                generateNode(_node, p_x_size, q_y_size, r_z_size, size+1);
                continue;
            }
            type = getCubeType(p_x_size, q_y_size, r_z_size);
            occlusion = getOcclusion(p_x_size, q_y_size, r_z_size);
            node->setOctreeEntriesAt(new Leaf<Voxel*>(new Voxel(p_x_size, q_y_size, r_z_size, sizes[8-size][1], occlusion, type, true)), i);
        }
    }
}

Octree<Voxel*>* WorldGenerator::generate(int p, int q, int r)
{
	// Start of user code generate
    Octree<Voxel*>* octree = new Octree<Voxel*>();
    octree->setP(p);
    octree->setQ(q);
    octree->setR(r);
    int size = Chunk::size*Chunk::subsize;
    /*for(int i =0; i < 8; i++)
    {
        int x = (*xs)[i];
        int y = (*ys)[i];
        int z = (*zs)[i];
        
        GenerationResult generationResult = generateOctreeEntry(p*size+x*size/2, q*size+y*size/2, r*size+z*size/2, size/2);
        if(generationResult.type>0 && generationResult.octreeEntry == NULL)
            octree->setOctreeEntriesAt(new Leaf<Voxel*>(new Voxel(p*size+x*size/2, q*size+y*size/2, r*size+z*size/2, size/2, generationResult.occlusion, generationResult.type, true)), i);
        else
            octree->setOctreeEntriesAt(generationResult.octreeEntry, i);
    }*/
    generateNode(octree, p*size, q*size, r*size, 1); //size >> 1);
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

