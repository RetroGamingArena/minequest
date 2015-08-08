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
    setSelectedCameraIndex(0);
    background = new Background();
	// End of user code
}


// Start of user code methods
Camera* Scene::camera = NULL;
glm::mat4 Scene::projection;// = glm::mat4();
glm::mat4 Scene::VM;// = glm::mat4();
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
    if(cameras.size()>0)
    if(camera != getSelectedCamera())
    {
        camera = getSelectedCamera();
        projection = camera->getProjection();
        VM = camera->getView()*camera->getModel();
    }
}


InputCamera* Scene::getSelectedCamera()
{
	// Start of user code getSelectedCamera
    return cameras[selectedCameraIndex];
	// End of user code
}

Background* Scene::getBackground()
{
	// Start of user code getBackground
	// End of user code
	return background;
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
					
vector<InputCamera*> Scene::getCameras()
{
	// Start of user code getCameras
	// End of user code
	return cameras;
}

void Scene::setCamerasAt(InputCamera* _cameras, int indice)
{
	cameras[indice] = _cameras;
}

