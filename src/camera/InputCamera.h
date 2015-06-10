#ifndef __InputCamera__
#define __InputCamera__

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

#include "Camera.h"


using namespace std;

// Start of user code class import
// End of user code

class InputCamera : public Camera
{
	// Start of user code private
	// End of user code

	protected:
	// Start of user code protected
    glm::vec3 position;
    glm::vec3 center;
	// End of user code
	float oldY;
	float oldX;

	public:
		// Start of user code public
		// End of user code
		InputCamera(float _oldY, float _oldX);
		InputCamera();
		virtual ~InputCamera(){};
		float getOldY();
		void setOldY(float _oldY);
		float getOldX();
		void setOldX(float _oldX);
		virtual void onMouseMotion(double xpos, double ypos) = 0;
		virtual void onMouseButton(int button, int action) = 0;
		virtual void onKeyboard(int key, int scancode, int action, int mods) = 0;
		virtual void onMouseWheel(double xoffset, double yoffset) = 0;
		glm::vec3 getPosition();
		glm::vec3 getCenter();
		glm::vec3 getUp();
};

#endif
