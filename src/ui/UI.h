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

// Start of user code defines
// End of user code

// Start of user code includes
// End of user code


#include "Control.h"
#include "DoubleBuffer.h"
#include "Shader.h"
#include "Texture.h"
#include "Transmitter.h"

using namespace std;

// Start of user code class import
class Control;
// End of user code

class UI : public Transmitter
{
	// Start of user code private
	// End of user code

	protected:
	// Start of user code protected
	// End of user code
	vector<Control*> controls;
	DoubleBuffer* doubleBuffer;
	Shader* shader;
	Texture* fontTexture;

	public:
		// Start of user code public
		// End of user code
		UI();
        ~UI(){};
		virtual void render() = 0;
        void poly(){};
		void printText(const char * text, int x, int y, int size);
		virtual void refresh() = 0;
		vector<Control*> getControls();
		void setControlsAt(Control* _controls, int indice);
		DoubleBuffer* getDoubleBuffer();
		void setDoubleBuffer(DoubleBuffer* _doubleBuffer);
		Shader* getShader();
		void setShader(Shader* _shader);
		Texture* getFontTexture();
		void setFontTexture(Texture* _fontTexture);
        void onMouseMotion(double xpos, double ypos);
        void onMouseButton(int button, int action);
};

#endif
