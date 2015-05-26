#ifndef __ChunkTask__
#define __ChunkTask__

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
#include "Chunk.h"
#include "WorldGenerator.h"
// End of user code

#include "Task.h"

#include "WorldGenerator.h"
#include "Chunk.h"

using namespace std;

// Start of user code class import
// End of user code

class ChunkTask : public Task
{
	WorldGenerator* worldGenerator;
	Chunk* chunk;

	protected:

	public:
		// Start of user code public
        ChunkTask(Chunk* _chunk, WorldGenerator* _worldGenerator);
		// End of user code
		ChunkTask();
		~ChunkTask();
		WorldGenerator* getWorldGenerator();
		void setWorldGenerator(WorldGenerator* _worldGenerator);
		Chunk* getChunk();
		void setChunk(Chunk* _chunk);
		void run();
};

#endif
