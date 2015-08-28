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
class Leaf : public OctreeEntry
{
	// Start of user code private
	// End of user code
	unsigned char type;
	unsigned char occlusion;
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
		
            Leaf(unsigned char _type, unsigned char _occlusion)
            {
   
        
        type = _type;
        occlusion = _occlusion;
        
        occluded = false;
        visible = false;
                }
    
            Leaf(){};
    ~Leaf(){};
		

            unsigned char getType()
            {
                    // Start of user code getType
                    // End of user code
                    return type;
                }
    
    void setType(unsigned char _type)
    {
        type = _type;
    }
		

        unsigned char getOcclusion()
        {
            // Start of user code getOcclusion
            // End of user code
            return occlusion;
        }
    
    void setOcclusion(unsigned char _occlusion)
    {
        occlusion = _occlusion;
    }
		
    bool isCompressible()
    {
        // Start of user code isCompressible
        return false;
        // End of user code
    }
    

    int getCode()
    {
        // Start of user code getCode
        return type;
        // End of user code
    }
    

    unsigned char getAbs(int x, int y, int z, int size)
    {
        // Start of user code getAbs
        return type;
        // End of user code
    }

		
    OctreeEntry* getLeafAbs(int x, int y, int z, int size)
    {
        // Start of user code getLeafAbs
        return this;
        // End of user code
    }

};

#endif
