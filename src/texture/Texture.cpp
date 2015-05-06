#include <cstdlib>

#include "Texture.h"
// Start of user code includes
// End of user code

Texture::Texture(GLuint _textureID, unsigned int _glTexture, char* _fileName)
{
	textureID = _textureID;
	glTexture = _glTexture;
	fileName = _fileName;
}

Texture::Texture()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

// Start of user code methods
Texture::Texture(unsigned int _glTexture, char* _fileName)
{
    this->fileName = new char[strlen(_fileName)];
    strcpy(this->fileName, _fileName);
    
    glGenTextures(1, &textureID);
    glActiveTexture(_glTexture);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    load_png_texture(_fileName);
}
// End of user code



GLuint Texture::getTextureID()
{
	return textureID;
}

void Texture::setTextureID(GLuint _textureID)
{
	textureID = _textureID;
}
unsigned int Texture::getGlTexture()
{
	return glTexture;
}

void Texture::setGlTexture(unsigned int _glTexture)
{
	glTexture = _glTexture;
}
char* Texture::getFileName()
{
	return fileName;
}

void Texture::setFileName(char* _fileName)
{
	fileName = _fileName;
}

void Texture::flip_image_vertical(unsigned char* data, unsigned int width, unsigned int height)
{
	// Start of user code flip_image_vertical
	// End of user code
}
void Texture::load_png_texture(char* file_name)
{
	// Start of user code load_png_texture
	// End of user code
}

