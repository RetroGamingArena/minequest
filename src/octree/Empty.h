#ifndef __Empty__
#define __Empty__

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


using namespace std;

// Start of user code class import
// End of user code

class Empty : public OctreeEntry
{
	// Start of user code private
	// End of user code
	float x;
	float y;
	float z;
	int size;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		Empty(float _x, float _y, float _z, int _size);
		Empty();
		~Empty();
		float getX();
		void setX(float _x);
		float getY();
		void setY(float _y);
		float getZ();
		void setZ(float _z);
		int getSize();
		void setSize(int _size);
		bool isCompressible();
		int getCode();
		unsigned char getAbs(int x, int y, int z, int size);
		void bufferize(VertexBuffer * vertexBuffer, float p, float q, float r, float size);
		OctreeEntry* getLeafAbs(int x, int y, int z, int size);
};

#endif
