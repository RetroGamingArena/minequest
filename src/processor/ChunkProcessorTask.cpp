#include <cstdlib>

#include "ChunkProcessorTask.h"
// Start of user code includes
// End of user code


ChunkProcessorTask::ChunkProcessorTask()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

ChunkProcessorTask::~ChunkProcessorTask()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code

void ChunkProcessorTask::run()
{
	// Start of user code run
    chunk->bufferize();//chunk->getVertexBuffer());
	// End of user code
}





Chunk* ChunkProcessorTask::getChunk()
{
	// Start of user code getChunk
	// End of user code
	return chunk;
}

void ChunkProcessorTask::setChunk(Chunk* _chunk)
{
	chunk = _chunk;
}
					
