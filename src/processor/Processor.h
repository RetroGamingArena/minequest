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

// Start of user code includes
#include "Octree.h"
// End of user code



using namespace std;

// Start of user code class import
// End of user code

class Processor
{

	protected:

	public:
		// Start of user code public
		// End of user code
		Processor();
		virtual ~Processor(){};
		virtual vector<GLfloat>* bufferize(Octree * octree) = 0;
};

#endif
