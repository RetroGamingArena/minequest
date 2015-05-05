#ifndef __Buffer__
#define __Buffer__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"



using namespace std;

class Buffer
{

	protected:
	GLuint id;

	public:
		// Start of user code public
		// End of user code
		Buffer(GLuint _id);
		Buffer();
		GLuint getId();
		void setId(GLuint _id);
};

#endif
