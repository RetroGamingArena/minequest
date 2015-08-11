#include <cstdlib>

#include "LoadingScene.h"
// Start of user code includes
#include "LoadingUI.h"
#include "GameScene.h"
#include "Engine.h"
// End of user code

LoadingScene::LoadingScene(std::thread* _thread, std::mutex* _mutex)
{
	thread = _thread;
	mutex = _mutex;
}

LoadingScene::LoadingScene()
// Start of user code super class
: VBOScene()
// End of user code
{
	// Start of user code constructor
    thread = NULL;
    this->uI = new LoadingUI();
    background = NULL;
	// End of user code
}

LoadingScene::~LoadingScene()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
void LoadingScene::render()
{
    VBOScene::render();
    if(thread == NULL)
    {
        thread = new std::thread (initWorld);
        mutex->lock();
    }
    if(mutex->try_lock())
    {
        GameScene* gameScene = new GameScene(Engine::getInstance()->getPlayer());
        gameScene->init();
        
        Engine* engine = Engine::getInstance();
        
        
        gameScene->getDoubleBuffer()->getVertexBuffer()->bind();
        gameScene->getDoubleBuffer()->getIndiceBuffer()->bind();
        
        engine->setScene(gameScene);
        engine->getPlayer()->setFalling(true);
        
        engine->refresh();

        mutex->unlock();
    }
}
// End of user code



std::mutex* LoadingScene::mutex = new std::mutex();	

std::thread* LoadingScene::getThread()
{
	// Start of user code getThread
	// End of user code
	return thread;
}

void LoadingScene::setThread(std::thread* _thread)
{
	thread = _thread;
}

std::mutex* LoadingScene::getMutex()
{
	// Start of user code getMutex
	// End of user code
	return mutex;
}

void LoadingScene::setMutex(std::mutex* _mutex)
{
	mutex = _mutex;
}


void LoadingScene::initWorld()
{
	// Start of user code initWorld
    Engine* engine = Engine::getInstance();
    World* world = new World();
    //engine->getWorldProcessor()->setWorld(world);
    Processor::bufferizeWorld = world;
    Engine::getInstance()->setWorld(world);
    mutex->unlock();
	// End of user code
}

