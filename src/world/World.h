#ifndef __World__
#define __World__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

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
	static int size;
	int chunkIndice;

	protected:

	public:
		// Start of user code public
		// End of user code
		World(int _size, int _chunkIndice);
		World();
		static int getSize();
		static void setSize(int _size);
		int getChunkIndice();
		void setChunkIndice(int _chunkIndice);
		WorldGenerator* getWorldGenerator();
		void setWorldGenerator(WorldGenerator* _worldGenerator);
		vector<Chunk*> getChunks();
		Task* buildTask();
		bool hasNext();
};

#endif
