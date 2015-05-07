#ifndef __Item__
#define __Item__

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

class Item
{

	protected:

	public:
		// Start of user code public
		// End of user code
		Item();
		void live(double dt);
};

#endif
