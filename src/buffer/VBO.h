#ifndef __VBO__
#define __VBO__

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


#include "Attribute.h"

using namespace std;

// Start of user code class import
// End of user code

class VBO
{
	unsigned int headerSize;
	unsigned int instanceSize;

	protected:
	vector<Attribute*> attributes;

	public:
		// Start of user code public
		// End of user code
		VBO(unsigned int _headerSize, unsigned int _instanceSize);
		VBO();
		~VBO();
		unsigned int getHeaderSize();
		void setHeaderSize(unsigned int _headerSize);
		unsigned int getInstanceSize();
		void setInstanceSize(unsigned int _instanceSize);
		vector<Attribute*> getAttributes();
		void setAttributesAt(Attribute* _attributes, int indice);
};

#endif
