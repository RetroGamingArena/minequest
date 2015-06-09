#ifndef __LoadingUI__
#define __LoadingUI__

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

#include "UI.h"


using namespace std;

// Start of user code class import
// End of user code

class LoadingUI : public UI
{
	// Start of user code private
	// End of user code

	protected:

	public:
		// Start of user code public
		// End of user code
		LoadingUI();
		~LoadingUI();
		void render();
		void refresh();
};

#endif
