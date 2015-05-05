#ifndef __VBOScene__
#define __VBOScene__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "Scene.h"

#include "DoubleBuffer.h"

using namespace std;

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
