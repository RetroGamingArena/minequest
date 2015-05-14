#ifndef __Buffer__
#define __Buffer__

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



using namespace std;

// Start of user code class import
// End of user code

class Buffer
{

	protected:
	GLuint id;

	public:
		// Start of user code public
		// End of user code
		Buffer(GLuint _id);
		Buffer();
		virtual ~Buffer(){};
		GLuint getId();
		void setId(GLuint _id);
		void init();
		virtual void bind() = 0;
};

#endif
