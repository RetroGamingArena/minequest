#include <cstdlib>

#include "UI.h"
// Start of user code includes
#include "Engine.h"
// End of user code


UI::UI()
{
	// Start of user code constructor
    /*buffer = new GlobalBuffer();
    
    view = glm::mat4(1.0f);
    projection = glm::ortho(0, 1024, 768, 0);
    model = glm::mat4(1.0f);
    MVP = projection * view * model;*/
    
    //TextureUtils::loadTexture("textures/font.png", GL_TEXTURE1, GL_LINEAR, false);
    //void TextureUtils::loadTexture(const char* texturePath, GLenum activeTexture, int minMagFilter, bool clampToEdge)
    //{
    //textUniformID = glGetUniformLocation( programID, "myTextureSampler" );
    
    /*glGenTextures(1, &fontID);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, fontID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    load_png_texture("textures/font.png");
    
    glGenVertexArrays(1, &vertexArrayID);
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




void UI::render()
{
	// Start of user code render
	// End of user code
}

vector<Control*> UI::getControls()
{
	// Start of user code getControls
	// End of user code
	return controls;
}

Shader* UI::getShader()
{
	// Start of user code getShader
	// End of user code
	return shader;
}

void UI::setShader(Shader* _shader)
{
	shader = _shader;
}
					
