#include <cstdlib>

#include "GameScene.h"
// Start of user code includes
#include "Chunk.h"
#include "ItemCamera.h"
// End of user code


GameScene::GameScene()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

GameScene::~GameScene()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
GameScene::GameScene(Player* player)
{
    ItemCamera* itemCamera = new ItemCamera();
    itemCamera->setItem(player);
    cameras.push_back(itemCamera);
    items.push_back(player);
}
// End of user code





void GameScene::reset()
{
	// Start of user code reset
    int x = 0;
    int y = 0;
    int z = 0;
    
    int p = 0;
    int q = 0;
    int r = 0;
    
    float size = 1.0 / Chunk::subsize;
    
    float type = 2;
    
    float* ao = new float[4];
    
    ao[0] = 0;
    ao[1] = 0;
    ao[2] = 0;
    ao[3] = 0;
    
    doubleBuffer->bufferizeSquare(x+p, y+q,      z+r, x+p+size, y+q,      z+r+size, type, ao);
    
    ao[0] = 1;
    ao[1] = 1;
    ao[2] = 1;
    ao[3] = 1;
    
    doubleBuffer->bufferizeSquare(x+p, y+q+size, z+r, x+p+size, y+q+size, z+r+size, type, ao); //top
    
    doubleBuffer->bufferizeIndice(0);
    doubleBuffer->bufferizeIndice(1);
    doubleBuffer->bufferizeIndice(2);
    doubleBuffer->bufferizeIndice(3);
    
    doubleBuffer->bufferizeIndice(0);
    doubleBuffer->bufferizeIndice(1);
    doubleBuffer->bufferizeIndice(4);
    doubleBuffer->bufferizeIndice(5);
    
    
    doubleBuffer->bufferizeIndice(1);
    doubleBuffer->bufferizeIndice(3);
    doubleBuffer->bufferizeIndice(5);
    doubleBuffer->bufferizeIndice(7);
    
    
    doubleBuffer->bufferizeIndice(3);
    doubleBuffer->bufferizeIndice(2);
    doubleBuffer->bufferizeIndice(7);
    doubleBuffer->bufferizeIndice(6);
    
    doubleBuffer->bufferizeIndice(2);
    doubleBuffer->bufferizeIndice(0);
    doubleBuffer->bufferizeIndice(6);
    doubleBuffer->bufferizeIndice(4);
    
    doubleBuffer->bufferizeIndice(4);
    doubleBuffer->bufferizeIndice(5);
    doubleBuffer->bufferizeIndice(6);
    doubleBuffer->bufferizeIndice(7);
	// End of user code
}

vector<Item*> GameScene::getItems()
{
	// Start of user code getItems
	// End of user code
	return items;
}

void GameScene::setItemsAt(Item* _items, int indice)
{
	items[indice] = _items;
}

