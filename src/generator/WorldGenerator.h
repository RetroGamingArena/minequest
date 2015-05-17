#ifndef __WorldGenerator__
#define __WorldGenerator__

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
#include "Octree.h"
// End of user code



using namespace std;

// Start of user code class import
// End of user code

class WorldGenerator
{
		OctreeEntry* generateOctreeEntry(int p, int q, int r, int size);

	protected:

	public:
		// Start of user code public
		// End of user code
		WorldGenerator();
		virtual ~WorldGenerator(){};
		virtual float getY(float x, float z) = 0;
		virtual unsigned char getCubeType(int x, int y, int z) = 0;
		Octree* generate(int p, int q, int r);
};

#endif
