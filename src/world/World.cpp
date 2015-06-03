#include <cstdlib>

#include "World.h"
// Start of user code includes
#include "PerlinGenerator.h"
#include "ChunkTask.h"
#include "Chunk.h"
#include "Camera.h"
#include "Engine.h"
#include "CubeFace.h"
// End of user code

World::World(int _size, int _chunkIndice, int _cubeCount)
{
	size = _size;
	chunkIndice = _chunkIndice;
	cubeCount = _cubeCount;
}

World::World()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    chunkIndice = 0;
    worldGenerator = new PerlinGenerator();
    
    Chunk* center = NULL;
    
    for(int p=-size; p<=size; p++)
        for(int r=-size; r<=size; r++)
        {
            Chunk* chunk = new Chunk(p,0,r);
            //chunk->generate(generator);
            chunks.push_back(chunk);
            if(p==0 && r==0)
            {
                center = chunk;
            }
        }
    
    threadCount = 9;
    
    ChunkTask* chunkTask = new ChunkTask();
    chunkTask->setChunk(center);
    chunkTask->setWorldGenerator(worldGenerator);
    chunkTask->run();
    
    //this->start();
    //while(isRunning()){}
	
    // End of user code
}

World::~World()
{
	// Start of user code destructor
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
	// Start of user code getChunkIndice
	// End of user code
	return chunkIndice;
}

void World::setChunkIndice(int _chunkIndice)
{
	chunkIndice = _chunkIndice;
}

int World::getCubeCount()
{
	// Start of user code getCubeCount
	// End of user code
	return cubeCount;
}

void World::setCubeCount(int _cubeCount)
{
	cubeCount = _cubeCount;
}


bool World::isCubeVisible(int x, int y, int z, int size)
{
	// Start of user code isCubeVisible
    int absSize = Chunk::size*Chunk::subsize*World::size;
    
    if( x==-absSize || z==-absSize || (x+size-1)==(absSize+Chunk::size*Chunk::subsize-1) || (y+size-1)==(Chunk::size*Chunk::subsize-1) || (z+size-1)==(absSize+Chunk::size*Chunk::subsize-1) )
        return true;
    
    if( y==0 && x>-absSize && z>-absSize && (x+size-1)<(absSize+Chunk::size*Chunk::subsize-1) && (z+size-1)<(absSize+Chunk::size*Chunk::subsize-1) )
        return false;
    
    unsigned char mask = Engine::getInstance()->getScene()->getSelectedCamera()->getMask();
    
    for(int i = size-1; i >= 0; i--)
        for(int j = size-1; j >= 0; j--)
        {
            if(this->getCube(x-1, y+i,   z+j) == 0 && (mask & LEFT))
                return true;
            if(this->getCube((x+size-1)+1, y+i,   z+j) == 0 && (mask & RIGHT))
                return true;
            if(this->getCube(x+i, y-1,   z+j) == 0 && (mask & BOTTOM))
                return true;
            if(this->getCube(x+i, (y+size-1)+1,   z+j) == 0 && (mask & TOP))
                return true;
            if(this->getCube(x+i, y+j,   z-1) == 0 && (mask & BACK))
                return true;
            if(this->getCube(x+i, y+j,   (z+size-1)+1) == 0 && (mask & FRONT))
                return true;
        }
    
    return false;
	// End of user code
}
void World::bufferizeEntry(VertexBuffer * vertexBuffer, unsigned char type, float p, float q, float r, int width, unsigned char occlusion)
{
	// Start of user code bufferizeEntry
    float offset = Chunk::size*Chunk::subsize*size;
    
    vector<GLfloat>* data = vertexBuffer->getData();
    
    data->push_back(p);
    data->push_back(q);
    data->push_back(r);

    data->push_back( (type << 17) + (occlusion << 15) + ((width-1) << 10) + ((width-1) << 5) + (width-1));
    
    cubeCount += (width*width*width);
    return;
	// End of user code
}
unsigned char World::getCube(int x, int y, int z)
{
	// Start of user code getCube
    if(y > Chunk::size*Chunk::subsize)
        return 0;
    
    int abs_x = x+size*Chunk::size*Chunk::subsize;
    
    int abs_y = y+size*Chunk::size*Chunk::subsize;
    
    int abs_z = z+size*Chunk::size*Chunk::subsize;
    
    int p = abs_x / (Chunk::size*Chunk::subsize);
    int q = abs_y / (Chunk::size*Chunk::subsize);
    int r = abs_z / (Chunk::size*Chunk::subsize);
    
    Chunk* chunk;
    if(size == 0)
        chunk = chunks[0];
    else
        chunk = chunks[ (p)*( (size)*2+1) + r ];
    
    int sx = abs_x % (Chunk::size*Chunk::subsize);
    int sy = abs_y % (Chunk::size*Chunk::subsize);
    int sz = abs_z % (Chunk::size*Chunk::subsize);
    
    if(chunk != NULL)
    {
        Octree* octree = chunk->getOctree();
        return octree->getAbs(sx, sy, sz, Octree::size);
    }
    
    return 0;
	// End of user code
}
void World::bufferizeEntryRect(VertexBuffer * vertexBuffer, unsigned char type, float p, float q, float r, int width, int height, unsigned char occlusion)
{
	// Start of user code bufferizeEntryRect
    vector<GLfloat>* data = vertexBuffer->getData();
    
    data->push_back(p);
    data->push_back(q);
    data->push_back(r);
    
    //data->push_back(type);
    
    data->push_back( (type << 17) + (occlusion << 15) + ((width-1) << 10) + ((height-1) << 5) + (width-1));
    //data->push_back(height);
    //data->push_back(width);
    
    //data->push_back(occlusion);
    
    cubeCount += (width*width*height);
	// End of user code
}
Chunk* World::getChunk(int x, int y, int z)
{
	// Start of user code getChunk
    int p = x/16.0;
    int q = x/16.0;
    int r = x/16.0;
    
    for(int i = 0; i < chunks.size(); i++)
    {
        Chunk* chunk = chunks[i];
        if(chunk->getP() == p && chunk->getQ() == q && chunk->getR() == r)
            return chunk;
    }
    return NULL;
	// End of user code
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
					
vector<Chunk*> World::getChunks()
{
	// Start of user code getChunks
	// End of user code
	return chunks;
}

void World::setChunksAt(Chunk* _chunks, int indice)
{
	chunks[indice] = _chunks;
}

