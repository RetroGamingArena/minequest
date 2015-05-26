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


#include "Shader.h"
#include "Texture.h"
#include "Control.h"
#include "DoubleBuffer.h"

using namespace std;

// Start of user code class import
// End of user code

class UI
{

	protected:
	Shader* shader;
	Texture* fontTexture;
	vector<Control*> controls;
	DoubleBuffer* doubleBuffer;

	public:
		// Start of user code public
		// End of user code
		UI();
		virtual ~UI(){};
		virtual void render() = 0;
		void printText(const char * text, int x, int y, int size);
		virtual void refresh() = 0;
		Shader* getShader();
		void setShader(Shader* _shader);
		Texture* getFontTexture();
		void setFontTexture(Texture* _fontTexture);
		vector<Control*> getControls();
		void setControlsAt(Control* _controls, int indice);
		DoubleBuffer* getDoubleBuffer();
		void setDoubleBuffer(DoubleBuffer* _doubleBuffer);
};

#endif
