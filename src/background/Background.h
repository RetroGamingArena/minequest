#ifndef __Background__
#define __Background__

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


#include "BackgroundShader.h"
#include "VertexBuffer.h"

using namespace std;

// Start of user code class import
// End of user code

class Background
{
	// Start of user code private
	// End of user code
	BackgroundShader* backgroundShader;
	VertexBuffer* vertexBuffer;

	protected:

	public:
		// Start of user code public
		// End of user code
		Background();
		~Background();
		void render();
		BackgroundShader* getBackgroundShader();
		void setBackgroundShader(BackgroundShader* _backgroundShader);
		VertexBuffer* getVertexBuffer();
};

#endif
