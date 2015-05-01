#include <cstdlib>

#include "Engine.h"

Engine* Engine::instance = NULL;

void Engine::run()
{

}

Engine* Engine::getInstance()
{
	return instance;
}
