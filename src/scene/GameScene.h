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

// Start of user code defines
// End of user code

// Start of user code includes
#include "Player.h"
// End of user code

#include "VoxelScene.h"
#include "Listener.h"

#include "Item.h"
#include "WorldProcessor.h"

using namespace std;

// Start of user code class import
// End of user code

class GameScene : public VoxelScene, public Listener
{
	// Start of user code private
	// End of user code
	vector<Item*> items;
	WorldProcessor* worldProcessor;
	int chunksOffset;
	bool updateChunks;
	bool updateBuffer;
    bool updateVoxels;
	std::mutex* bufferAddMutex;
	unsigned char oldMask;
	std::mutex* cameraLock;
    Thread* voxelsThread;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
        GameScene(Player* player);
		// End of user code
		GameScene(int _chunksOffset, bool _updateChunks, bool _updateBuffer, int _updateChunksCpt, std::mutex* _bufferAddMutex, int _updateBufferCpt, unsigned char _oldMask, std::mutex* _cameraLock);
		GameScene();
		~GameScene();
		int getChunksOffset();
		void setChunksOffset(int _chunksOffset);
		bool getUpdateChunks();
		void setUpdateChunks(bool _updateChunks);
		bool getUpdateBuffer();
		void setUpdateBuffer(bool _updateBuffer);
		std::mutex* getBufferAddMutex();
		void setBufferAddMutex(std::mutex* _bufferAddMutex);
		unsigned char getOldMask();
		void setOldMask(unsigned char _oldMask);
		std::mutex* getCameraLock();
		void setCameraLock(std::mutex* _cameraLock);
		void reset();
		void render();
		void refreshItemsBuffer();
		void onKey(int key, int scancode, int action, int mods);
		vector<Item*> getItems();
		void setItemsAt(Item* _items, int indice);
		WorldProcessor* getWorldProcessor();
		void setWorldProcessor(WorldProcessor* _worldProcessor);
		void handle(Event * event);
};

#endif
