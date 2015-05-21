#ifndef __ItemCamera__
#define __ItemCamera__

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

#include "Camera.h"

#include "Item.h"

using namespace std;

// Start of user code class import
// End of user code

class ItemCamera : public Camera
{
	Item* item;

	protected:

	public:
		// Start of user code public
		// End of user code
		ItemCamera();
		~ItemCamera();
		Item* getItem();
		void setItem(Item* _item);
		void onMouseMotion(double xpos, double ypos);
		void onKeyboard(int key, int scancode, int action, int mods);
		void onMouseButton(int button, int action);
		void onMouseWheel(double xoffset, double yoffset);
		glm::vec3 getRealPosition();
		glm::vec3 getRealCenter();
		glm::vec3 getRealUp();
};

#endif
