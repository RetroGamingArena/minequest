#ifndef __Attribute__
#define __Attribute__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>
#include <noise/noise.h>
#include "noiseutils.h"

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code defines
// End of user code

// Start of user code includes
// End of user code



using namespace std;

// Start of user code class import
// End of user code

class Attribute
{
	// Start of user code private
	// End of user code
	int size;
	int divisor;
	const char * name;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		Attribute(int _size, int _divisor, const char * _name);
		Attribute();
		~Attribute();
		int getSize();
		void setSize(int _size);
		int getDivisor();
		void setDivisor(int _divisor);
		const char * getName();
		void setName(const char * _name);
};

#endif
