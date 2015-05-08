#ifndef __IterativeProcessor__
#define __IterativeProcessor__

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

#include "WorldProcessor.h"
#include "Pool.h"


using namespace std;

// Start of user code class import
// End of user code

class IterativeProcessor : public WorldProcessor, public Pool
{
	int chunkIndice;

	protected:

	public:
		// Start of user code public
		// End of user code
		IterativeProcessor(int _chunkIndice);
		IterativeProcessor();
		int getChunkIndice();
		void setChunkIndice(int _chunkIndice);
		void bufferize(GameScene * gameScene, World * world);
		Task* buildTask();
		bool hasNext();
};

#endif
