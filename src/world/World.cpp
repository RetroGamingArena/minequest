#include <cstdlib>

#include "World.h"
// Start of user code includes
#include "PerlinGenerator.h"
#include "ChunkTask.h"
#include "Chunk.h"
// End of user code

World::World(int _size, int _chunkIndice)
{
	size = _size;
	chunkIndice = _chunkIndice;
}

World::World()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    worldGenerator = new PerlinGenerator();
    
    for(int p=-size; p<=size; p++)
        for(int r=-size; r<=size; r++)
        {
            Chunk* chunk = new Chunk(p,0,r);
            //chunk->generate(generator);
            chunks.push_back(chunk);
        }
    
    threadCount = 5;
    this->start();
    while(getRunning()){}
	// End of user code
}

// Start of user code methods
// End of user code

Task* World::buildTask()
{
	// Start of user code buildTask
    if( mutex->try_lock() && hasNext())
    {
        Chunk* chunk = chunks[chunkIndice];
        ChunkTask* chunkTask = new ChunkTask(chunk, worldGenerator);
        chunkIndice = chunkIndice+1;
        mutex->unlock();
        return chunkTask;
    }
    return NULL;
	// End of user code
}
bool World::hasNext()
{
	// Start of user code hasNext
    return chunkIndice < chunks.size();
	// End of user code
}


int World::size = 1;	

int World::getChunkIndice()
{
	return chunkIndice;
}

void World::setChunkIndice(int _chunkIndice)
{
	chunkIndice = _chunkIndice;
}


vector<Chunk*> World::getChunks()
{
	// Start of user code getChunks
	// End of user code
	return chunks;
}

WorldGenerator* World::getWorldGenerator()
{
	// Start of user code getWorldGenerator
	// End of user code
	return worldGenerator;
}

void World::setWorldGenerator(WorldGenerator* _worldGenerator)
{
	worldGenerator = _worldGenerator;
}
					
