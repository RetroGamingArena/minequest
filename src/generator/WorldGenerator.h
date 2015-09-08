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

// Start of user code defines
// End of user code

// Start of user code includes
#include "Octree.h"
#include "Chunk.h"
#include "GenerationResult.h"
#include "Voxel.h"
#include "Node.h"
// End of user code



using namespace std;

// Start of user code class import
//class Chunk;
// End of user code

class WorldGenerator
{
	// Start of user code private
    /*int _x = 0;
    int _y = 0;
    int _z = 0;
    
    unsigned char type = 0;
    unsigned char occlusion = 0;
    
    int x_size;
    int y_size;
    int z_size;
    
    int p_x_size = 0;
    int q_y_size = 0;
    int r_z_size = 0;*/
    
    Node<Voxel*>* _node = NULL;
	// End of user code
	static vector<int>* xs;
	static vector<int>* ys;
	static vector<int>* zs;
    static short** sizes;
    
    GenerationResult generateOctreeEntry(int p, int q, int r, int size);
    void generateNode(Node<Voxel*>* node, int p, int q, int r, int size);
    
	protected:
	// Start of user code protected
    utils::NoiseMap heightMap;
	// End of user code

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
        virtual bool isCubeFilled(int x, int y, int z, int size) = 0;
        virtual bool isCubeUniform(int x, int y, int z, int size) = 0;
        bool isCubeVisible(int x,int y,int z,int size);
		Octree<Voxel*>* generate(Chunk* chunk, int p, int q, int r);
		unsigned char getOcclusion(int x, int y, int z);
};

#endif
