#ifndef __Thread__
#define __Thread__

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


#include "Task.h"

using namespace std;

// Start of user code class import
class Task;
// End of user code

class Thread
{
	Task* task;
	std::mutex* mutex;

	protected:

	public:
		// Start of user code public
		// End of user code
		Thread(std::mutex* _mutex);
		Thread();
		std::mutex* getMutex();
		void setMutex(std::mutex* _mutex);
		void start();
		bool isBusy();
		Task* getTask();
		void setTask(Task* _task);
};

#endif
