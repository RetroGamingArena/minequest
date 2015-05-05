#include <cstdlib>

#include "TextShader.h"
// Start of user code includes
// End of user code

TextShader::TextShader(GLuint _textureSamplerID, GLuint _fontID)
{
	textureSamplerID = _textureSamplerID;
	fontID = _fontID;
}

TextShader::TextShader()
{
	// Start of user code constructor
    Shader::Shader("shaders/uiVertexShader.glsl", "shaders/uiFragmentShader.glsl", NULL);
    textureSamplerID = glGetUniformLocation( this->getProgramID(), "myTextureSampler" );
    
    glGenTextures(1, &fontID);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, fontID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    load_png_texture("textures/font.png");
    
    /*glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);
    
    glGenBuffers(1, &fontVertexBufferID);
    glGenBuffers(1, &fontUVBufferID);
    
    
    
    glGenBuffers(1, &bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*buffer->getData()->size(), &(*buffer->getData())[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);*/
	// End of user code
}

// Start of user code methods
// End of user code



GLuint TextShader::getTextureSamplerID()
{
	return textureSamplerID;
}

void TextShader::setTextureSamplerID(GLuint _textureSamplerID)
{
	textureSamplerID = _textureSamplerID;
}
GLuint TextShader::getFontID()
{
	return fontID;
}

void TextShader::setFontID(GLuint _fontID)
{
	fontID = _fontID;
}


