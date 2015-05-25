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


#include "VertexBuffer.h"
#include "BackgroundShader.h"

using namespace std;

// Start of user code class import
// End of user code

class Background
{
	VertexBuffer* vertexBuffer;
	BackgroundShader* backgroundShader;

	protected:

	public:
		// Start of user code public
		// End of user code
		Background();
		~Background();
		void render();
		VertexBuffer* getVertexBuffer();
		BackgroundShader* getBackgroundShader();
		void setBackgroundShader(BackgroundShader* _backgroundShader);
};

#endif
