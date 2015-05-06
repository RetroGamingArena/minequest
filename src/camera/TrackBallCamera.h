#ifndef __TrackBallCamera__
#define __TrackBallCamera__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
// End of user code

#include "Camera.h"


using namespace std;

class TrackBallCamera : public Camera
{
	glm::vec3 position;
	glm::vec3 center;
	glm::vec3 up;

	protected:

	public:
		// Start of user code public
		// End of user code
		TrackBallCamera(glm::vec3 _position, glm::vec3 _center, glm::vec3 _up);
		TrackBallCamera();
		glm::vec3 getPosition();
		void setPosition(glm::vec3 _position);
		glm::vec3 getCenter();
		void setCenter(glm::vec3 _center);
		glm::vec3 getUp();
		void setUp(glm::vec3 _up);
};

#endif
