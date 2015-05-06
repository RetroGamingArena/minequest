#ifndef __WorldShader__
#define __WorldShader__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
// End of user code

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
