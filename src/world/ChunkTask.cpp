#include <cstdlib>

#include "ChunkTask.h"
// Start of user code includes
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
    chunk->setOctree(worldGenerator->generate(chunk->getP(), chunk->getQ(), chunk->getR()));
    chunk->setGenerated(true);
    chunk->setGenerating(false);
    //chunk->generate(worldGenerator);
	// End of user code
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
					
