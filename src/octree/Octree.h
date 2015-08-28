#ifndef __Octree__
#define __Octree__

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
#include "VertexBuffer.h"
// End of user code

#include "Node.h"


using namespace std;

// Start of user code class import
// End of user code

template <class T>
class Octree : public Node<T>
{
	// Start of user code private
	// End of user code
	float p;
	float q;
	float r;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
	static int size;
	static int subSize;
    Octree(float _p, float _q, float _r, int _size, int _subSize)
    {
        p = _p;
        q = _q;
        r = _r;
        size = _size;
        subSize = _subSize;
    }
    
    Octree()
    // Start of user code super class
    // End of user code
    {
        // Start of user code constructor
        // End of user code
    }
    
    ~Octree()
    {
        // Start of user code destructor
        // End of user code
    }

    float getP()
    {
        // Start of user code getP
        // End of user code
        return p;
    }

    void setP(float _p)
    {
        p = _p;
    }

    float getQ()
    {
        // Start of user code getQ
        // End of user code
        return q;
    }

    void setQ(float _q)
    {
        q = _q;
    }

    float getR()
    {
        // Start of user code getR
        // End of user code
        return r;
    }

    void setR(float _r)
    {
        r = _r;
    }
};

template<class T>
int Octree<T>::size = 0;

template<class T>
int Octree<T>::subSize = 0;



#endif
