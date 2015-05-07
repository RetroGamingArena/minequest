#ifndef __Task__
#define __Task__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
#include "Pool.h"
// End of user code



using namespace std;

// Start of user code class import
class Pool;
// End of user code

class Task
{

	protected:

	public:
		// Start of user code public
		// End of user code
		Task();
		static void run(Pool * pool);
};

#endif
