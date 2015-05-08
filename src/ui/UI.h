#ifndef __UI__
#define __UI__

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


#include "Control.h"
#include "Shader.h"
#include "DoubleBuffer.h"
#include "Texture.h"

using namespace std;

// Start of user code class import
// End of user code

class UI
{

	protected:
	vector<Control*> controls;
	Shader* shader;
	DoubleBuffer* doubleBuffer;
	Texture* fontTexture;

	public:
		// Start of user code public
		// End of user code
		UI();
		~UI();
		void render();
		void printText(const char * text, int x, int y, int size);
		vector<Control*> getControls();
		Shader* getShader();
		void setShader(Shader* _shader);
		DoubleBuffer* getDoubleBuffer();
		void setDoubleBuffer(DoubleBuffer* _doubleBuffer);
		Texture* getFontTexture();
		void setFontTexture(Texture* _fontTexture);
};

#endif
