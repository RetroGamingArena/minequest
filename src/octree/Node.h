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

// Start of user code defines
// End of user code

// Start of user code includes
// End of user code

#include "OctreeEntry.h"

#include "OctreeEntry.h"

using namespace std;

// Start of user code class import
// End of user code

class Node : public OctreeEntry
{
	// Start of user code private
	// End of user code

	protected:
	// Start of user code protected
	// End of user code
	vector<OctreeEntry*> octreeEntries;

	public:
		// Start of user code public
		// End of user code
		Node();
		~Node();
		void compress(int x, int y, int z, unsigned char type);
		OctreeEntry* get(int x, int y, int z);
		void split();
		vector<OctreeEntry*> getOctreeEntries();
		void setOctreeEntriesAt(OctreeEntry* _octreeEntries, int indice);
		bool isCompressible();
		int getCode();
		unsigned char getAbs(int x, int y, int z, int size);
		void bufferize(VertexBuffer * vertexBuffer, float p, float q, float r, float size);
};

#endif
