#ifndef __ChunkTask__
#define __ChunkTask__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
#include "Chunk.h"
#include "WorldGenerator.h"
// End of user code

#include "Task.h"


using namespace std;

// Start of user code class import
// End of user code

class ChunkTask : public Task
{

	protected:

	public:
		// Start of user code public
        ChunkTask(Chunk* chunk, WorldGenerator* worldGenerator);
		// End of user code
		ChunkTask();
};

#endif
