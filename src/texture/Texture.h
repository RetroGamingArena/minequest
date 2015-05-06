#ifndef __Texture__
#define __Texture__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"



using namespace std;

class Texture
{
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
