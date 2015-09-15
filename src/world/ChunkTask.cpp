#include <cstdlib>

#include "ChunkTask.h"
// Start of user code includes
#include <iostream>
// End of user code


ChunkTask::ChunkTask()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

ChunkTask::~ChunkTask()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
ChunkTask::ChunkTask(Chunk* _chunk, WorldGenerator* _worldGenerator)
{
    chunk = _chunk;
    worldGenerator = _worldGenerator;
}
// End of user code

void ChunkTask::run()
{
	// Start of user code run
    double currentTime = glfwGetTime();
    
    worldGenerator->generate(chunk, chunk->getP(), chunk->getQ(), chunk->getR());
    
    currentTime = glfwGetTime() - currentTime;
    std::cout << currentTime << std::endl;
    chunk->setGenerated(true);
    chunk->setGenerating(false);
    // End of user code
}





WorldGenerator* ChunkTask::getWorldGenerator()
{
	// Start of user code getWorldGenerator
	// End of user code
	return worldGenerator;
}

void ChunkTask::setWorldGenerator(WorldGenerator* _worldGenerator)
{
	worldGenerator = _worldGenerator;
}
					
Chunk* ChunkTask::getChunk()
{
	// Start of user code getChunk
	// End of user code
	return chunk;
}

void ChunkTask::setChunk(Chunk* _chunk)
{
	chunk = _chunk;
}
					
