#ifndef __WorldShader__
#define __WorldShader__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

#include "Shader.h"


using namespace std;

class WorldShader : public Shader
{

	protected:

	public:
		// Start of user code public
		// End of user code
		WorldShader();
		void poly();
};

#endif
