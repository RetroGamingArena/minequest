#ifndef __Control__
#define __Control__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"



using namespace std;

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
