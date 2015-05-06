#ifndef __UI__
#define __UI__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"


#include "Control.h"
#include "Shader.h"
#include "DoubleBuffer.h"
#include "Texture.h"

using namespace std;

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
