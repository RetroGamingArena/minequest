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
	// Start of user code private
	// End of user code
	static vector<int>* xs;
	static vector<int>* ys;
	static vector<int>* zs;
		OctreeEntry* generateOctreeEntry(int p, int q, int r, int size);

	protected:

	public:
		// Start of user code public
		// End of user code
		WorldGenerator(vector<int>* _xs, vector<int>* _ys, vector<int>* _zs);
		WorldGenerator();
		virtual ~WorldGenerator(){};
		static vector<int>* getXs();
		static void setXs(int _xs);
		static vector<int>* getYs();
		static void setYs(int _ys);
		static vector<int>* getZs();
		static void setZs(int _zs);
		virtual float getY(float x, float z) = 0;
		virtual unsigned char getCubeType(int x, int y, int z) = 0;
		Octree* generate(int p, int q, int r);
		unsigned char getOcclusion(int x, int y, int z);
};

#endif
