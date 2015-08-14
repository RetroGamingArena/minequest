#include <cstdlib>

#include "VoxelScene.h"
// Start of user code includes
#include "DebugUI.h"
#include "CubeFace.h"
// End of user code


VoxelScene::VoxelScene()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    this->uI = new DebugUI();
    _updateIndices = false;
	// End of user code
}

VoxelScene::~VoxelScene()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
void VoxelScene::render()
{
    if(_updateIndices)
    {
        updateIndices();
        _updateIndices = false;
    }
    VBOScene::render();
    glClearColor(0.5f, 0.9f, 1.0f, 0.0f);
}
// End of user code





void VoxelScene::updateIndices()
{
	// Start of user code updateIndices
    cameras[selectedCameraIndex]->getMask();
    unsigned char mask = cameras[selectedCameraIndex]->getMask();
    
    int indices[4];
    int indicesRaw[4];
    int indices2[4];
    
    
    int yOffset = 0;
    if(mask & TOP)
        yOffset = 1;
    int hOffset = 0;
    
    if(mask & RIGHT && mask & FRONT)
        hOffset = 2;
    if(mask & FRONT && mask & LEFT)
        hOffset = 1;
    if(mask & RIGHT && mask & BACK)
        hOffset = 3;
    
    indicesRaw[0] = 0;
    indicesRaw[1] = 1;
    indicesRaw[2] = 3;
    indicesRaw[3] = 2;
    
    indices[0] = indicesRaw[(0 + hOffset)%4] + yOffset*4;
    indices[1] = indicesRaw[(1 + hOffset)%4] + yOffset*4;
    indices[2] = indicesRaw[(2 + hOffset)%4] + yOffset*4;
    indices[3] = indicesRaw[(3 + hOffset)%4] + yOffset*4;
    
    indices2[0] = indicesRaw[(0 + hOffset)%4] + (1-yOffset)*4;
    indices2[1] = indicesRaw[(1 + hOffset)%4] + (1-yOffset)*4;
    indices2[2] = indicesRaw[(2 + hOffset)%4] + (1-yOffset)*4;
    indices2[3] = indicesRaw[(3 + hOffset)%4] + (1-yOffset)*4;
    
    doubleBuffer->getIndiceBuffer()->getData()->clear();

    int cpt=0;
    
    if(mask & TOP)
    {
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[4*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+3], cpt++);

        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[5*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+3], cpt++);

        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[6*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[6*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[6*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[6*4+3], cpt++);
        //
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[6*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[6*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[6*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[6*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[5*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[7*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[7*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[7*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[7*4+3], cpt++);
    }
    if(mask & BOTTOM)
    {
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[0*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[0*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[0*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[0*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[1*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[2*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+3], cpt++);
        //
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[2*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[1*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[3*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[3*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[3*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[3*4+3], cpt++);
    }
    if(mask & LEFT)
    {
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[0*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[0*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[0*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[0*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[1*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[4*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+3], cpt++);
        //
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[4*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[1*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[5*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+3], cpt++);
    }
    if(mask & RIGHT)
    {
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[7*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[7*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[7*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[7*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[3*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[3*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[3*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[3*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[2*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+3], cpt++);
        //
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[7*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[7*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[7*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[7*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[2*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[6*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[6*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[6*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[6*4+3], cpt++);
    }
    if(mask & FRONT)
    {
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[1*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[1*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[3*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[3*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[3*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[3*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[5*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+3], cpt++);
        //
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[5*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[5*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[3*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[3*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[3*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[3*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[7*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[7*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[7*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[7*4+3], cpt++);
    }
    if(mask & BACK)
    {
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[4*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[2*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[0*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[0*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[0*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[0*4+3], cpt++);
        //
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[6*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[6*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[6*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[6*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[2*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[2*4+3], cpt++);
        
        doubleBuffer->setVertex((*doubleBuffer->getVertexBuffer()->getBase())[4*4+0],
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+1],
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+2], 0,
                                (*doubleBuffer->getVertexBuffer()->getBase())[4*4+3], cpt++);
    }

    doubleBuffer->getIndiceBuffer()->bind();
	// End of user code
}

