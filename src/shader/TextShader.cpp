#include <cstdlib>

#include "TextShader.h"
// Start of user code includes
// End of user code

TextShader::TextShader(GLuint _textureSamplerID, GLuint _vertexArrayID, GLuint _fontVertexBufferID, GLuint _fontUVBufferID)
{
	textureSamplerID = _textureSamplerID;
	vertexArrayID = _vertexArrayID;
	fontVertexBufferID = _fontVertexBufferID;
	fontUVBufferID = _fontUVBufferID;
}

TextShader::TextShader()
// Start of user code super class
: Shader("shaders/uiVertexShader.glsl", "shaders/uiFragmentShader.glsl", NULL)
// End of user code
{
	// Start of user code constructor
    //Shader::Shader("shaders/uiVertexShader.glsl", "shaders/uiFragmentShader.glsl", NULL);
    textureSamplerID = glGetUniformLocation( this->getProgramID(), "myTextureSampler" );
    
    /*glGenTextures(1, &fontID);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, fontID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    load_png_texture("textures/font.png");*/
    
    glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);
    
    glGenBuffers(1, &fontVertexBufferID);
    glGenBuffers(1, &fontUVBufferID);
    
    /*glGenBuffers(1, &bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*buffer->getData()->size(), &(*buffer->getData())[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);*/
	// End of user code
}

TextShader::~TextShader()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code

void TextShader::poly()
{
	// Start of user code poly
	// End of user code
}



GLuint TextShader::getTextureSamplerID()
{
	// Start of user code getTextureSamplerID
	// End of user code
	return textureSamplerID;
}

void TextShader::setTextureSamplerID(GLuint _textureSamplerID)
{
	textureSamplerID = _textureSamplerID;
}

GLuint TextShader::getVertexArrayID()
{
	// Start of user code getVertexArrayID
	// End of user code
	return vertexArrayID;
}

void TextShader::setVertexArrayID(GLuint _vertexArrayID)
{
	vertexArrayID = _vertexArrayID;
}

GLuint TextShader::getFontVertexBufferID()
{
	// Start of user code getFontVertexBufferID
	// End of user code
	return fontVertexBufferID;
}

void TextShader::setFontVertexBufferID(GLuint _fontVertexBufferID)
{
	fontVertexBufferID = _fontVertexBufferID;
}

GLuint TextShader::getFontUVBufferID()
{
	// Start of user code getFontUVBufferID
	// End of user code
	return fontUVBufferID;
}

void TextShader::setFontUVBufferID(GLuint _fontUVBufferID)
{
	fontUVBufferID = _fontUVBufferID;
}



