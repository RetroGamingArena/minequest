#ifndef __Label__
#define __Label__

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

#include "Control.h"


using namespace std;

// Start of user code class import
// End of user code

class Label : public Control
{
	char* caption;

	protected:

	public:
		// Start of user code public
        Label(char* _caption, int x, int y);
		// End of user code
		Label(char* _caption);
		Label();
		~Label();
		char* getCaption();
		void setCaption(char* _caption);
		void render();
};

#endif
