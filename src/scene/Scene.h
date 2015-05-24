#ifndef __Scene__
#define __Scene__

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


#include "Background.h"
#include "Camera.h"
#include "UI.h"

using namespace std;

// Start of user code class import
// End of user code

class Scene
{

	protected:
	int selectedCameraIndex;
	Background* background;
	vector<Camera*> cameras;
	UI* uI;

	public:
		// Start of user code public
		// End of user code
		Scene(int _selectedCameraIndex);
		Scene();
		virtual ~Scene(){};
		int getSelectedCameraIndex();
		void setSelectedCameraIndex(int _selectedCameraIndex);
		virtual void init() = 0;
		virtual void render() = 0;
		virtual void onMouseMotion(double xpos, double ypos) = 0;
		virtual void onMouseScroll(double xoffset, double yoffset) = 0;
		Camera* getSelectedCamera();
		virtual void onKey(int key, int scancode, int action, int mods) = 0;
		Background* getBackground();
		vector<Camera*> getCameras();
		void setCamerasAt(Camera* _cameras, int indice);
		UI* getUI();
		void setUI(UI* _uI);
};

#endif
