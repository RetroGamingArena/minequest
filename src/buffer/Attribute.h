#ifndef __Attribute__
#define __Attribute__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
// End of user code



using namespace std;

// Start of user code class import
// End of user code

class Attribute
{
	int size;
	int divisor;
	const char * name;

	protected:

	public:
		// Start of user code public
		// End of user code
		Attribute(int _size, int _divisor, const char * _name);
		Attribute();
		int getSize();
		void setSize(int _size);
		int getDivisor();
		void setDivisor(int _divisor);
		const char * getName();
		void setName(const char * _name);
};

#endif
