#ifndef __UI__
#define __UI__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"


#include "Control.h"
#include "Shader.h"

using namespace std;

class UI
{

	protected:
	vector<Control*> controls;
	Shader* shader;

	public:
		// Start of user code public
		// End of user code
		UI();
		void render();
		vector<Control*> getControls();
		Shader* getShader();
		void setShader(Shader* _shader);
};

#endif
