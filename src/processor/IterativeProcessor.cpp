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
: Pool(4)
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

vector<GLuint>* IterativeProcessor::bufferize(Octree * octree)
{
	// Start of user code bufferize
    /*int x = 0;
    int y = 0;
    int z = 0;
    
    int p = 0;
    int q = 0;
    int r = 0;
    
    float size = 1.0 / Chunk::subsize;
    
    float type = 2;*/
    
    float* ao = new float[4];
    
    /*ao[0] = 0;
    ao[1] = 0;
    ao[2] = 0;
    ao[3] = 0;
    
    gameScene->getDoubleBuffer()->bufferizeSquare(x+p, y+q,      z+r, x+p+size, y+q,      z+r+size, type, ao);
    
    ao[0] = 1;
    ao[1] = 1;
    ao[2] = 1;
    ao[3] = 1;
    
    gameScene->getDoubleBuffer()->bufferizeSquare(x+p, y+q+size, z+r, x+p+size, y+q+size, z+r+size, type, ao); //top
    
    gameScene->getDoubleBuffer()->bufferizeIndice(0);
    gameScene->getDoubleBuffer()->bufferizeIndice(1);
    gameScene->getDoubleBuffer()->bufferizeIndice(2);
    gameScene->getDoubleBuffer()->bufferizeIndice(3);
    
    gameScene->getDoubleBuffer()->bufferizeIndice(0);
    gameScene->getDoubleBuffer()->bufferizeIndice(1);
    gameScene->getDoubleBuffer()->bufferizeIndice(4);
    gameScene->getDoubleBuffer()->bufferizeIndice(5);
    
    
    gameScene->getDoubleBuffer()->bufferizeIndice(1);
    gameScene->getDoubleBuffer()->bufferizeIndice(3);
    gameScene->getDoubleBuffer()->bufferizeIndice(5);
    gameScene->getDoubleBuffer()->bufferizeIndice(7);
    
    
    gameScene->getDoubleBuffer()->bufferizeIndice(3);
    gameScene->getDoubleBuffer()->bufferizeIndice(2);
    gameScene->getDoubleBuffer()->bufferizeIndice(7);
    gameScene->getDoubleBuffer()->bufferizeIndice(6);
    
    gameScene->getDoubleBuffer()->bufferizeIndice(2);
    gameScene->getDoubleBuffer()->bufferizeIndice(0);
    gameScene->getDoubleBuffer()->bufferizeIndice(6);
    gameScene->getDoubleBuffer()->bufferizeIndice(4);
    
    gameScene->getDoubleBuffer()->bufferizeIndice(4);
    gameScene->getDoubleBuffer()->bufferizeIndice(5);
    gameScene->getDoubleBuffer()->bufferizeIndice(6);
    gameScene->getDoubleBuffer()->bufferizeIndice(7);*/
    
    //threadCount = 5;
    //this->start();
    //while(isRunning()){}
    
    //vector<GLfloat>* gameSceneData = gameScene->getDoubleBuffer()->getVertexBuffer()->getData();
    
    //for(int i=0; i < world->getChunks().size() ; i++)
    {
        //Chunk* chunk = world->getChunks()[i];
        
        //vector<GLfloat>* chunkData = chunk->getVertexBuffer()->getData();
        
        //gameSceneData->insert(gameSceneData->end(), chunkData->begin(), chunkData->end());
      //  chunkData->clear();
        //delete chunk->getOctree();
    }
    
    VertexBuffer* vertexBuffer = new VertexBuffer();
    octree->bufferize(vertexBuffer, 0, 0, 0);
    vector<GLuint>* res = new vector<GLuint>();
    res->insert(res->end(), vertexBuffer->getData()->begin(), vertexBuffer->getData()->end());
    delete vertexBuffer;
    return res;
    //gameScene->getDoubleBuffer()->getIndiceBuffer()->bind();
    
    return NULL;
	// End of user code
}
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





