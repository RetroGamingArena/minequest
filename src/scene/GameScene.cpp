#include <cstdlib>

#include "GameScene.h"
// Start of user code includes
#include "Chunk.h"
#include "ChunkTask.h"
#include "ItemCamera.h"
#include "Engine.h"
#include "ChunkProcessorTask.h"
// End of user code

GameScene::GameScene(int _chunksOffset, bool _updateChunks, bool _updateBuffer, int _updateChunksCpt, std::mutex* _bufferAddMutex, int _updateBufferCpt)
{
	chunksOffset = _chunksOffset;
	updateChunks = _updateChunks;
	updateBuffer = _updateBuffer;
	updateChunksCpt = _updateChunksCpt;
	bufferAddMutex = _bufferAddMutex;
	updateBufferCpt = _updateBufferCpt;
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
    worldProcessor->setThreadCount(9);
    ItemCamera* itemCamera = new ItemCamera();
    itemCamera->setItem(player);
    cameras.push_back(itemCamera);
    items.push_back(player);
    
    cameras[0]->addListener(this);
    
    Chunk* first = Engine::getInstance()->getWorld()->getChunk(player->getX(), player->getY(), player->getZ());
    ChunkProcessorTask* task = new ChunkProcessorTask();
    task->setProcessor(worldProcessor);
    task->setChunk(first);
    task->run();
    //first->setBuffered(true);
    
    reset();
    
    vector<GLfloat>* gameSceneData = getDoubleBuffer()->getVertexBuffer()->getData();
    
    vector<GLfloat>* chunkData = first->getVertexBuffer()->getData();
        
    gameSceneData->insert(gameSceneData->end(), chunkData->begin(), chunkData->end());
    chunkData->clear();
    
    
    setChunksOffset(gameSceneData->size());
    
    for(int i=0; i < items.size() ; i++)
        getItems()[0]->draw(getDoubleBuffer()->getVertexBuffer());
    
    worldProcessor->setWorld(Engine::getInstance()->getWorld());
    
    updateBuffer = false;
    updateChunks = true;
    
    Engine::getInstance()->getWorld()->addListener(this);
    worldProcessor->addListener(this);
    
    updateChunksCpt = 0;
    updateBufferCpt = 0;
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
            updateIndices();
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
            {
                updateChunksCpt++;
                updateBuffer = true;
                return;
            }
            ChunkProcessorTask* chunkProcessorTask = dynamic_cast<ChunkProcessorTask*>(task);
            if(chunkProcessorTask != NULL)
            {
                updateChunksCpt--;
                updateBufferCpt++;
                return;
            }
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

int GameScene::getUpdateChunksCpt()
{
	// Start of user code getUpdateChunksCpt
	// End of user code
	return updateChunksCpt;
}

void GameScene::setUpdateChunksCpt(int _updateChunksCpt)
{
	updateChunksCpt = _updateChunksCpt;
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

int GameScene::getUpdateBufferCpt()
{
	// Start of user code getUpdateBufferCpt
	// End of user code
	return updateBufferCpt;
}

void GameScene::setUpdateBufferCpt(int _updateBufferCpt)
{
	updateBufferCpt = _updateBufferCpt;
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
    
    updateIndices();

	// End of user code
}
void GameScene::render()
{
	// Start of user code render
    if(updateChunks)
    {
        World* world = Engine::getInstance()->getWorld();
        if(!world->isRunning() && !world->getStarted())
        {
            world->start();
        }
        else if(world->getStarted() && !world->isRunning())
        {
            updateChunks = false;
            //updateBuffer = true;
        }
    }
    if(updateChunksCpt > 0)
    {
        if(!worldProcessor->isRunning() && !worldProcessor->getStarted())
            worldProcessor->start();
        /*else if(worldProcessor->getStarted() && !worldProcessor->isRunning())
        {
            vector<GLfloat>* gameSceneData = doubleBuffer->getVertexBuffer()->getData();
            
            for(int i=0; i < Engine::getInstance()->getWorld()->getChunks().size() ; i++)
            {
                Chunk* chunk = Engine::getInstance()->getWorld()->getChunks()[i];
                
                vector<GLfloat>* chunkData = chunk->getVertexBuffer()->getData();
                
                gameSceneData->insert(gameSceneData->end(), chunkData->begin(), chunkData->end());
                chunkData->clear();
            }
            
            setChunksOffset(gameSceneData->size());
            
            //
            for(int i=0; i < items.size() ; i++)
            {
                items[0]->draw(doubleBuffer->getVertexBuffer());
            }
            
            worldProcessor->setStarted(false);
            updateChunksCpt--;
            updateBuffer = false;
        }*/
    }
    if(updateBufferCpt > 0)
    {
        vector<GLfloat>* gameSceneData = doubleBuffer->getVertexBuffer()->getData();
        
        for(int i=0; i < Engine::getInstance()->getWorld()->getChunks().size(); i++)
        {
            Chunk* chunk = Engine::getInstance()->getWorld()->getChunks()[i];
            
            if(chunk->getBuffered() && chunk->getVertexBuffer()->getData()->size() > 0)
            {
                vector<GLfloat>* chunkData = chunk->getVertexBuffer()->getData();
                gameSceneData->insert(gameSceneData->end(), chunkData->begin(), chunkData->end());
                chunkData->clear();
                updateBufferCpt--;
            }
        }
        
        setChunksOffset(gameSceneData->size());
        
        //
        for(int i=0; i < items.size() ; i++)
        {
            items[0]->draw(doubleBuffer->getVertexBuffer());
        }
        
        worldProcessor->setStarted(false);
        updateBuffer = false;
    }
    
    bool refresh = false;
    for(int i = 0; i < items.size(); i++)
        if(items[i]->live(Engine::getInstance()->getDt()))
            refresh = true;
    if(refresh)
        refreshItemsBuffer();
    VoxelScene::render();
	// End of user code
}
void GameScene::refreshItemsBuffer()
{
	// Start of user code refreshItemsBuffer
    int offset = chunksOffset;
    
    vector<GLfloat>* datas =  doubleBuffer->getVertexBuffer()->getData();
    
    doubleBuffer->getVertexBuffer()->getData()->erase(datas->begin()+offset, datas->end());
    for(int i=0; i < items.size() ; i++)
        items[0]->draw(doubleBuffer->getVertexBuffer());
    doubleBuffer->getVertexBuffer()->bind();
	// End of user code
}
void GameScene::onKey(int key, int scancode, int action, int mods)
{
	// Start of user code onKey
	// End of user code
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

