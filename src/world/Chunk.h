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


#include "VertexBuffer.h"
#include "Octree.h"

using namespace std;

// Start of user code class import
// End of user code

class Chunk
{
	VertexBuffer* vertexBuffer;
	Octree* octree;
	float p;
	float q;
	float r;
	bool buffered;
	bool generated;

	protected:

	public:
		// Start of user code public
        Chunk(float _p, float _q, float _r);
		// End of user code
	static int size;
	static int subsize;
		Chunk(float _p, float _q, float _r, int _size, int _subsize, bool _buffered, bool _generated);
		Chunk();
		~Chunk();
		float getP();
		void setP(float _p);
		float getQ();
		void setQ(float _q);
		float getR();
		void setR(float _r);
		bool getBuffered();
		void setBuffered(bool _buffered);
		bool getGenerated();
		void setGenerated(bool _generated);
		void generate(WorldGenerator * worldGenerator);
		void bufferize();
		VertexBuffer* getVertexBuffer();
		void setVertexBuffer(VertexBuffer* _vertexBuffer);
		Octree* getOctree();
		void setOctree(Octree* _octree);
};

#endif
