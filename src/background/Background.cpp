#include <cstdlib>

#include "Background.h"
// Start of user code includes
#include "Engine.h"
// End of user code

Background::Background(glm::vec3 _firstColor, glm::vec3 _lastColor)
{
	firstColor = _firstColor;
	lastColor = _lastColor;
}

Background::Background()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    Engine* engine = Engine::getInstance();
    backgroundShader = dynamic_cast<BackgroundShader*>(engine->getShaders()[2]);
    
    firstColor = glm::vec3(0, 0, 255);
    lastColor  = glm::vec3(90, 150, 255);
    
    vertexBuffer = new VertexBuffer();
    vector<GLuint>* data = new vector<GLuint>(); //vertexBuffer->getData();
    
    data->push_back(0);
    data->push_back(2);
    data->push_back(0);
    
    data->push_back(lastColor.r);
    data->push_back(lastColor.g);
    data->push_back(lastColor.b);

    data->push_back(0);
    data->push_back(0);
    data->push_back(0);
    
    data->push_back(firstColor.r);
    data->push_back(firstColor.g);
    data->push_back(firstColor.b);

    data->push_back(2);
    data->push_back(0);
    data->push_back(0);
    
    data->push_back(firstColor.r);
    data->push_back(firstColor.g);
    data->push_back(firstColor.b);

    data->push_back(0);
    data->push_back(2);
    data->push_back(0);
    
    data->push_back(lastColor.r);
    data->push_back(lastColor.g);
    data->push_back(lastColor.b);

    data->push_back(2);
    data->push_back(0);
    data->push_back(0);
    
    data->push_back(firstColor.r);
    data->push_back(firstColor.g);
    data->push_back(firstColor.b);

    data->push_back(2);
    data->push_back(2);
    data->push_back(0);
    
    data->push_back(lastColor.r);
    data->push_back(lastColor.g);
    data->push_back(lastColor.b);
    
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    
    vertexBuffer->init();
    
    /*GLuint id;
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);*/
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(unsigned int)*data->size(), &(*data)[0], GL_STATIC_DRAW);
    //vertexBuffer->init();
	// End of user code
}

Background::~Background()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code




glm::vec3 Background::getFirstColor()
{
	// Start of user code getFirstColor
	// End of user code
	return firstColor;
}

void Background::setFirstColor(glm::vec3 _firstColor)
{
	firstColor = _firstColor;
}

glm::vec3 Background::getLastColor()
{
	// Start of user code getLastColor
	// End of user code
	return lastColor;
}

void Background::setLastColor(glm::vec3 _lastColor)
{
	lastColor = _lastColor;
}


void Background::render()
{
	// Start of user code render
    //glClearColor(1.0, 0.0, 0.0, 1.0);
    
    //glClear(GL_COLOR_BUFFER_BIT);// | GL_DEPTH_BUFFER_BIT);
    
    glUseProgram(backgroundShader->getProgramID());
    
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->getId());
    
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT)*6, (void*)0 );
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT)*6, (void*)12 );

    glDrawArrays(GL_TRIANGLES, 0, 6);//vertexBuffer->getData()->size()/5 );
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    
	// End of user code
}

VertexBuffer* Background::getVertexBuffer()
{
	// Start of user code getVertexBuffer
	// End of user code
	return vertexBuffer;
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
					
