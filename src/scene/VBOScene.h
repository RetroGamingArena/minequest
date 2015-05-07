#ifndef __VBOScene__
#define __VBOScene__

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

#include "Scene.h"

#include "DoubleBuffer.h"

using namespace std;

// Start of user code class import
// End of user code

class VBOScene : public Scene
{
	DoubleBuffer* doubleBuffer;

	protected:

	public:
		// Start of user code public
		// End of user code
		VBOScene();
		DoubleBuffer* getDoubleBuffer();
		void setDoubleBuffer(DoubleBuffer* _doubleBuffer);
		void init();
		void render();
};

#endif
