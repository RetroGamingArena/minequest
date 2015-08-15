#include <cstdlib>

#include "GameScene.h"
// Start of user code includes
#include "Chunk.h"
#include "ChunkTask.h"
#include "ItemCamera.h"
#include "Engine.h"
#include "ChunkProcessorTask.h"
#include <iostream>
// End of user code

GameScene::GameScene(int _chunksOffset, bool _updateChunks, bool _updateBuffer, int _updateChunksCpt, std::mutex* _bufferAddMutex, int _updateBufferCpt, unsigned char _oldMask, std::mutex* _cameraLock)
{
	chunksOffset = _chunksOffset;
	updateChunks = _updateChunks;
	updateBuffer = _updateBuffer;
	bufferAddMutex = _bufferAddMutex;
	oldMask = _oldMask;
	cameraLock = _cameraLock;
}

GameScene::GameScene()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    background = new Background();
    worldProcessor = new WorldProcessor();
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
    //GameScene();
    background = new Background();
    worldProcessor = new WorldProcessor();
    ItemCamera* itemCamera = new ItemCamera();
    itemCamera->setItem(player);
    cameras.push_back(itemCamera);
    setSelectedCameraIndex(getSelectedCameraIndex());
    items.push_back(player);
    
    for(int i = 0; i  <cameras.size(); i++)
        cameras[i]->addListener(this);

    reset();
    
    vector<GLuint>* gameSceneData = getDoubleBuffer()->getVertexBuffer()->getData();
    
    setChunksOffset(gameSceneData->size());

    worldProcessor->setWorld(Engine::getInstance()->getWorld());
    
    updateBuffer = false;
    updateChunks = true;
    
    Engine::getInstance()->getWorld()->addListener(this);
    worldProcessor->addListener(this);
    
    selectedCameraIndex = 1;

    oldMask = getSelectedCamera()->getMask();
    cameraLock = new mutex();
    
    background = new Background();
    
}
// End of user code

void GameScene::handle(Event * event)
{
	// Start of user code handle
    if(event->getID() == Event::ID_CHANGED && event->getSource() != NULL)
    {
        Camera* camera = dynamic_cast<Camera*>((Transmitter*)event->getSource());
        if(camera != NULL)
        {
            cameraLock->lock();
            camera = getSelectedCamera();
            projection = camera->getProjection();
            VM = camera->getView()*camera->getModel();
            unsigned char mask = camera->getMask();
            
            if(mask != oldMask)
            {
                _updateIndices = true;
                oldMask = mask;
            }

            if(worldProcessor->isFinished() && !worldProcessor->isRunning())
            {
                /*World* world = Engine::getInstance()->getWorld();
                    
                world->setCubeCount(0);
                world->setInstanceCount(0);
                world->setOccludedCount(0);
                    
                vector<Chunk*> chunks = Engine::getInstance()->getWorld()->getChunks();
                    
                for(int i = 0; i < chunks.size(); i++)
                    chunks[i]->setBuffered(false);*/
                updateBuffer = true;
            }
            updateCamera = true;
            cameraLock->unlock();
            return;
        }
    }
    if(event->getID() == Event::ID_FINISHED && event->getSource() != NULL)
    {
        Thread* thread = dynamic_cast<Thread*>((Transmitter*)event->getSource());
        if(thread != NULL)
        {
            Task* task = thread->getTask();
            ChunkTask* chunkTask = dynamic_cast<ChunkTask*>(task);
            if(chunkTask != NULL)
                return;
            ChunkProcessorTask* chunkProcessorTask = dynamic_cast<ChunkProcessorTask*>(task);
            if(chunkProcessorTask != NULL)
                return;
        }
    }
    // End of user code
}



int GameScene::getChunksOffset()
{
	// Start of user code getChunksOffset
	// End of user code
	return chunksOffset;
}

void GameScene::setChunksOffset(int _chunksOffset)
{
	chunksOffset = _chunksOffset;
}

bool GameScene::getUpdateChunks()
{
	// Start of user code getUpdateChunks
	// End of user code
	return updateChunks;
}

void GameScene::setUpdateChunks(bool _updateChunks)
{
	updateChunks = _updateChunks;
}

bool GameScene::getUpdateBuffer()
{
	// Start of user code getUpdateBuffer
	// End of user code
	return updateBuffer;
}

void GameScene::setUpdateBuffer(bool _updateBuffer)
{
	updateBuffer = _updateBuffer;
}

std::mutex* GameScene::getBufferAddMutex()
{
	// Start of user code getBufferAddMutex
	// End of user code
	return bufferAddMutex;
}

void GameScene::setBufferAddMutex(std::mutex* _bufferAddMutex)
{
	bufferAddMutex = _bufferAddMutex;
}

unsigned char GameScene::getOldMask()
{
	// Start of user code getOldMask
	// End of user code
	return oldMask;
}

void GameScene::setOldMask(unsigned char _oldMask)
{
	oldMask = _oldMask;
}

std::mutex* GameScene::getCameraLock()
{
	// Start of user code getCameraLock
	// End of user code
	return cameraLock;
}

void GameScene::setCameraLock(std::mutex* _cameraLock)
{
	cameraLock = _cameraLock;
}


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
    
    ao[0] = 1;
    ao[1] = 1;
    ao[2] = 1;
    ao[3] = 1;
    
    doubleBuffer->bufferizeSquare(x+p, y+q,      z+r, x+p+size, y+q,      z+r+size, type, ao);
    
    ao[0] = 1;
    ao[1] = 1;
    ao[2] = 1;
    ao[3] = 1;
    
    doubleBuffer->bufferizeSquare(x+p, y+q+size, z+r, x+p+size, y+q+size, z+r+size, type, ao); //top
    
    doubleBuffer->getVertexBuffer()->getData()->resize(96);
    updateIndices();

	// End of user code
}
void GameScene::render()
{
	// Start of user code render
    World* world = Engine::getInstance()->getWorld();
    if(updateChunks)
    {
        
        if(!world->isRunning())
        {
            world->start();
            updateChunks = false;
        }
    }
    if(world->isFinished() && !worldProcessor->isFinished())
    //if(updateChunksCpt >= world->getChunks().size()-1)
    {
        if(!worldProcessor->isRunning() && !worldProcessor->buffered)
        {
            worldProcessor->start();
            updateBuffer = true;
        }
    }
    if(worldProcessor->isFinished() && updateBuffer)//updateBufferCpt == world->getChunks().size()-1)
    {
        if(!worldProcessor->buffered)
            worldProcessor->buffered = true;

        vector<GLuint>* gameSceneData = doubleBuffer->getVertexBuffer()->getData();
        
        vector<GLuint>* temp = new vector<GLuint>();
        
        worldProcessor->bufferizeVoxels(temp);
        
        gameSceneData->erase(gameSceneData->begin()+96, gameSceneData->end());
        gameSceneData->insert(gameSceneData->end(), temp->begin(), temp->end());
        temp->clear();
        delete temp;
        /*vector<GLuint>* gameSceneData = doubleBuffer->getVertexBuffer()->getData();
        
        gameSceneData->erase(gameSceneData->begin()+96, gameSceneData->end());
        
        for(int i=0; i < Engine::getInstance()->getWorld()->getChunks().size(); i++)
        {
            Chunk* chunk = Engine::getInstance()->getWorld()->getChunks()[i];
            
            if(chunk->getBuffered() && chunk->getVertexBuffer()->getData()->size() > 0)
            {
                vector<GLuint>* chunkData = chunk->getVertexBuffer()->getData();
                gameSceneData->insert(gameSceneData->end(), chunkData->begin(), chunkData->end());
            }
        }*/
        
        setChunksOffset(gameSceneData->size());
        
        //
        for(int i=0; i < items.size() ; i++)
        {
            items[0]->draw(doubleBuffer->getVertexBuffer());
        }
        
        doubleBuffer->getVertexBuffer()->bind();
        
        worldProcessor->setStarted(false);
        updateBuffer = false;
    }
    
    bool refresh = false;
    for(int i = 0; i < items.size(); i++)
        if(items[i]->live(Engine::getInstance()->getDt()))
            refresh = true;
    if(refresh)
    {
        getSelectedCamera()->look();
        refreshItemsBuffer();
    }
    VoxelScene::render();
	// End of user code
}
void GameScene::refreshItemsBuffer()
{
	// Start of user code refreshItemsBuffer
    int offset = chunksOffset;
    
    vector<GLuint>* datas =  doubleBuffer->getVertexBuffer()->getData();
    
    doubleBuffer->getVertexBuffer()->getData()->erase(datas->begin()+offset, datas->end());
    for(int i=0; i < items.size() ; i++)
        items[i]->draw(doubleBuffer->getVertexBuffer());
    doubleBuffer->getVertexBuffer()->bind();
	// End of user code
}
void GameScene::onKey(int key, int scancode, int action, int mods)
{
	// Start of user code onKey
    VoxelScene::onKey(key, scancode, action, mods);
    if(action == GLFW_RELEASE && key == GLFW_KEY_SPACE)
    {
        items[0]->setDy(24);
    }
    else if(action == GLFW_RELEASE && key == GLFW_KEY_W)
    {
        items[0]->setDz(1);
    }
    else if(action == GLFW_RELEASE && key == GLFW_KEY_A)
    {
        items[0]->setDx(-1);
    }
    else if(action == GLFW_RELEASE && key == GLFW_KEY_S)
    {
        items[0]->setDz(-1);
    }
    else if(action == GLFW_RELEASE && key == GLFW_KEY_D)
    {
        items[0]->setDx(1);
    }
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

WorldProcessor* GameScene::getWorldProcessor()
{
	// Start of user code getWorldProcessor
	// End of user code
	return worldProcessor;
}

void GameScene::setWorldProcessor(WorldProcessor* _worldProcessor)
{
	worldProcessor = _worldProcessor;
}
					
