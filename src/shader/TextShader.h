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
	GLuint vertexArrayID;
	GLuint fontVertexBufferID;
	GLuint fontUVBufferID;

	protected:

	public:
		// Start of user code public
		// End of user code
		TextShader(GLuint _textureSamplerID, GLuint _vertexArrayID, GLuint _fontVertexBufferID, GLuint _fontUVBufferID);
		TextShader();
		GLuint getTextureSamplerID();
		void setTextureSamplerID(GLuint _textureSamplerID);
		GLuint getVertexArrayID();
		void setVertexArrayID(GLuint _vertexArrayID);
		GLuint getFontVertexBufferID();
		void setFontVertexBufferID(GLuint _fontVertexBufferID);
		GLuint getFontUVBufferID();
		void setFontUVBufferID(GLuint _fontUVBufferID);
		void poly();
};

#endif
