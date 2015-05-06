#ifndef __GameScene__
#define __GameScene__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
#include "Player.h"
// End of user code

#include "VoxelScene.h"

#include "Item.h"

using namespace std;

class GameScene : public VoxelScene
{
	vector<Item*> items;

	protected:

	public:
		// Start of user code public
        GameScene(Player* player);
		// End of user code
		GameScene();
		vector<Item*> getItems();
};

#endif
