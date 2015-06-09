#ifndef __Camera__
#define __Camera__

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

#include "Transmitter.h"


using namespace std;

// Start of user code class import
// End of user code

class Camera : public Transmitter
{
	// Start of user code private
	// End of user code

	protected:
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	float angleZ;
	float angleY;

	public:
		// Start of user code public
		// End of user code
		Camera(glm::mat4 _model, glm::mat4 _view, glm::mat4 _projection, float _angleZ, float _angleY);
		Camera();
		virtual ~Camera(){};
		glm::mat4 getModel();
		void setModel(glm::mat4 _model);
		glm::mat4 getView();
		void setView(glm::mat4 _view);
		glm::mat4 getProjection();
		void setProjection(glm::mat4 _projection);
		float getAngleZ();
		void setAngleZ(float _angleZ);
		float getAngleY();
		void setAngleY(float _angleY);
		void look();
		virtual glm::vec3 getPosition() = 0;
		virtual glm::vec3 getCenter() = 0;
		virtual glm::vec3 getUp() = 0;
		unsigned char getMask();
		void poly();
};

#endif
