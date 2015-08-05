#include <cstdlib>

#include "VBOScene.h"
// Start of user code includes
#include "Engine.h"
#include "Shader.h"
#include "VoxelVBO.h"
#include "TrackBallCamera.h"
#include <iostream>
#include <cmath>
// End of user code


VBOScene::VBOScene()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    cameras.push_back(new TrackBallCamera());
    doubleBuffer = new DoubleBuffer();
    doubleBuffer->getVertexBuffer()->init();
    VBO* vBO = new VoxelVBO();
    vBO->setInstanceSize(6);
    doubleBuffer->setVBO(vBO);
    updateCamera = true;
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
    
    // Enable blending
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    

    if(background != NULL)
        background->render();
    
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    //return;
    
    //3D
    
    glUseProgram(shader->getProgramID());
    
    //if(updateCamera)
    {
        glUniformMatrix4fv(shader->getMMatrixID(), 1, GL_FALSE, &getSelectedCamera()->getModel()[0][0]);
        glUniformMatrix4fv(shader->getVMatrixID(), 1, GL_FALSE, &getSelectedCamera()->getView()[0][0]);
        glUniformMatrix4fv(shader->getPMatrixID(), 1, GL_FALSE, &getSelectedCamera()->getProjection()[0][0]);
        updateCamera = false;
    }

    //for(int i = 0; i < doubleBuffers.size(); i++)
    {
        glBindBuffer(GL_ARRAY_BUFFER, doubleBuffer->getVertexBuffer()->getId());
        
        VBO* vBO = doubleBuffer->getVBO();
        vector<Attribute*> attributes = vBO->getAttributes();
        for(int i = 0; i < attributes.size(); i++)
            glEnableVertexAttribArray(i);
        
        int size = 0;
        
        int instanceFace = 4;
        
        for(int i = 0; i < attributes.size(); i++)
        {
            if( i == 2 )
                size=0;
            
            float stride = sizeof(GLfloat) * ( (attributes[i]->getDivisor()>0) ? 2 : 4);
            int divisor = attributes[i]->getDivisor();
            GLvoid* offset = (GLvoid*)(sizeof(GLuint) * size + sizeof(GLuint)*(divisor > 0 ? instanceFace*6*4/*72*/ : 0));//32 : 0));
            
            glVertexAttribIPointer( i, attributes[i]->getSize(), GL_UNSIGNED_INT, stride, offset);
            if(attributes[i]->getDivisor()>0)
                glVertexAttribDivisor( i, attributes[i]->getDivisor());
            size += attributes[i]->getSize();
        }
        
        //glBindBuffer(GL_ARRAY_BUFFER, doubleBuffer->getVertexBuffer()->getId());//bufferIDs[i]);
        
        vector<GLuint>* data = doubleBuffer->getVertexBuffer()->getData();
        
        //if(data->size() != oldSize)
        {
            int instanceCountFull = (data->size()-(instanceFace*6*4)/*72*/)/2;
            //int instanceCount = min( instanceCountFull, 140000 );
            glDrawArraysInstanced(GL_TRIANGLES, 0, instanceFace*6, instanceCountFull);
            //glDrawArraysInstanced(GL_TRIANGLES, 0, 18, instanceCount);
            //glDrawArraysInstanced(glDrawArraysInstanced, doubleBuffer->getIndiceBuffer()->getData()->size(), GL_UNSIGNED_INT, (void*)0, (data->size()-32)/4 );
          //  oldSize = data->size();
        }
        
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
    getSelectedCamera()->onMouseMotion(xpos, ypos);
	// End of user code
}
void VBOScene::onMouseScroll(double xoffset, double yoffset)
{
	// Start of user code onMouseScroll
    getSelectedCamera()->onMouseWheel(xoffset, yoffset);
	// End of user code
}
void VBOScene::onKey(int key, int scancode, int action, int mods)
{
	// Start of user code onKey
    if(action == GLFW_RELEASE && key == GLFW_KEY_TAB)
    {
        selectedCameraIndex = (selectedCameraIndex+1) % cameras.size();
        getSelectedCamera()->fireEvent(new Event(Event::ID_CHANGED, getSelectedCamera()));
    }
    else
    {
        getSelectedCamera()->onKeyboard(key, scancode, action, mods);
    }
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
					
