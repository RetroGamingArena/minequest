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

#include "InputCamera.h"


using namespace std;

// Start of user code class import
// End of user code

class TrackBallCamera : public InputCamera
{
	// Start of user code private
	// End of user code
	float distance;
	bool hold;
	float motionSensitivity;
	float scrollSensitivity;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		TrackBallCamera(float _distance, bool _hold, float _motionSensitivity, float _scrollSensitivity);
		TrackBallCamera();
		~TrackBallCamera();
		float getDistance();
		void setDistance(float _distance);
		bool getHold();
		void setHold(bool _hold);
		float getMotionSensitivity();
		void setMotionSensitivity(float _motionSensitivity);
		float getScrollSensitivity();
		void setScrollSensitivity(float _scrollSensitivity);
		glm::vec3 getCenter();
		glm::vec3 getPosition();
		void onMouseMotion(double xpos, double ypos);
		void onMouseButton(int button, int action);
		void onKeyboard(int key, int scancode, int action, int mods);
		void onMouseWheel(double xoffset, double yoffset);
};

#endif
