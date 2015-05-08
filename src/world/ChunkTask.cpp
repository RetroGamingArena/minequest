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

// Start of user code methods
ChunkTask::ChunkTask(Chunk* chunk, WorldGenerator* worldGenerator)
{

}
// End of user code

void ChunkTask::run(Pool * pool)
{
	// Start of user code run
    chunk->generate(worldGenerator);
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
					
