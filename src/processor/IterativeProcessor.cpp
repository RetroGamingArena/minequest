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
void IterativeProcessor::bufferizeOctreeEntry(OctreeEntry* octreeEntry, vector<GLuint>* buffer, int p, int q, int r, int size)
{
    int size_2 = (int)size>>1;
    
    Node* node = dynamic_cast<Node*>(octreeEntry);
    if(node != NULL)
    {
        int bufferizeX;
        int bufferizeY;
        int bufferizeZ;
        vector<int>* xs;
        vector<int>* ys;
        vector<int>* zs;
        
        xs = WorldGenerator::getXs();
        ys = WorldGenerator::getYs();
        zs = WorldGenerator::getZs();
        
        for(int i = 0; i < 8; i++)
        {
            bufferizeX = (*xs)[i];
            bufferizeY = (*ys)[i];
            bufferizeZ = (*zs)[i];
            
            if(node->getOctreeEntries()[i] != NULL)
                bufferizeOctreeEntry(node->getOctreeEntries()[i], buffer, p+bufferizeX*size_2, q+bufferizeY*size_2, r+bufferizeZ*size_2, size_2);
        }
        return;
    }
    Leaf* leaf = dynamic_cast<Leaf*>(octreeEntry);
    if(leaf != NULL)
    {
        bufferizeLeaf(leaf, buffer, p, q, r, size);//_2);
    }
}
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
                buildedTask = chunkProcessorTask;
                //mutex->unlock();
                return chunkProcessorTask;
            }
        mutex->unlock();
    }
    else
    {
        return buildedTask;
    }
    return NULL;
	// End of user code
}
vector<GLuint>* IterativeProcessor::bufferize(Octree * octree)
{
	// Start of user code bufferize
    vector<GLuint>* res = new vector<GLuint>();
    //VertexBuffer* vertexBuffer = new VertexBuffer();
    
    //octree->bufferize(vertexBuffer, 0, 0, 0);
    int x = 0;
    int y = 0;
    int z = 0;
    
    for(int i = 0; i < 8; i++)
    {
        x = (*WorldGenerator::getXs())[i];
        y = (*WorldGenerator::getYs())[i];
        z = (*WorldGenerator::getZs())[i];
        
        if(octree->getOctreeEntries()[i] != NULL)
            bufferizeOctreeEntry(octree->getOctreeEntries()[i], res, octree->getP()*Octree::size+x*Octree::size/2.0, octree->getQ()*Octree::size+y*Octree::size/2.0, octree->getR()*Octree::size+z*Octree::size/2.0, Octree::size/2);
    }
    
    
    //res->insert(res->end(), vertexBuffer->getData()->begin(), vertexBuffer->getData()->end());
    //delete vertexBuffer;
    return res;
	// End of user code
}





