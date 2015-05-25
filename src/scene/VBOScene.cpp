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
    cameras.push_back(new TrackBallCamera());
    doubleBuffer = new DoubleBuffer();
    doubleBuffer->getVertexBuffer()->init();
    VBO* vBO = new VoxelVBO();
    vBO->setInstanceSize(6);
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
    
    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    

    //if(background != NULL)
    //    background->render();
    
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    //return;
    
    //3D
    
    glUseProgram(shader->getProgramID());
    //glUniformMatrix4fv(matrixID, 1, GL_FALSE, &getCamera()->getMVP()[0][0]);
    
    glUniformMatrix4fv(shader->getMMatrixID(), 1, GL_FALSE, &getSelectedCamera()->getModel()[0][0]);
    glUniformMatrix4fv(shader->getVMatrixID(), 1, GL_FALSE, &getSelectedCamera()->getView()[0][0]);
    glUniformMatrix4fv(shader->getPMatrixID(), 1, GL_FALSE, &getSelectedCamera()->getProjection()[0][0]);
    //glUniformMatrix4fv(cameraUnprojectionID, 1, GL_FALSE, &getCamera()->getUnprojection()[0][0]);
    //glUniform3fv(cameraPositionVecID, 1, &getCamera()->getPosition()[0]);
    
    //glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    
    //for(int i = 0; i < doubleBuffers.size(); i++)
    {
        glBindBuffer(GL_ARRAY_BUFFER, doubleBuffer->getVertexBuffer()->getId());
        
        VBO* vBO = doubleBuffer->getVBO();
        vector<Attribute*> attributes = vBO->getAttributes();
        for(int i = 0; i < attributes.size(); i++)
            glEnableVertexAttribArray(i);
        
        int size = 0;
        
        for(int i = 0; i < attributes.size(); i++)
        {
            if( i == 2 )
                size=0;
            
            float stride = sizeof(GLfloat) * ( (attributes[i]->getDivisor()>0) ? 8 : 4);
            int divisor = attributes[i]->getDivisor();
            GLvoid* offset = (GLvoid*)(sizeof(GLfloat) * size + sizeof(GLfloat)*(divisor > 0 ? 32 : 0));
            
            glVertexAttribPointer( i, attributes[i]->getSize(), GL_FLOAT, GL_FALSE, stride, offset);
            if(attributes[i]->getDivisor()>0)
                glVertexAttribDivisor( i, attributes[i]->getDivisor());
            size += attributes[i]->getSize();
        }
        
        glBindBuffer(GL_ARRAY_BUFFER, doubleBuffer->getVertexBuffer()->getId());//bufferIDs[i]);
        
        vector<GLfloat>* data = doubleBuffer->getVertexBuffer()->getData();
        
        glDrawElementsInstanced(GL_TRIANGLE_STRIP, 36, GL_UNSIGNED_INT, (void*)0, 8+(data->size()-32)/8 );
        
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
					
