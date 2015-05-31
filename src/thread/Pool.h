#ifndef __Pool__
#define __Pool__

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


#include "Thread.h"

using namespace std;

// Start of user code class import
class Task;
class Thread;
// End of user code

class Pool
{
	vector<Thread*> threads;
	bool running;
	std::thread* work;
	bool started;

	protected:
	int threadCount;
	std::mutex* mutex;

	public:
		// Start of user code public
		// End of user code
		Pool(int _threadCount, bool _running, std::thread* _work, std::mutex* _mutex, bool _started);
		Pool();
		virtual ~Pool(){};
		int getThreadCount();
		void setThreadCount(int _threadCount);
		bool getRunning();
		void setRunning(bool _running);
		std::thread* getWork();
		void setWork(std::thread* _work);
		std::mutex* getMutex();
		void setMutex(std::mutex* _mutex);
		bool getStarted();
		void setStarted(bool _started);
		void start();
		virtual Task* buildTask() = 0;
		static void run(Pool * pool);
		virtual bool hasNext() = 0;
		bool isRunning();
		vector<Thread*> getThreads();
		void setThreadsAt(Thread* _threads, int indice);
};

#endif
