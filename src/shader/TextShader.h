#ifndef __TextShader__
#define __TextShader__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

#include "Shader.h"


using namespace std;

class TextShader : public Shader
{
	GLuint textureSamplerID;
	GLuint fontID;

	protected:

	public:
		// Start of user code public
		// End of user code
		TextShader(GLuint _textureSamplerID, GLuint _fontID);
		TextShader();
		GLuint getTextureSamplerID();
		void setTextureSamplerID(GLuint _textureSamplerID);
		GLuint getFontID();
		void setFontID(GLuint _fontID);
};

#endif
