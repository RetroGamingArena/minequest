#ifndef __Camera__
#define __Camera__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

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
		glm::mat4 getModel();
		void setModel(glm::mat4 _model);
		glm::mat4 getView();
		void setView(glm::mat4 _view);
		glm::mat4 getProjection();
		void setProjection(glm::mat4 _projection);
		void look();
};

#endif
