#include <cstdlib>

#include "VBOScene.h"
// Start of user code includes
// End of user code


VBOScene::VBOScene()
{
	// Start of user code constructor
    doubleBuffer = new DoubleBuffer();
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
					
