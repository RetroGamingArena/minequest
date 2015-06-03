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

// Start of user code includes
// End of user code

#include "Task.h"

#include "Processor.h"
#include "Chunk.h"

using namespace std;

// Start of user code class import
// End of user code

class ChunkProcessorTask : public Task
{
	Processor* processor;
	Chunk* chunk;

	protected:

	public:
		// Start of user code public
		// End of user code
		ChunkProcessorTask();
		~ChunkProcessorTask();
		Processor* getProcessor();
		void setProcessor(Processor* _processor);
		Chunk* getChunk();
		void setChunk(Chunk* _chunk);
		void run();
};

#endif
