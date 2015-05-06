#ifndef __VoxelScene__
#define __VoxelScene__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
// End of user code

#include "VBOScene.h"


using namespace std;

class VoxelScene : public VBOScene
{

	protected:

	public:
		// Start of user code public
		// End of user code
		VoxelScene();
};

#endif
