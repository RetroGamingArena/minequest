#ifndef __ChunkProcessorTask__
#define __ChunkProcessorTask__

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
// End of user code

#include "Task.h"

#include "Chunk.h"
#include "Processor.h"

using namespace std;

// Start of user code class import
// End of user code

class ChunkProcessorTask : public Task
{
	// Start of user code private
	// End of user code
	Chunk* chunk;
	Processor* processor;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		ChunkProcessorTask();
		~ChunkProcessorTask();
		Chunk* getChunk();
		void setChunk(Chunk* _chunk);
		Processor* getProcessor();
		void setProcessor(Processor* _processor);
		void run();
};

#endif
