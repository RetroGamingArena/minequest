#ifndef __Listener__
#define __Listener__

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
#include "Event.h"
// End of user code



using namespace std;

// Start of user code class import
// End of user code

class Listener
{
	// Start of user code private
	// End of user code

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		Listener();
		virtual ~Listener(){};
		virtual void handle(Event * event) = 0;
};

#endif
