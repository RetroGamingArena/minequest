#ifndef __Control__
#define __Control__

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



using namespace std;

// Start of user code class import
// End of user code

class Control
{

	protected:
	int x;
	int y;

	public:
		// Start of user code public
		// End of user code
		Control(int _x, int _y);
		Control();
		int getX();
		void setX(int _x);
		int getY();
		void setY(int _y);
		virtual void render() = 0;
};

#endif
