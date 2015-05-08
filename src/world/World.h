#ifndef __World__
#define __World__

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

#include "Pool.h"

#include "WorldGenerator.h"
#include "Chunk.h"

using namespace std;

// Start of user code class import
// End of user code

class World : public Pool
{
	WorldGenerator* worldGenerator;
	vector<Chunk*> chunks;
	int chunkIndice;

	protected:

	public:
		// Start of user code public
		// End of user code
	static int size;
		World(int _size, int _chunkIndice);
		World();
		~World();
		int getChunkIndice();
		void setChunkIndice(int _chunkIndice);
		WorldGenerator* getWorldGenerator();
		void setWorldGenerator(WorldGenerator* _worldGenerator);
		vector<Chunk*> getChunks();
		Task* buildTask();
		bool hasNext();
};

#endif