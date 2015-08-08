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

// Start of user code defines
// End of user code

// Start of user code includes
#include "Leaf.h"
#include "Ray.h"
// End of user code

#include "Pool.h"

#include "Chunk.h"
#include "WorldGenerator.h"
#include "Camera.h"

using namespace std;

// Start of user code class import
// End of user code

class World : public Pool
{
	// Start of user code private
    // redondent for optimisation
    static glm::vec4 viewport;
	// End of user code
	vector<Chunk*> chunks;
	WorldGenerator* worldGenerator;
	int chunkIndice;
	int cubeCount;
	int instanceCount;
	int occludedCount;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
        static Camera* camera;
        bool isCubeRayCasted(int x, int y, int z, int size);
		// End of user code
	static int size;
		World(int _size, int _chunkIndice, int _cubeCount, int _instanceCount, int _occludedCount);
		World();
		~World();
		int getChunkIndice();
		void setChunkIndice(int _chunkIndice);
		int getCubeCount();
		void setCubeCount(int _cubeCount);
		int getInstanceCount();
		void setInstanceCount(int _instanceCount);
		int getOccludedCount();
		void setOccludedCount(int _occludedCount);
		bool isCubeVisible(int x, int y, int z, int size);
		void bufferizeEntry(VertexBuffer * vertexBuffer, unsigned char type, float p, float q, float r, int widthP, int widthQ, int widthR, unsigned char occlusion);
		unsigned char getCube(int x, int y, int z);
		Chunk* getChunk(int x, int y, int z);
		bool isCubeFree(int x, int y, int z, int size);
		OctreeEntry* getLeaf(int x, int y, int z);
		bool isCubeOccluded(int x, int y, int z, int size);
		OctreeEntry* collide(Ray * ray, int x, int y, int z);
		double isCubeInFrustum(double x1, double y1, double z1, double x2, double y2, double z2);
		vector<Chunk*> getChunks();
		void setChunksAt(Chunk* _chunks, int indice);
		WorldGenerator* getWorldGenerator();
		void setWorldGenerator(WorldGenerator* _worldGenerator);
		Task* buildTask();
};

#endif
