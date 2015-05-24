#include <cstdlib>

#include "Background.h"
// Start of user code includes
#include "Engine.h"
// End of user code


Background::Background()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    Engine* engine = Engine::getInstance();
    backgroundShader = dynamic_cast<BackgroundShader*>(engine->getShaders()[2]);
    
    vertexBuffer = new VertexBuffer();
    
    vertexBuffer->getData()->push_back(-1);
    vertexBuffer->getData()->push_back(1);
    vertexBuffer->getData()->push_back(0);
    //vertexBuffer->getData()->push_back(0);
    //vertexBuffer->getData()->push_back(1);

    vertexBuffer->getData()->push_back(-1);
    vertexBuffer->getData()->push_back(-1);
    vertexBuffer->getData()->push_back(0);
    //vertexBuffer->getData()->push_back(0);
    //vertexBuffer->getData()->push_back(1);
    
    vertexBuffer->getData()->push_back(1);
    vertexBuffer->getData()->push_back(-1);
    vertexBuffer->getData()->push_back(0);
    //vertexBuffer->getData()->push_back(0);
    //vertexBuffer->getData()->push_back(1);
    
    vertexBuffer->getData()->push_back(-1);
    vertexBuffer->getData()->push_back(1);
    vertexBuffer->getData()->push_back(0);
   // vertexBuffer->getData()->push_back(0);
    //vertexBuffer->getData()->push_back(1);
    
    vertexBuffer->getData()->push_back(1);
    vertexBuffer->getData()->push_back(-1);
    vertexBuffer->getData()->push_back(0);
   // vertexBuffer->getData()->push_back(0);
   // vertexBuffer->getData()->push_back(1);
    
    vertexBuffer->getData()->push_back(1);
    vertexBuffer->getData()->push_back(1);
    vertexBuffer->getData()->push_back(0);
   // vertexBuffer->getData()->push_back(0);
    //vertexBuffer->getData()->push_back(1);
    
	// End of user code
}

Background::~Background()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code





void Background::render()
{
	// Start of user code render
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glUseProgram(backgroundShader->getProgramID());
    
    vertexBuffer->init();
    
    glEnableVertexAttribArray(0);
    //glEnableVertexAttribArray(1);
    
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );
    //glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, (void*)2 );

    glDrawArrays(GL_TRIANGLES, 0, 6);//vertexBuffer->getData()->size()/5 );
    
    glDisableVertexAttribArray(0);
    //glDisableVertexAttribArray(1);
    
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    
	// End of user code
}

BackgroundShader* Background::getBackgroundShader()
{
	// Start of user code getBackgroundShader
	// End of user code
	return backgroundShader;
}

void Background::setBackgroundShader(BackgroundShader* _backgroundShader)
{
	backgroundShader = _backgroundShader;
}
					
VertexBuffer* Background::getVertexBuffer()
{
	// Start of user code getVertexBuffer
	// End of user code
	return vertexBuffer;
}

