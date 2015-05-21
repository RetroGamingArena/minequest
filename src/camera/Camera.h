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



using namespace std;

// Start of user code class import
// End of user code

class Camera
{

	protected:
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	public:
		// Start of user code public
		// End of user code
		Camera(glm::mat4 _model, glm::mat4 _view, glm::mat4 _projection);
		Camera();
		virtual ~Camera(){};
		glm::mat4 getModel();
		void setModel(glm::mat4 _model);
		glm::mat4 getView();
		void setView(glm::mat4 _view);
		glm::mat4 getProjection();
		void setProjection(glm::mat4 _projection);
		void look();
		virtual void onMouseMotion(double xpos, double ypos) = 0;
		virtual void onKeyboard(int key, int scancode, int action, int mods) = 0;
		virtual void onMouseButton(int button, int action) = 0;
		virtual void onMouseWheel(double xoffset, double yoffset) = 0;
		virtual glm::vec3 getRealPosition() = 0;
		virtual glm::vec3 getRealCenter() = 0;
		virtual glm::vec3 getRealUp() = 0;
};

#endif
