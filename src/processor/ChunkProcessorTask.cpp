#include <cstdlib>

#include "ChunkProcessorTask.h"
// Start of user code includes
#include <iostream>
// End of user code


ChunkProcessorTask::ChunkProcessorTask()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    int a = 2;
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
    chunk->getVertexBuffer()->getData()->clear();
    
    double currentTime = glfwGetTime();
    //vector<GLuint>* temp = processor->bufferize(chunk);
    currentTime = glfwGetTime() - currentTime;
    std::cout << currentTime << std::endl;
    //chunk->getVertexBuffer()->getData()->insert(chunk->getVertexBuffer()->getData()->end(), temp->begin(), temp->end());
    //temp->clear();
    //delete temp;
    chunk->setBuffered(true);
    chunk->setBuffering(false);
    // End of user code
}





Processor* ChunkProcessorTask::getProcessor()
{
	// Start of user code getProcessor
	// End of user code
	return processor;
}

void ChunkProcessorTask::setProcessor(Processor* _processor)
{
	processor = _processor;
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
					
