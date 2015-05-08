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
        glBindBuffer(GL_ARRAY_BUFFER, doubleBuffer->getVertexBuffer()->getId());// bufferIDs[i]);
        
        VBO* vBO = doubleBuffer->getVBO();
        vector<Attribute*> attributes = doubleBuffer->getVBO()->getAttributes();
        for(int i = 0; i < attributes.size(); i++)
            glEnableVertexAttribArray(i);
        
        /*glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        glEnableVertexAttribArray(3);
        glEnableVertexAttribArray(4);
        glEnableVertexAttribArray(5);*/
        
        for(int i = 0; i < attributes.size(); i++)
        {
            glVertexAttribPointer( 2, attributes[i]->getSize(), GL_FLOAT, GL_FALSE, sizeof(GLfloat) * vBO->getSize(), (void*)(0) ); //0, NULL);
            if(attributes[i]->getDivisor()>0)
                glVertexAttribDivisor( 2, attributes[i]->getDivisor());
        }
    
        /*glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)0 );
        glVertexAttribPointer( 1, 1, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(sizeof(GLfloat) * 3));
        
        
        glVertexAttribPointer( 2, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(0) ); //0, NULL);
        glVertexAttribDivisor( 2, 1);
        glVertexAttribPointer( 3, 1, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(sizeof(GLfloat) * (3))); //0, NULL);
        glVertexAttribDivisor( 3, 1);
        glVertexAttribPointer( 4, 1, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(sizeof(GLfloat) * (4))); //0, NULL);
        glVertexAttribDivisor( 4, 1);
        glVertexAttribPointer( 5, 1, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(sizeof(GLfloat) * (5))); //0, NULL);
        glVertexAttribDivisor( 5, 1);*/
        
        //glDrawArrays(GL_POINTS, 0, buffer->getData()->size());
        //glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, (void*)0);           // element array buffer offset
        
        glBindBuffer(GL_ARRAY_BUFFER, doubleBuffer->getVertexBuffer()->getId());//bufferIDs[i]);
        
        vector<GLfloat>* data = doubleBuffer->getVertexBuffer()->getData();
        
        glDrawElementsInstanced(GL_TRIANGLE_STRIP, 32, GL_UNSIGNED_INT, (void*)0, data->size()-32/6 );//(buffers[i]->getData()->size()-32)/6 );           // element array buffer offset
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        for(int i = 0; i < attributes.size(); i++)
            glDisableVertexAttribArray(i);
        
        /*glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);
        glDisableVertexAttribArray(3);
        glDisableVertexAttribArray(4);
        glDisableVertexAttribArray(5);*/
        
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    
    //2D
    uI->render();
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
					
