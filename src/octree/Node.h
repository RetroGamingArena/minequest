#ifndef __Node__
#define __Node__

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

#include "OctreeEntry.h"

#include "OctreeEntry.h"

using namespace std;

// Start of user code class import
// End of user code

class Node : public OctreeEntry
{

	protected:
	vector<OctreeEntry*> octreeEntries;

	public:
		// Start of user code public
		// End of user code
		Node();
		void compress(int x, int y, int z, unsigned char type);
		OctreeEntry* get(int x, int y, int z);
		void split();
		vector<OctreeEntry*> getOctreeEntries();
		void generate(WorldGenerator * worldGenerator, int p, int q, int r, int size);
		bool isCompressible();
		int getCode();
		unsigned char getAbs(int x, int y, int z, int size);
		void bufferize(VertexBuffer , float p, float q, float r, float size);
};

#endif
