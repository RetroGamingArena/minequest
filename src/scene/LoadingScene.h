#ifndef __LoadingScene__
#define __LoadingScene__

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

#include "VBOScene.h"


using namespace std;

// Start of user code class import
// End of user code

class LoadingScene : public VBOScene
{
	std::thread* thread;
	static std::mutex* mutex;

	protected:

	public:
		// Start of user code public
        void render();
		// End of user code
		LoadingScene(std::thread* _thread, std::mutex* _mutex);
		LoadingScene();
		~LoadingScene();
		std::thread* getThread();
		void setThread(std::thread* _thread);
		static std::mutex* getMutex();
		static void setMutex(std::mutex* _mutex);
		static void initWorld();
};

#endif
