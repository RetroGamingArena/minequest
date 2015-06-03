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
    
    //V
    doubleBuffer->bufferizeIndice(indices[0]);
    doubleBuffer->bufferizeIndice(indices[1]);
    doubleBuffer->bufferizeIndice(indices[2]);
    
    doubleBuffer->bufferizeIndice(indices[0]);
    doubleBuffer->bufferizeIndice(indices[2]);
    doubleBuffer->bufferizeIndice(indices[3]);
    
    //L
    
    doubleBuffer->bufferizeIndice(indices2[1]);
    doubleBuffer->bufferizeIndice(indices[1]);
    doubleBuffer->bufferizeIndice(indices[0]);
    
    doubleBuffer->bufferizeIndice(indices2[0]);
    doubleBuffer->bufferizeIndice(indices2[1]);
    doubleBuffer->bufferizeIndice(indices[0]);
    
    //R
    doubleBuffer->bufferizeIndice(indices[0]);
    doubleBuffer->bufferizeIndice(indices[3]);
    doubleBuffer->bufferizeIndice(indices2[3]);
    
    doubleBuffer->bufferizeIndice(indices[0]);
    doubleBuffer->bufferizeIndice(indices2[3]);
    doubleBuffer->bufferizeIndice(indices2[0]);
    
    doubleBuffer->getIndiceBuffer()->bind();
	// End of user code
}

