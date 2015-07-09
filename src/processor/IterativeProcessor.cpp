#include <cstdlib>

#include "IterativeProcessor.h"
// Start of user code includes
#include "Engine.h"
#include "Chunk.h"
#include "ChunkProcessorTask.h"
// End of user code

IterativeProcessor::IterativeProcessor(int _chunkIndice)
{
	chunkIndice = _chunkIndice;
}

IterativeProcessor::IterativeProcessor()
// Start of user code super class
: Pool(8)
// End of user code
{
	// Start of user code constructor
    chunkIndice = -1;
	// End of user code
}

IterativeProcessor::~IterativeProcessor()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code

Task* IterativeProcessor::buildTask()
{
	// Start of user code buildTask
    if( mutex->try_lock())
    {
        std::vector<Chunk*> chunks = Engine::getInstance()->getWorld()->getChunks();
        Chunk* chunk = chunks[chunkIndice];
            
        World* world = Engine::getInstance()->getWorld();
        
        for(int i = 0; i < world->getChunks().size(); i++)
            if(!world->getChunks()[i]->getBuffered() && world->getChunks()[i]->getGenerated() && !world->getChunks()[i]->getBuffering() && !world->getChunks()[i]->getGenerating())
            {
                chunk = world->getChunks()[i];
                ChunkProcessorTask* chunkProcessorTask = new ChunkProcessorTask();
                chunkProcessorTask->setProcessor(this);
                chunkProcessorTask->setChunk(chunk);
                chunk->setBuffering(true);
                mutex->unlock();
                return chunkProcessorTask;
            }
        mutex->unlock();
    }
    else
    {
        mutex->unlock();
    }
    return NULL;
	// End of user code
}
vector<GLuint>* IterativeProcessor::bufferize(Octree * octree)
{
	// Start of user code bufferize
    
    VertexBuffer* vertexBuffer = new VertexBuffer();
    octree->bufferize(vertexBuffer, 0, 0, 0);
    vector<GLuint>* res = new vector<GLuint>();
    res->insert(res->end(), vertexBuffer->getData()->begin(), vertexBuffer->getData()->end());
    delete vertexBuffer;
    return res;
	// End of user code
}





