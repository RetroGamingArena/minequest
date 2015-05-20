#include <cstdlib>

#include "UI.h"
// Start of user code includes
#include "Engine.h"
#include "Label.h"
#include "TextShader.h"
// End of user code


UI::UI()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    shader = Engine::getInstance()->getShaders()[1];
    
    //TextShader* textShader = dynamic_cast<TextShader*>(shader);
    /*buffer = new GlobalBuffer();
    
    view = glm::mat4(1.0f);
    projection = glm::ortho(0, 1024, 768, 0);
    model = glm::mat4(1.0f);
    MVP = projection * view * model;*/
    
    //textUniformID = glGetUniformLocation( programID, "myTextureSampler" );
    
    fontTexture = new Texture(GL_TEXTURE1, "textures/font.png");
    
    /*glGenTextures(1, &fontID);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, fontID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    load_png_texture("textures/font.png");*/
    
    /*glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);
    
    glGenBuffers(1, &fontVertexBufferID);
    glGenBuffers(1, &fontUVBufferID);*/
    
    
    //doubleBuffer = new DoubleBuffer();
    /*glGenBuffers(1, &bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*buffer->getData()->size(), &(*buffer->getData())[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);*/
	// End of user code
}


// Start of user code methods
void UI::render()
{
    glUseProgram(shader->getProgramID());
    
    //glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
    
    //glBindBuffer(GL_ARRAY_BUFFER, doubleBuffer->getVertexBuffer()->getId());
    
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0 );
    
    //vector<GLfloat> data = *doubleBuffer->getVertexBuffer()->getData();
    
    //glDrawArrays(GL_TRIANGLES, 0, data.size());
    
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    for(int i = 0; i < controls.size(); i++)
    {
        if(dynamic_cast<Label*>(controls[i]) != 0)
            this->printText(dynamic_cast<Label*>(controls[i])->getCaption(), controls[i]->getX(), controls[i]->getY(), 10);
    }
}
// End of user code





void UI::printText(const char * text, int x, int y, int size)
{
	// Start of user code printText
    unsigned int length = strlen(text);
    
    // Fill buffers
    std::vector<glm::vec2> vertices;
    std::vector<glm::vec2> UVs;
    for ( unsigned int i=0 ; i<length ; i++ )
    {
        glm::vec2 vertex_up_left    = glm::vec2( x+i*size     , -4+y+size );
        glm::vec2 vertex_up_right   = glm::vec2( x+i*size+size, -4+y+size );
        glm::vec2 vertex_down_right = glm::vec2( x+i*size+size, -12+y      );
        glm::vec2 vertex_down_left  = glm::vec2( x+i*size     , -12+y      );
        
        vertices.push_back(vertex_up_left   );
        vertices.push_back(vertex_down_left );
        vertices.push_back(vertex_up_right  );
        
        vertices.push_back(vertex_down_right);
        vertices.push_back(vertex_up_right);
        vertices.push_back(vertex_down_left);
        
        char character = text[i]-32;
        float uv_x = (character%16)/16.0f;
        float uv_y = (character/16)/8.0f;
        
        glm::vec2 uv_up_left    = glm::vec2( uv_x           , -1*uv_y );
        glm::vec2 uv_up_right   = glm::vec2( uv_x+1.0f/16.0f, -1*uv_y );
        glm::vec2 uv_down_right = glm::vec2( uv_x+1.0f/16.0f, -1*(uv_y + 1.0f/8.0f) );
        glm::vec2 uv_down_left  = glm::vec2( uv_x           , -1*(uv_y + 1.0f/8.0f) );
        UVs.push_back(uv_up_left   );
        UVs.push_back(uv_down_left );
        UVs.push_back(uv_up_right  );
        
        UVs.push_back(uv_down_right);
        UVs.push_back(uv_up_right);
        UVs.push_back(uv_down_left);
    }
    
    TextShader* textShader = dynamic_cast<TextShader*>(shader);
    
    glBindBuffer(GL_ARRAY_BUFFER, textShader->getFontVertexBufferID());
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec2), &vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, textShader->getFontUVBufferID());
    glBufferData(GL_ARRAY_BUFFER, UVs.size() * sizeof(glm::vec2), &UVs[0], GL_STATIC_DRAW);
    
    // Bind shader
    glUseProgram(shader->getProgramID());
    
    // Bind texture
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, fontTexture->getTextureID());
    // Set our "myTextureSampler" sampler to user Texture Unit 0
    glUniform1i(textShader->getTextureSamplerID(), 0);
    
    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, textShader->getFontVertexBufferID());
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0 );
    
    // 2nd attribute buffer : UVs
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, textShader->getFontUVBufferID());
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0 );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // Draw call
    glDrawArrays(GL_TRIANGLES, 0, vertices.size() );
    
    glDisable(GL_BLEND);
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
	// End of user code
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
					
vector<Control*> UI::getControls()
{
	// Start of user code getControls
	// End of user code
	return controls;
}

void UI::setControlsAt(Control* _controls, int indice)
{
	controls[indice] = _controls;
}

Texture* UI::getFontTexture()
{
	// Start of user code getFontTexture
	// End of user code
	return fontTexture;
}

void UI::setFontTexture(Texture* _fontTexture)
{
	fontTexture = _fontTexture;
}
					
DoubleBuffer* UI::getDoubleBuffer()
{
	// Start of user code getDoubleBuffer
	// End of user code
	return doubleBuffer;
}

void UI::setDoubleBuffer(DoubleBuffer* _doubleBuffer)
{
	doubleBuffer = _doubleBuffer;
}
					
