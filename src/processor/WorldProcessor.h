#ifndef __WorldProcessor__
#define __WorldProcessor__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
#include "World.h"
#include "GameScene.h"
// End of user code



using namespace std;

// Start of user code class import
// End of user code

class WorldProcessor
{

	protected:

	public:
		// Start of user code public
		// End of user code
		WorldProcessor();
		virtual void bufferize(GameScene * gameScene, World * world) = 0;
};

#endif
