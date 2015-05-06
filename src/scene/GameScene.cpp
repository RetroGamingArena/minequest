#include <cstdlib>

#include "GameScene.h"
// Start of user code includes
// End of user code


GameScene::GameScene()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

// Start of user code methods
GameScene::GameScene(Player* player)
{
    items.push_back(player);
}
// End of user code






vector<Item*> GameScene::getItems()
{
	// Start of user code getItems
	// End of user code
	return items;
}

