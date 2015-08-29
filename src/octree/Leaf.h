#ifndef __Leaf__
#define __Leaf__

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
//#include "World.h"
// End of user code

using namespace std;

// Start of user code class import
#include "OctreeEntry.h"
// End of user code

template <class T>
class Leaf : public OctreeEntry<T>
{
	// Start of user code private
	// End of user code
	//unsigned char type;
	//unsigned char occlusion;
    T value;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
        bool occluded;
        //static World* bufferizeWorld;
        unsigned char visible;
		// End of user code
		
        Leaf()
        {
        
        }
    
        Leaf(T value)
        {
            this->value = value;
            occluded = false;
            visible = false;
        };
    ~Leaf(){};

    T getValue()
    {
        return value;
    }
		
    bool isCompressible()
    {
        // Start of user code isCompressible
        return false;
        // End of user code
    }
    

    int getCode()
    {
        return 0;
    }
		
    T /*unsigned char*/ getAbs(int x, int y, int z, int size)
    {
        return value;
    }
    
    OctreeEntry<T>* getLeafAbs(int x, int y, int z, int size)
    {
        // Start of user code getLeafAbs
        return this;
        // End of user code
    }

};

#endif
