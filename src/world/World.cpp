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
    chunkIndice = 0;
    worldGenerator = new PerlinGenerator();
    
    for(int p=-size; p<=size; p++)
        for(int r=-size; r<=size; r++)
        {
            Chunk* chunk = new Chunk(p,0,r);
            //chunk->generate(generator);
            chunks.push_back(chunk);
        }
    
    threadCount = 9;
    this->start();
    while(isRunning()){}
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


int World::size = 0;

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

bool World::isCubeVisible(int x, int y, int z, int size)
{
	// Start of user code isCubeVisible
    int absSize = Chunk::size*Chunk::subsize*World::size;
    
    if( x==-absSize || z==-absSize || (x+size-1)==(absSize+Chunk::size*Chunk::subsize-1) || (y+size-1)==(Chunk::size*Chunk::subsize-1) || (z+size-1)==(absSize+Chunk::size*Chunk::subsize-1) )
        return true;
    
    if( y==0 && x>-absSize && z>-absSize && (x+size-1)<(absSize+Chunk::size*Chunk::subsize-1) && (z+size-1)<(absSize+Chunk::size*Chunk::subsize-1) )
        return false;
    
    for(int i = size-1; i >= 0; i--)
        for(int j = size-1; j >= 0; j--)
        {
            if(this->getCube(x-1, y+i,   z+j) == 0)
                return true;
            if(this->getCube((x+size-1)+1, y+i,   z+j) == 0)
                return true;
            if(this->getCube(x+i, y-1,   z+j) == 0)
                return true;
            if(this->getCube(x+i, (y+size-1)+1,   z+j) == 0)
                return true;
            if(this->getCube(x+i, y+j,   z-1) == 0)
                return true;
            if(this->getCube(x+i, y+j,   (z+size-1)+1) == 0)
                return true;
        }
    
    return false;
	// End of user code
}
void World::bufferizeEntry(VertexBuffer * vertexBuffer, unsigned char type, float p, float q, float r, int width)
{
	// Start of user code bufferizeEntry
    float offset = Chunk::size*Chunk::subsize*size;
    
    float ao = 0;
    
    if(width==1)
    {
        if( (offset*2 + p*Chunk::subsize-1) > offset && (offset*2 + r*Chunk::subsize) > offset )
            ao += (this->getCube(p*Chunk::subsize-1, q*Chunk::subsize+1, r*Chunk::subsize) > 0);
        if( (offset*2 + p*Chunk::subsize) > offset   && (offset*2 + r*Chunk::subsize-1) > offset )
            ao += (this->getCube(p*Chunk::subsize, q*Chunk::subsize+1, r*Chunk::subsize-1) > 0);
        if( (offset*2 + p*Chunk::subsize-1) > offset && (offset*2 + r*Chunk::subsize-1) > offset )
            ao += (this->getCube(p*Chunk::subsize-1, q*Chunk::subsize+1, r*Chunk::subsize-1) > 0);
    }
    
    vector<GLfloat>* data = vertexBuffer->getData();
    
    data->push_back(p);
    data->push_back(q);
    data->push_back(r);
    
    data->push_back(type);
    data->push_back(width);
    data->push_back(ao);
    
    //sizeTemp += width*width*width;
    
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
        return chunk->getOctree()->getAbs(sx, sy, sz, Octree::size);
    }
    
    return 0;
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

