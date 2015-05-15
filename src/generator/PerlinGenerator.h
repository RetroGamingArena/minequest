#ifndef __PerlinGenerator__
#define __PerlinGenerator__

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

#include "WorldGenerator.h"


using namespace std;

// Start of user code class import
// End of user code

class PerlinGenerator : public WorldGenerator
{
	utils::NoiseMap heightMap;

	protected:

	public:
		// Start of user code public
		// End of user code
		PerlinGenerator(utils::NoiseMap _heightMap);
		PerlinGenerator();
		~PerlinGenerator();
		utils::NoiseMap getHeightMap();
		void setHeightMap(utils::NoiseMap _heightMap);
		float getY(float x, float z);
		unsigned char getCubeType(int x, int y, int z);
};

#endif
