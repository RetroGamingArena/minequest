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
// End of user code
{
	// Start of user code constructor
    this->uI = new LoadingUI();
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
        
        Engine::getInstance()->getWorldProcessor()->bufferize(gameScene, Engine::getInstance()->getWorld());
        
        //gameScene->bindBuffer();
        Engine::getInstance()->setScene(gameScene);
        Engine::getInstance()->getPlayer()->setFalling(true);
        mutex->unlock();
    }
}
// End of user code



std::mutex* LoadingScene::mutex = new std::mutex();	

std::thread* LoadingScene::getThread()
{
	return thread;
}

void LoadingScene::setThread(std::thread* _thread)
{
	thread = _thread;
}
std::mutex* LoadingScene::getMutex()
{
	return mutex;
}

void LoadingScene::setMutex(std::mutex* _mutex)
{
	mutex = _mutex;
}

void LoadingScene::initWorld()
{
	// Start of user code initWorld
    Engine::getInstance()->setWorld(new World());
    mutex->unlock();
	// End of user code
}

