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
{
	// Start of user code constructor
	// End of user code
}

// Start of user code methods
// End of user code



glm::mat4 Camera::getModel()
{
	return model;
}

void Camera::setModel(glm::mat4 _model)
{
	model = _model;
}
glm::mat4 Camera::getView()
{
	return view;
}

void Camera::setView(glm::mat4 _view)
{
	view = _view;
}
glm::mat4 Camera::getProjection()
{
	return projection;
}

void Camera::setProjection(glm::mat4 _projection)
{
	projection = _projection;
}

void Camera::look()
{
	// Start of user code look
	// End of user code
}

