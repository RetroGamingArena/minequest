#ifndef __Node__
#define __Node__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>
#include <noise/noise.h>
#include "noiseutils.h"

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code defines
// End of user code

// Start of user code includes
#include "Empty.h"
#include "Leaf.h"
// End of user code

using namespace std;

// Start of user code class import
// End of user code

template <class T>
class Node : public OctreeEntry<T>
{
	// Start of user code private
    /*int bufferizeX;
    int bufferizeY;
    int bufferizeZ;
    vector<int>* xs;
    vector<int>* ys;
    vector<int>* zs;*/
	// End of user code

	protected:
	// Start of user code protected
	// End of user code
	vector<OctreeEntry<T>*> octreeEntries;

	public:
		// Start of user code public
		// End of user code
    Node()
    // Start of user code super class
    // End of user code
    {
        // Start of user code constructor
        split();
        /*bufferizeX = 0;
         bufferizeY = 0;
         bufferizeZ = 0;*/
        // End of user code
    }
    
    ~Node()
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
    
    bool isCompressible()
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
        if(code == 1)
            return false;
        for( int i = 1 ; i < octreeEntries.size(); i++ )
        {
            if(octreeEntries[i]== NULL)
                return false;
            if(octreeEntries[0]->getCode() == 1)
                return false;
            if(octreeEntries[i]->getCode() != code)
                return false;
        }
        return true;
        // End of user code
    }
    
    int getCode()
    {
        // Start of user code getCode
        return 1;
        // End of user code
    }
    
    T getAbs(int x, int y, int z, int size)
    {
   
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
        
        OctreeEntry<T>* entry = this->get(i,j,k);
        if(entry == NULL)
            return 0;
        else
            return entry->getAbs(offset_x,offset_y,offset_z, size/2);
        // End of user code
    }
    
    //virtual T getAbs(int x, int y, int z, int size) = 0;
    //virtual OctreeEntry* getLeafAbs(int x, int y, int z, int size) = 0;
    
    
    OctreeEntry<T>* getLeafAbs(int x, int y, int z, int size)
    {
        int subsize = size >> 1;
        
        int i = !!(x & subsize);
        int j = !!(y & subsize);
        int k = !!(z & subsize);
        
        int _log = log2(subsize);
        
        int offset_x = x - (i << _log);
        int offset_y = y - (j << _log);
        int offset_z = z - (k << _log);
        
        OctreeEntry<T>* entry = this->get(i,j,k);
        if(entry == NULL)
            return new Empty<T>(i << _log,j << _log,k << _log, size/2); // TODO : corriger fuite mémoire
        else
        {
            OctreeEntry<T>* _entry = entry->getLeafAbs(offset_x,offset_y,offset_z, size/2); //getLeafAbs(offset_x,offset_y,offset_z, size/2);
            Empty<T>* empty = dynamic_cast<Empty<T>*>(_entry);
            if( empty != NULL )
            {
                empty->setX(empty->getX()+(i << _log));
                empty->setY(empty->getY()+(j << _log));
                empty->setZ(empty->getZ()+(k << _log));
                return empty;
            }
            return _entry;
        }

    }
    
    void compress(int x, int y, int z, unsigned char type)
    {
        // Start of user code compress
        OctreeEntry<T>* octreeEntry = this->get(x,y,z);
        
        int entryIndex = x + (y << 2) + (z << 1);
        
        Node * node = static_cast<Node*>(octreeEntries[entryIndex]);
        Leaf<T> * leaf = static_cast<Leaf<T>*>(node->get(0, 0, 0));
        
        if(leaf == NULL)
        {
            octreeEntries[entryIndex] = NULL;
            //delete octreeEntry;
        }
        else
        {
            type = leaf->getType();
            Leaf<T>* leaf = new Leaf<T>();
            leaf->setType(type);
            octreeEntries[entryIndex] = leaf;
        }
        delete octreeEntry;
        // End of user code
    }
    
    OctreeEntry<T>* get(int x, int y, int z)
    {
        // Start of user code get
        if(this->octreeEntries.size() > 0 )
            return this->octreeEntries[x+y*4+z*2];
        else
            return 0;
        // End of user code
    }

    void split()
    {
        // Start of user code split
        this->octreeEntries.reserve(8);
        for(int i = 0; i < 8; i++)
            this->octreeEntries.push_back(NULL);
        // End of user code
    }

    vector<OctreeEntry<T>*> getOctreeEntries()
    {
        // Start of user code getOctreeEntries
        // End of user code
        return octreeEntries;
    }

    void setOctreeEntriesAt(OctreeEntry<T>* _octreeEntries, int indice)
    {
        octreeEntries[indice] = _octreeEntries;
    }

};

#endif
