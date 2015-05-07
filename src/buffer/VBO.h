#ifndef __VBO__
#define __VBO__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
// End of user code


#include "Attribute.h"

using namespace std;

// Start of user code class import
// End of user code

class VBO
{
	unsigned int size;

	protected:
	vector<Attribute*> attributes;

	public:
		// Start of user code public
		// End of user code
		VBO(unsigned int _size);
		VBO();
		unsigned int getSize();
		void setSize(unsigned int _size);
		vector<Attribute*> getAttributes();
};

#endif
