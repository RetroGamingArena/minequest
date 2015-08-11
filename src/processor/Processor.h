#ifndef __Processor__
#define __Processor__

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
#include "Octree.h"
#include "Leaf.h"
// End of user code



using namespace std;

// Start of user code class import
// End of user code

class Processor
{
	// Start of user code private
	// End of user code

	protected:
	// Start of user code protected
    static void bufferizeLeaf(Leaf * leaf, vector<GLuint>* vec, int p, int q, int r, int size);
	// End of user code

	public:
		// Start of user code public
        static World* bufferizeWorld;
		// End of user code
		Processor();
		virtual ~Processor(){};
		virtual vector<GLuint>* bufferize(Octree * octree) = 0;
};

#endif
