#ifndef __VBO__
#define __VBO__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"


#include "Attribute.h"

using namespace std;

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
