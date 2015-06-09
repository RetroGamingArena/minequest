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

#include "Transmitter.h"

#include "Task.h"

using namespace std;

// Start of user code class import
class Task;
// End of user code

class Thread : public Transmitter
{
	// Start of user code private
	// End of user code
	Task* task;
	std::mutex* mutex;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		Thread(std::mutex* _mutex);
		Thread();
		~Thread();
		std::mutex* getMutex();
		void setMutex(std::mutex* _mutex);
		void start();
		bool isBusy();
		static void run(Thread * thread);
		Task* getTask();
		void setTask(Task* _task);
		void poly();
};

#endif
