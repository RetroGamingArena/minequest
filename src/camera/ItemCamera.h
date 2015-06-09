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

#include "InputCamera.h"

#include "Item.h"

using namespace std;

// Start of user code class import
// End of user code

class ItemCamera : public InputCamera
{
	// Start of user code private
	// End of user code
	Item* item;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		ItemCamera();
		~ItemCamera();
		glm::vec3 getPosition();
		glm::vec3 getCenter();
		Item* getItem();
		void setItem(Item* _item);
		void onMouseMotion(double xpos, double ypos);
		void onMouseButton(int button, int action);
		void onKeyboard(int key, int scancode, int action, int mods);
		void onMouseWheel(double xoffset, double yoffset);
};

#endif
