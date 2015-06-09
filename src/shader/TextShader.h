#ifndef __TextShader__
#define __TextShader__

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


using namespace std;

// Start of user code class import
// End of user code

class TextShader : public Shader
{
	// Start of user code private
	// End of user code
	GLuint textureSamplerID;
	GLuint vertexArrayID;
	GLuint fontVertexBufferID;
	GLuint fontUVBufferID;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		TextShader(GLuint _textureSamplerID, GLuint _vertexArrayID, GLuint _fontVertexBufferID, GLuint _fontUVBufferID);
		TextShader();
		~TextShader();
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
