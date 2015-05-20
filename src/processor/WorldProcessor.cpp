#include <cstdlib>

#include "WorldProcessor.h"
// Start of user code includes
// End of user code


WorldProcessor::WorldProcessor()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

WorldProcessor::~WorldProcessor()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code





void WorldProcessor::process()
{
	// Start of user code process
    threadCount = 5;
    this->start();
    while(isRunning()){}
    
	// End of user code
}

World* WorldProcessor::getWorld()
{
	// Start of user code getWorld
	// End of user code
	return world;
}

void WorldProcessor::setWorld(World* _world)
{
	world = _world;
}
					
