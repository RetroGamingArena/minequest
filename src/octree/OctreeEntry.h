#ifndef __OctreeEntry__
#define __OctreeEntry__

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
//#include "WorldGenerator.h"
#include "VertexBuffer.h"
// End of user code



using namespace std;

// Start of user code class import
// End of user code

template <class T>
class OctreeEntry
{
	// Start of user code private
	// End of user code

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
    static int NODE;
		OctreeEntry(int _NODE)
        {
    
        }
		OctreeEntry()
        {
    
        }
		virtual ~OctreeEntry(){};
		virtual bool isCompressible() = 0;
		virtual int getCode() = 0;
		virtual T getAbs(int x, int y, int z, int size) = 0;
		virtual OctreeEntry* getLeafAbs(int x, int y, int z, int size) = 0;
};

#endif
