#ifndef __Scene__
#define __Scene__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>


#include "Camera.h"

using namespace std;

class Scene
{
	Camera* camera;

	public:
		// Start of user code public
		// End of user code
		Scene();
		void init();
		Camera* getCamera();
		void setCamera(Camera* _camera);
};

#endif
