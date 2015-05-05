#ifndef __Buffer__
#define __Buffer__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>



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
};

#endif
