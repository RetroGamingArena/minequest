#include <cstdlib>

#include "Texture.h"
// Start of user code includes
#include "../depends/lodepng/lodepng.h"
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

Texture::~Texture()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
Texture::Texture(unsigned int _glTexture, char* _fileName)
{
    this->fileName = new char[strlen(_fileName)];
    strcpy(this->fileName, _fileName);
    
    glTexture = _glTexture;
    
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
	// Start of user code getTextureID
	// End of user code
	return textureID;
}

void Texture::setTextureID(GLuint _textureID)
{
	textureID = _textureID;
}
unsigned int Texture::getGlTexture()
{
	// Start of user code getGlTexture
	// End of user code
	return glTexture;
}

void Texture::setGlTexture(unsigned int _glTexture)
{
	glTexture = _glTexture;
}
char* Texture::getFileName()
{
	// Start of user code getFileName
	// End of user code
	return fileName;
}

void Texture::setFileName(char* _fileName)
{
	fileName = _fileName;
}

void Texture::flip_image_vertical(unsigned char* data, unsigned int width, unsigned int height)
{
	// Start of user code flip_image_vertical
    unsigned int size = width * height * 4;
    unsigned int stride = sizeof(char) * width * 4;
    unsigned char *new_data = (unsigned char *)malloc(sizeof(unsigned char) * size);
    for (unsigned int i = 0; i < height; i++) {
        unsigned int j = height - i - 1;
        memcpy(new_data + j * stride, data + i * stride, stride);
    }
    memcpy(data, new_data, size);
    free(new_data);
	// End of user code
}
void Texture::load_png_texture(char* file_name)
{
	// Start of user code load_png_texture
    unsigned int error;
    unsigned char *data;
    unsigned int width, height;
    error = lodepng_decode32_file(&data, &width, &height, file_name);
    if (error) {
        fprintf(stderr, "error %u: %s\n", error, lodepng_error_text(error));
    }
    flip_image_vertical(data, width, height);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    free(data);
	// End of user code
}

