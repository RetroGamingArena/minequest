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

#include "Chunk.h"
#include "WorldGenerator.h"

using namespace std;

// Start of user code class import
// End of user code

class World : public Pool
{
	vector<Chunk*> chunks;
	WorldGenerator* worldGenerator;
	int chunkIndice;
	int cubeCount;

	protected:

	public:
		// Start of user code public
		// End of user code
	static int size;
		World(int _size, int _chunkIndice, int _cubeCount);
		World();
		~World();
		int getChunkIndice();
		void setChunkIndice(int _chunkIndice);
		int getCubeCount();
		void setCubeCount(int _cubeCount);
		bool isCubeVisible(int x, int y, int z, int size);
		void bufferizeEntry(VertexBuffer * vertexBuffer, unsigned char type, float p, float q, float r, int width, unsigned char occlusion);
		unsigned char getCube(int x, int y, int z);
		void bufferizeEntryRect(VertexBuffer * vertexBuffer, unsigned char type, float p, float q, float r, int width, int height, unsigned char occlusion);
		Chunk* getChunk(int x, int y, int z);
		vector<Chunk*> getChunks();
		void setChunksAt(Chunk* _chunks, int indice);
		WorldGenerator* getWorldGenerator();
		void setWorldGenerator(WorldGenerator* _worldGenerator);
		Task* buildTask();
		bool hasNext();
};

#endif
