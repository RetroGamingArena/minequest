#ifndef __OctreeEntry__
#define __OctreeEntry__

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
#include "WorldGenerator.h"
#include "VertexBuffer.h"
// End of user code



using namespace std;

// Start of user code class import
// End of user code

class OctreeEntry
{

	protected:

	public:
		// Start of user code public
		// End of user code
	static int NODE;
		OctreeEntry(int _NODE);
		OctreeEntry();
		~OctreeEntry();
		virtual void generate(WorldGenerator * worldGenerator, int p, int q, int r, int size) = 0;
		virtual bool isCompressible() = 0;
		virtual int getCode() = 0;
		virtual unsigned char getAbs(int x, int y, int z, int size) = 0;
		virtual void bufferize(VertexBuffer * vertexBuffer, float p, float q, float r, float size) = 0;
};

#endif
