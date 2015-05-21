#ifndef __TrackBallCamera__
#define __TrackBallCamera__

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


using namespace std;

// Start of user code class import
// End of user code

class TrackBallCamera : public Camera
{
	glm::vec3 position;
	glm::vec3 center;
	glm::vec3 up;
	float angleY;
	float angleZ;
	float distance;
	float oldX;
	float oldY;
	bool hold;
	float motionSensitivity;
	float scrollSensitivity;

	protected:

	public:
		// Start of user code public
		// End of user code
		TrackBallCamera(glm::vec3 _position, glm::vec3 _center, glm::vec3 _up, float _angleY, float _angleZ, float _distance, float _oldX, float _oldY, bool _hold, float _motionSensitivity, float _scrollSensitivity);
		TrackBallCamera();
		~TrackBallCamera();
		glm::vec3 getPosition();
		void setPosition(glm::vec3 _position);
		glm::vec3 getCenter();
		void setCenter(glm::vec3 _center);
		glm::vec3 getUp();
		void setUp(glm::vec3 _up);
		float getAngleY();
		void setAngleY(float _angleY);
		float getAngleZ();
		void setAngleZ(float _angleZ);
		float getDistance();
		void setDistance(float _distance);
		float getOldX();
		void setOldX(float _oldX);
		float getOldY();
		void setOldY(float _oldY);
		bool getHold();
		void setHold(bool _hold);
		float getMotionSensitivity();
		void setMotionSensitivity(float _motionSensitivity);
		float getScrollSensitivity();
		void setScrollSensitivity(float _scrollSensitivity);
		void onMouseMotion(double xpos, double ypos);
		void onKeyboard(int key, int scancode, int action, int mods);
		void onMouseButton(int button, int action);
		void onMouseWheel(double xoffset, double yoffset);
		glm::vec3 getRealPosition();
		glm::vec3 getRealCenter();
		glm::vec3 getRealUp();
};

#endif
