#include <cstdlib>

#include "Scene.h"
// Start of user code includes
// End of user code

Scene::Scene(int _selectedCameraIndex)
{
	selectedCameraIndex = _selectedCameraIndex;
}

Scene::Scene()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    selectedCameraIndex = 0;
    background = new Background();
	// End of user code
}


// Start of user code methods
// End of user code




int Scene::getSelectedCameraIndex()
{
	// Start of user code getSelectedCameraIndex
	// End of user code
	return selectedCameraIndex;
}

void Scene::setSelectedCameraIndex(int _selectedCameraIndex)
{
	selectedCameraIndex = _selectedCameraIndex;
}


Camera* Scene::getSelectedCamera()
{
	// Start of user code getSelectedCamera
    return cameras[selectedCameraIndex];
	// End of user code
}

vector<Camera*> Scene::getCameras()
{
	// Start of user code getCameras
	// End of user code
	return cameras;
}

void Scene::setCamerasAt(Camera* _cameras, int indice)
{
	cameras[indice] = _cameras;
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
					
Background* Scene::getBackground()
{
	// Start of user code getBackground
	// End of user code
	return background;
}

