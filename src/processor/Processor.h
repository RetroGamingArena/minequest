#ifndef __Processor__
#define __Processor__

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
#include "Octree.h"
#include "Leaf.h"
#include "Engine.h"
#include "Voxel.h"
// End of user code



using namespace std;

// Start of user code class import
// End of user code

class Processor
{
	// Start of user code private
    static double near;
    static std::mutex* addVoxelMutex;
    // redondent for optimisation
    static glm::vec4 viewport;
    static glm::vec3 vertexPosition;
    static glm::vec4 viewSpace;
    static glm::vec4 position;
    
    static bool isCubeVisible(int x, int y, int z, int size);
    static bool isCubeFree(int x, int y, int z, int size);
    static bool isCubeFreeWithMask(int x, int y, int z, int size);
    static bool isCubeInFrustum(double x1, double y1, double z1, double x2, double y2, double z2);
	// End of user code

	protected:
	// Start of user code protected
    void bufferizeLeaf(Leaf * leaf, vector<GLuint>* vec, int p, int q, int r, int size);
	// End of user code

	public:
		// Start of user code public
    vector<GLuint>* vec;
        static World* bufferizeWorld;
        vector<Voxel> voxels;
        bool buffered;
        void addVoxel(Voxel voxel);
        void bufferizeVoxels(/*vector<GLuint>* vec*/);
		// End of user code
		Processor();
		virtual ~Processor(){};
		virtual vector<GLuint>* bufferize(Octree * octree) = 0;
};

#endif
