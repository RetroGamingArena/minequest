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
	// Start of user code private
	// End of user code
	VertexBuffer* vertexBuffer;
	BackgroundShader* backgroundShader;
	glm::vec3 firstColor;
	glm::vec3 lastColor;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		Background(glm::vec3 _firstColor, glm::vec3 _lastColor);
		Background();
		~Background();
		glm::vec3 getFirstColor();
		void setFirstColor(glm::vec3 _firstColor);
		glm::vec3 getLastColor();
		void setLastColor(glm::vec3 _lastColor);
		void render();
		VertexBuffer* getVertexBuffer();
		BackgroundShader* getBackgroundShader();
		void setBackgroundShader(BackgroundShader* _backgroundShader);
};

#endif
