#include <cstdlib>

#include "Scene.h"
// Start of user code includes
// End of user code


Scene::Scene()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}


// Start of user code methods
// End of user code






Camera* Scene::getCamera()
{
	// Start of user code getCamera
	// End of user code
	return camera;
}

void Scene::setCamera(Camera* _camera)
{
	camera = _camera;
}
					
UI* Scene::getUI()
{
	// Start of user code getUI
	// End of user code
	return uI;
}

void Scene::setUI(UI* _uI)
{
	uI = _uI;
}
					
