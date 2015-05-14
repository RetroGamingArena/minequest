#include <cstdlib>

#include "Camera.h"
// Start of user code includes
// End of user code

Camera::Camera(glm::mat4 _model, glm::mat4 _view, glm::mat4 _projection)
{
	model = _model;
	view = _view;
	projection = _projection;
}

Camera::Camera()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    float FoV = 70.0f;
    projection = glm::perspective(FoV, 4.0f / 3.0f, 0.0009f, 200.0f);
    model = glm::mat4(1.0f);
	// End of user code
}


// Start of user code methods
// End of user code




glm::mat4 Camera::getModel()
{
	// Start of user code getModel
	// End of user code
	return model;
}

void Camera::setModel(glm::mat4 _model)
{
	model = _model;
}
glm::mat4 Camera::getView()
{
	// Start of user code getView
	// End of user code
	return view;
}

void Camera::setView(glm::mat4 _view)
{
	view = _view;
}
glm::mat4 Camera::getProjection()
{
	// Start of user code getProjection
	// End of user code
	return projection;
}

void Camera::setProjection(glm::mat4 _projection)
{
	projection = _projection;
}

void Camera::look()
{
	// Start of user code look
    float FoV = 70.0f;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.
    
    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    projection = glm::perspective(FoV, 4.0f / 3.0f, 0.0009f, 200.0f);
    // Camera matrix
    view       = glm::lookAt(
                             getRealPosition(),           // Camera is here
                             getRealCenter(), // and looks here : at the same position, plus "direction"
                             getRealUp()                  // Head is up (set to 0,-1,0 to look upside-down)
                             );
	// End of user code
}

