#ifndef __WorldProcessor__
#define __WorldProcessor__

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
#include "World.h"
// End of user code

#include "IterativeProcessor.h"

#include "World.h"

using namespace std;

// Start of user code class import
// End of user code

class WorldProcessor : public IterativeProcessor
{
	// Start of user code private
	// End of user code
	World* world;

	protected:

	public:
		// Start of user code public
		// End of user code
		WorldProcessor();
		~WorldProcessor();
		void process();
		World* getWorld();
		void setWorld(World* _world);
};

#endif
