#ifndef __Scene__
#define __Scene__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"


#include "Camera.h"
#include "UI.h"

using namespace std;

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
