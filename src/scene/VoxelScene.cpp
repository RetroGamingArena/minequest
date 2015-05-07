#include <cstdlib>

#include "VoxelScene.h"
// Start of user code includes
#include "DebugUI.h"
// End of user code


VoxelScene::VoxelScene()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    this->uI = new DebugUI();
	// End of user code
}

// Start of user code methods
// End of user code





void VoxelScene::render()
{
	// Start of user code render
    VBOScene::render();
    glClearColor(0.5f, 0.9f, 1.0f, 0.0f);
	// End of user code
}

