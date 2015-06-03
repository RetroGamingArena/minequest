#ifndef __GameScene__
#define __GameScene__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>
#include <noise/noise.h>
#include "noiseutils.h"

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
#include "Player.h"
// End of user code

#include "VoxelScene.h"
#include "Listener.h"

#include "WorldProcessor.h"
#include "Item.h"

using namespace std;

// Start of user code class import
// End of user code

class GameScene : public VoxelScene, public Listener
{
	WorldProcessor* worldProcessor;
	vector<Item*> items;
	int chunksOffset;
	bool updateChunks;
	bool updateBuffer;

	protected:

	public:
		// Start of user code public
        GameScene(Player* player);
		// End of user code
		GameScene(int _chunksOffset, bool _updateChunks, bool _updateBuffer);
		GameScene();
		~GameScene();
		int getChunksOffset();
		void setChunksOffset(int _chunksOffset);
		bool getUpdateChunks();
		void setUpdateChunks(bool _updateChunks);
		bool getUpdateBuffer();
		void setUpdateBuffer(bool _updateBuffer);
		void reset();
		void render();
		void refreshItemsBuffer();
		void onKey(int key, int scancode, int action, int mods);
		WorldProcessor* getWorldProcessor();
		void setWorldProcessor(WorldProcessor* _worldProcessor);
		vector<Item*> getItems();
		void setItemsAt(Item* _items, int indice);
		void handle(Event * event);
};

#endif
