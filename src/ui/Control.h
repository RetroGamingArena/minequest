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

// Start of user code defines
// End of user code

// Start of user code includes
#include "UI.h"
// End of user code



using namespace std;

// Start of user code class import
class UI;
// End of user code

class Control
{
	// Start of user code private
	// End of user code

	protected:
	// Start of user code protected
	// End of user code
	int x;
	int y;
    static int pixelSize;

	public:
		// Start of user code public
		// End of user code
		Control(int _x, int _y);
		Control();
		virtual ~Control(){};
		int getX();
		void setX(int _x);
		int getY();
		void setY(int _y);
		virtual void render(std::vector<glm::vec2> &vertices, std::vector<glm::vec2> &UVs) = 0;
        static void drawRect(std::vector<glm::vec2> &vertices, std::vector<glm::vec2> &UVs, int x, int y, int w, int h);
		virtual void refresh() = 0;
        virtual void mouseMove(double xpos, double ypos) = 0;
        virtual void mouseButton(int button, int action) = 0;
};

#endif
