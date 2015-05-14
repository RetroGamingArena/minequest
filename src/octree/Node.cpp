#include <cstdlib>

#include "Node.h"
// Start of user code includes
#include "Chunk.h"
#include "CubeType.h"
#include "Leaf.h"
// End of user code


Node::Node()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    split();
	// End of user code
}

Node::~Node()
{
	// Start of user code destructor
    if( this->octreeEntries.size() > 0 )
        for(int i = 0; i < 8; i++)
        {
            if( this->octreeEntries[i] != NULL )
            {
                delete this->octreeEntries[i];
                this->octreeEntries[i] = NULL;
            }
        }
    octreeEntries.clear();
	// End of user code
}

// Start of user code methods
// End of user code

void Node::generate(WorldGenerator * worldGenerator, int p, int q, int r, int size)
{
	// Start of user code generate
    unsigned char* types = new unsigned char[8];
    
    int absSize = 0;
    
    int size_2 = size >> 1;
    int size_4 = size_2 >> 1;
    
    for(int i = 0; i < 8; i++)
    {
        int x = (i%4)&1;
        int y = i >> 2;
        int z = (i%4) >> 1;
        
        if(this->octreeEntries[i] == NULL)
        {
            int ii;
            
            if(size==4)
            {
                types[0] = 0;
                
                for(ii = 0; ii < 8; ii++)
                {
                    int xx = (ii%4)&1;
                    int yy = ii >> 2;
                    int zz = (ii%4) >> 1;
                    
                    double height = worldGenerator->getY(p+x*size_2 + xx*size_4, r+z*size_2 + zz*size_4)*Chunk::size*Chunk::subsize/2;
                    if(height > q+y*size_2+yy)
                        types[ii] = CubeType::getTypeFromHeight(q+y*size_2+yy);
                }
                if( types[0] > 0 && types[0] == types[1] && types[1] == types[2] && types[2] == types[3] && types[3] == types[4] && types[4] == types[5] && types[5] == types[6] && types[6] == types[7] )
                {
                    //octreeEntries[i] = new Leaf(types[0]);
                    continue;
                }
            }
            
            else if(size==2)
            {
                types[0] = 0;
                
                for(ii = 0; ii < 8; ii++)
                {
                    int xx = (ii%4)&1;
                    int yy = ii >> 2;
                    int zz = (ii%4) >> 1;
                    
                    double height = worldGenerator->getY(p+x*size_2 + xx*size_4, r+z*size_2 + zz*size_4)*Chunk::size*Chunk::subsize/2;
                    if(height > q+y*size_2+yy)
                        types[ii] = CubeType::getTypeFromHeight(q+y*size_2+yy);
                }
                for(int ii=0;ii<8;ii++)
                    if(types[ii] > 0)
                        octreeEntries[ii] = new Leaf(types[ii]);
                continue;
            }

            octreeEntries[i] = new Node();
            octreeEntries[i]->generate(worldGenerator, p+x*size_2, q+y*size_2, r+z*size_2, size_2);
            if(octreeEntries[i]->isCompressible() && size > 4)
                compress(x,y,z, 1);
        }
    }
    delete[] types;
    if(size == 1)
    {
        return;
    }
	// End of user code
}
bool Node::isCompressible()
{
	// Start of user code isCompressible
    bool _null = octreeEntries[0] == NULL;
    if(_null)
    {
        for( int i = 1 ; i < octreeEntries.size(); i++ )
            if(octreeEntries[i] != NULL)
                return false;
        return true;
    }
    
    int code = octreeEntries[0]->getCode();
    if(code == NODE)
        return false;
    for( int i = 1 ; i < octreeEntries.size(); i++ )
    {
        if(octreeEntries[i]== NULL)
            return false;
        if(octreeEntries[0]->getCode() == NODE)
            return false;
        if(octreeEntries[i]->getCode() != code)
            return false;
    }
    return true;
	// End of user code
}
int Node::getCode()
{
	// Start of user code getCode
    return NODE;
	// End of user code
}
unsigned char Node::getAbs(int x, int y, int z, int size)
{
	// Start of user code getAbs
    if(this->octreeEntries.size() == 0)
        this->split();
    
    int subsize = size >> 1;
    
    int i = !!(x & subsize);
    int j = !!(y & subsize);
    int k = !!(z & subsize);
    
    int _log = log2(subsize);
    
    int offset_x = x - (i << _log);
    int offset_y = y - (j << _log);
    int offset_z = z - (k << _log);
    
    OctreeEntry* entry = this->get(i,j,k);
    if(entry == NULL)
        return 0;
    else
        return entry->getAbs(offset_x,offset_y,offset_z, size/2);
	// End of user code
}
void Node::bufferize(VertexBuffer * vertexBuffer, float p, float q, float r, float size)
{
	// Start of user code bufferize
    for(int i = 0; i < 8; i++)
    {
        int x = (i%4)%2;
        int y = i/4;
        int z = (i%4)/2;
        
        //bufferize(scene, this->entries[i], p+x*size/2.0, q+y*size/2.0, r+z*size/2.0, size/2.0);
        if(this->octreeEntries[i] != NULL)
            this->octreeEntries[i]->bufferize(vertexBuffer, p+x*size/2.0, q+y*size/2.0, r+z*size/2.0, size/2.0);
    }
	// End of user code
}




void Node::compress(int x, int y, int z, unsigned char type)
{
	// Start of user code compress
    OctreeEntry* octreeEntry = this->get(x,y,z);

    type = octreeEntry->getAbs(x, y, z, 4);
    
    if(type==0)
    {
        delete octreeEntry;
        octreeEntries[x+y*4+z*2] = NULL;
    }
    else
    {
        Leaf* leaf = new Leaf();
        leaf->setType(type);
        octreeEntries[x+y*4+z*2] = leaf;
        delete octreeEntry;
    }
	// End of user code
}
OctreeEntry* Node::get(int x, int y, int z)
{
	// Start of user code get
    if(this->octreeEntries.size() > 0 )
        return this->octreeEntries[x+y*4+z*2];
    else
        return 0;
	// End of user code
}
void Node::split()
{
	// Start of user code split
    for(int i = 0; i < 8; i++)
        this->octreeEntries.push_back(NULL);
	// End of user code
}

vector<OctreeEntry*> Node::getOctreeEntries()
{
	// Start of user code getOctreeEntries
	// End of user code
	return octreeEntries;
}

