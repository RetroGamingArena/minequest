#ifndef __Empty__
#define __Empty__

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
#include "Leaf.h"
// End of user code

#include "OctreeEntry.h"


using namespace std;

// Start of user code class import
// End of user code

template <class T>
class Empty : public OctreeEntry<T>
{
	// Start of user code private
	// End of user code
	float x;
	float y;
	float z;
	int size;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
    
    Empty(float _x, float _y, float _z, int _size)
    {
        x = _x;
        y = _y;
        z = _z;
        size = _size;
    }

    Empty()
    // Start of user code super class
    // End of user code
    {
        // Start of user code constructor
        // End of user code
    }

    ~Empty()
    {
        // Start of user code destructor
        // End of user code
    }
    
    // Start of user code methods
    // End of user code

    bool isCompressible()
    {
        // Start of user code isCompressible
        return false;
        // End of user code
    }

    int getCode()
    {
        // Start of user code getCode
        return 0;
        // End of user code
    }

    /*unsigned char getAbs(int x, int y, int z, int size)
    {
        return 0;
    }*/

    void bufferize(VertexBuffer * vertexBuffer, float p, float q, float r, float size)
    {
        // Start of user code bufferize
        // End of user code
    }

    /*OctreeEntry<T>* getAbs(int x, int y, int z, int size)
    {
        return this;
    }*/

    T getAbs(int x, int y, int z, int size)
    {
        return NULL;
    }

    OctreeEntry<T>* getLeafAbs(int x, int y, int z, int size)
    {
        return this;
    }
    
    float getX()
    {
        // Start of user code getX
        // End of user code
        return x;
    }
    
    void setX(float _x)
    {
        x = _x;
    }
    
    float getY()
    {
        // Start of user code getY
        // End of user code
        return y;
    }
    
    void setY(float _y)
    {
        y = _y;
    }
    
    float getZ()
    {
        // Start of user code getZ
        // End of user code
        return z;
    }
    
    void setZ(float _z)
    {
        z = _z;
    }
    
    int getSize()
    {
        // Start of user code getSize
        // End of user code
        return size;
    }
    
    void setSize(int _size)
    {
        size = _size;
    }

};

#endif
