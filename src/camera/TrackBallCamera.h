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
		TrackBallCamera(float _distance, float _oldX, float _oldY, bool _hold, float _motionSensitivity, float _scrollSensitivity);
		TrackBallCamera();
		~TrackBallCamera();
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
		glm::vec3 getPosition();
		glm::vec3 getCenter();
		glm::vec3 getUp();
};

#endif
