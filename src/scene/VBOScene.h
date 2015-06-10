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

// Start of user code defines
// End of user code

// Start of user code includes
// End of user code

#include "Scene.h"

#include "DoubleBuffer.h"

using namespace std;

// Start of user code class import
// End of user code

class VBOScene : public Scene
{
	// Start of user code private
	// End of user code

	protected:
	// Start of user code protected
	// End of user code
	DoubleBuffer* doubleBuffer;

	public:
		// Start of user code public
		// End of user code
		VBOScene();
		~VBOScene();
		DoubleBuffer* getDoubleBuffer();
		void setDoubleBuffer(DoubleBuffer* _doubleBuffer);
		void init();
		void render();
		void onMouseMotion(double xpos, double ypos);
		void onMouseScroll(double xoffset, double yoffset);
		void onKey(int key, int scancode, int action, int mods);
};

#endif
