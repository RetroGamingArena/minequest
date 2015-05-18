#include <cstdlib>

#include "Node.h"
// Start of user code includes
#include "Chunk.h"
//#include "CubeType.h"
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

    int entryIndex = x + (y << 2) + (z << 1);
    
    Node * node = static_cast<Node*>(octreeEntries[entryIndex]);
    Leaf * leaf = static_cast<Leaf*>(node->get(0, 0, 0));
    
    if(leaf == NULL)
    {
        octreeEntries[entryIndex] = NULL;
         //delete octreeEntry;
    }
    else
    {
        type = leaf->getType();
        Leaf* leaf = new Leaf();
        leaf->setType(type);
        octreeEntries[entryIndex] = leaf;
    }
    delete octreeEntry;
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

void Node::setOctreeEntriesAt(OctreeEntry* _octreeEntries, int indice)
{
	octreeEntries[indice] = _octreeEntries;
}

