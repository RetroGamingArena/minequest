#include <cstdlib>

#include "VBOScene.h"
// Start of user code includes
#include "Engine.h"
#include "Shader.h"
#include "VoxelVBO.h"
#include "TrackBallCamera.h"
// End of user code


VBOScene::VBOScene()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    camera = new TrackBallCamera();
    doubleBuffer = new DoubleBuffer();
    doubleBuffer->getVertexBuffer()->init();
    VBO* vBO = new VoxelVBO();
    vBO->setSize(6);
    doubleBuffer->setVBO(vBO);
	// End of user code
}

VBOScene::~VBOScene()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code

void VBOScene::init()
{
	// Start of user code init
	// End of user code
}
void VBOScene::render()
{
	// Start of user code render
    Engine* engine = Engine::getInstance();
    Shader* shader = engine->getShaders()[0];

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(shader->getProgramID());
    
    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    //3D
    //glUniformMatrix4fv(matrixID, 1, GL_FALSE, &getCamera()->getMVP()[0][0]);
    
    glUniformMatrix4fv(shader->getMMatrixID(), 1, GL_FALSE, &getCamera()->getModel()[0][0]);
    glUniformMatrix4fv(shader->getVMatrixID(), 1, GL_FALSE, &getCamera()->getView()[0][0]);
    glUniformMatrix4fv(shader->getPMatrixID(), 1, GL_FALSE, &getCamera()->getProjection()[0][0]);
    //glUniformMatrix4fv(cameraUnprojectionID, 1, GL_FALSE, &getCamera()->getUnprojection()[0][0]);
    //glUniform3fv(cameraPositionVecID, 1, &getCamera()->getPosition()[0]);
    
    //glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    
    //for(int i = 0; i < doubleBuffers.size(); i++)
    {
        glBindBuffer(GL_ARRAY_BUFFER, doubleBuffer->getVertexBuffer()->getId());
        
        VBO* vBO = doubleBuffer->getVBO();
        vector<Attribute*> attributes = doubleBuffer->getVBO()->getAttributes();
        for(int i = 0; i < attributes.size(); i++)
            glEnableVertexAttribArray(i);
        
        int size = 0;
        
        for(int i = 0; i < attributes.size(); i++)
        {
            if( attributes[i]->getSize() == 3)
                size=0;
            
            glVertexAttribPointer( i, attributes[i]->getSize(), GL_FLOAT, GL_FALSE, sizeof(GLfloat) * vBO->getSize(), (void*)(sizeof(GLfloat) *size) ); //0, NULL);
            if(attributes[i]->getDivisor()>0)
                glVertexAttribDivisor( i, attributes[i]->getDivisor());
            size += attributes[i]->getSize();
        }
        
        glBindBuffer(GL_ARRAY_BUFFER, doubleBuffer->getVertexBuffer()->getId());//bufferIDs[i]);
        
        vector<GLfloat>* data = doubleBuffer->getVertexBuffer()->getData();
        
        glDrawElementsInstanced(GL_TRIANGLE_STRIP, 32, GL_UNSIGNED_INT, (void*)0, (data->size()-32)/6 );
        
        for(int i = 0; i < attributes.size(); i++)
            glDisableVertexAttribArray(i);
        
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    
    //2D
    uI->render();
	// End of user code
}
void VBOScene::onMouseMotion(double xpos, double ypos)
{
	// Start of user code onMouseMotion
    camera->onMouseMotion(xpos, ypos);
	// End of user code
}
void VBOScene::onMouseScroll(double xoffset, double yoffset)
{
	// Start of user code onMouseScroll
    camera->onMouseWheel(xoffset, yoffset);
	// End of user code
}





DoubleBuffer* VBOScene::getDoubleBuffer()
{
	// Start of user code getDoubleBuffer
	// End of user code
	return doubleBuffer;
}

void VBOScene::setDoubleBuffer(DoubleBuffer* _doubleBuffer)
{
	doubleBuffer = _doubleBuffer;
}
					
