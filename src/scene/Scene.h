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


#include "Camera.h"
#include "UI.h"

using namespace std;

// Start of user code class import
// End of user code

class Scene
{

	protected:
	Camera* camera;
	UI* uI;

	public:
		// Start of user code public
		// End of user code
		Scene();
		virtual void init() = 0;
		virtual void render() = 0;
		Camera* getCamera();
		void setCamera(Camera* _camera);
		UI* getUI();
		void setUI(UI* _uI);
};

#endif
