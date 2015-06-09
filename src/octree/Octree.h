#ifndef __Octree__
#define __Octree__

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
#include "VertexBuffer.h"
// End of user code

#include "Node.h"


using namespace std;

// Start of user code class import
// End of user code

class Octree : public Node
{
	// Start of user code private
	// End of user code
	float p;
	float q;
	float r;

	protected:

	public:
		// Start of user code public
		// End of user code
	static int size;
	static int subSize;
		Octree(float _p, float _q, float _r, int _size, int _subSize);
		Octree();
		~Octree();
		float getP();
		void setP(float _p);
		float getQ();
		void setQ(float _q);
		float getR();
		void setR(float _r);
		void bufferize(VertexBuffer * vertexBuffer, float p, float q, float r);
};

#endif
