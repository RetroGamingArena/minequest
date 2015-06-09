#ifndef __Texture__
#define __Texture__

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



using namespace std;

// Start of user code class import
// End of user code

class Texture
{
	// Start of user code private
	// End of user code
	GLuint textureID;
	unsigned int glTexture;
	char* fileName;

	protected:

	public:
		// Start of user code public
		Texture(unsigned int _glTexture, char* _fileName);
        // End of user code
		Texture(GLuint _textureID, unsigned int _glTexture, char* _fileName);
		Texture();
		~Texture();
		GLuint getTextureID();
		void setTextureID(GLuint _textureID);
		unsigned int getGlTexture();
		void setGlTexture(unsigned int _glTexture);
		char* getFileName();
		void setFileName(char* _fileName);
		static void flip_image_vertical(unsigned char* data, unsigned int width, unsigned int height);
		static void load_png_texture(char* file_name);
};

#endif
