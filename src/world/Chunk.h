#ifndef __Chunk__
#define __Chunk__

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
// End of user code


#include "Octree.h"
#include "VertexBuffer.h"

using namespace std;

// Start of user code class import
// End of user code

class Chunk
{
	Octree* octree;
	VertexBuffer* vertexBuffer;
	float p;
	float q;
	float r;

	protected:

	public:
		// Start of user code public
        Chunk(float _p, float _q, float _r);
		// End of user code
	static int size;
	static int subsize;
		Chunk(float _p, float _q, float _r, int _size, int _subsize);
		Chunk();
		float getP();
		void setP(float _p);
		float getQ();
		void setQ(float _q);
		float getR();
		void setR(float _r);
		void generate(WorldGenerator * worldGenerator);
		void bufferize();
		Octree* getOctree();
		void setOctree(Octree* _octree);
		VertexBuffer* getVertexBuffer();
		void setVertexBuffer(VertexBuffer* _vertexBuffer);
};

#endif
