#ifndef __Cube__
#define __Cube__

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
// End of user code



using namespace std;

// Start of user code class import
// End of user code

class Cube
{

	protected:

	public:
		// Start of user code public
		// End of user code
	static int size;
		Cube(int _size);
		Cube();
};

#endif
