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

// Start of user code defines
// End of user code

// Start of user code includes
// End of user code


#include "Background.h"
#include "UI.h"
#include "InputCamera.h"

using namespace std;

// Start of user code class import
// End of user code

class Scene
{
	// Start of user code private
	// End of user code

	protected:
	// Start of user code protected
	// End of user code
	int selectedCameraIndex;
	Background* background;
	UI* uI;
	vector<InputCamera*> cameras;

	public:
		// Start of user code public
        static Camera* camera;
        static glm::mat4 projection;
        static glm::mat4 VM;
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
        virtual void onMouseButton(int button, int action) = 0;
		InputCamera* getSelectedCamera();
		virtual void onKey(int key, int scancode, int action, int mods) = 0;
		Background* getBackground();
		UI* getUI();
		void setUI(UI* _uI);
		vector<InputCamera*> getCameras();
		void setCamerasAt(InputCamera* _cameras, int indice);
};

#endif
