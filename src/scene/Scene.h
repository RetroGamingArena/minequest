#ifndef __Scene__
#define __Scene__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
// End of user code


#include "UI.h"
#include "Camera.h"

using namespace std;

class Scene
{

	protected:
	UI* uI;
	Camera* camera;

	public:
		// Start of user code public
		// End of user code
		Scene();
		virtual void init() = 0;
		virtual void render() = 0;
		UI* getUI();
		void setUI(UI* _uI);
		Camera* getCamera();
		void setCamera(Camera* _camera);
};

#endif
