#include <cstdlib>

#include "World.h"
// Start of user code includes
#include "PerlinGenerator.h"
#include "ChunkTask.h"
#include "Chunk.h"
#include "Camera.h"
#include "Engine.h"
#include "CubeFace.h"
#include <algorithm>
// End of user code

World::World(int _size, int _chunkIndice, int _cubeCount, int _instanceCount, int _occludedCount)
{
	size = _size;
	chunkIndice = _chunkIndice;
	cubeCount = _cubeCount;
	instanceCount = _instanceCount;
	occludedCount = _occludedCount;
}

World::World()
// Start of user code super class
: Pool(4)
// End of user code
{
	// Start of user code constructor
    chunkIndice = 0;
    worldGenerator = new PerlinGenerator();
    
    Chunk* center = NULL;
    
    for(int p=0; p<=size*2; p++)
        for(int r=0; r<=size*2; r++)
        {
            Chunk* chunk = new Chunk(p,0,r);
            //chunk->generate(generator);
            chunks.push_back(chunk);
            if(p==0 && r==0)
            {
                center = chunk;
            }
        }
    
    //threadCount = 4;
    
    ChunkTask* chunkTask = new ChunkTask();
    chunkTask->setChunk(center);
    chunkTask->setWorldGenerator(worldGenerator);
    center->setGenerated(true);
    chunkTask->run();
    cubeCount = 0;
    instanceCount = 0;
    occludedCount = 0;
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
    World* world = Engine::getInstance()->getWorld();
    if( mutex->try_lock() )
    {
        for(int i = 0; i < world->getChunks().size(); i++)
        {
            Chunk* chunk = chunks[i];
            if(!chunk->getGenerated() && !chunk->getGenerating())
            {
                ChunkTask* chunkTask = new ChunkTask(chunk, worldGenerator);
                chunkIndice = chunkIndice+1;
                chunk->setGenerating(true);
                mutex->unlock();
                return chunkTask;
            }
        }
        mutex->unlock();
    }
    return NULL;
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

int World::getInstanceCount()
{
	// Start of user code getInstanceCount
	// End of user code
	return instanceCount;
}

void World::setInstanceCount(int _instanceCount)
{
	instanceCount = _instanceCount;
}

int World::getOccludedCount()
{
	// Start of user code getOccludedCount
	// End of user code
	return occludedCount;
}

void World::setOccludedCount(int _occludedCount)
{
	occludedCount = _occludedCount;
}


bool World::isCubeVisible(int x, int y, int z, int size)
{
	// Start of user code isCubeVisible
    //int absSize = Chunk::size*Chunk::subsize*World::size;
    
    //kjgfjgjf//TODO : corriger les if
    
    //OctreeEntry* test = getLeaf(94, 5, 0);
    
    //ground occlusion
    if( y==0 && x>0 && z>0 && (x+size-1)<(Chunk::size*Chunk::subsize-1) && (z+size-1)<(Chunk::size*Chunk::subsize-1) )
        return false;
    
    Camera* camera = Engine::getInstance()->getScene()->getSelectedCamera();
    unsigned char mask = camera->getMask();
    
    unsigned char visibility = 0;
    
    //30520
    //geometry occlusion
    if(!isCubeFree(x, y, z, size))
        return false;
    /*for(int i = size-1; i >= 0; i--)
        for(int j = size-1; j >= 0; j--)
        {
            if(this->getCube(x-1, y+i,   z+j) == 0 && (mask & LEFT))
                visibility |= LEFT;//return true;
            if( (x+size-1)==((World::size*2+1)*Chunk::size*Chunk::subsize-1) )
                visibility |= RIGHT;//return true;
            else if(this->getCube((x+size-1)+1, y+i,   z+j) == 0 && (mask & RIGHT))
                visibility |= RIGHT;//return true;
            if(this->getCube(x+i, y-1,   z+j) == 0 && (mask & BOTTOM))
                visibility |= BOTTOM;//return true;
            if(this->getCube(x+i, (y+size-1)+1,   z+j) == 0 && (mask & TOP))
                visibility |= TOP;//return true;
            if(this->getCube(x+i, y+j,   z-1) == 0 && (mask & BACK))
                visibility |= BACK;//return true;
            if( (z+size-1)==((World::size*2+1)*Chunk::size*Chunk::subsize-1) )
                visibility |= FRONT;
            else if(this->getCube(x+i, y+j,   (z+size-1)+1) == 0 && (mask & FRONT))
                visibility |= FRONT;//return true;
        }*/
    
    //if((visibility & TOP))
    //    return true;

    //raycast occlusion
    //2D Cube
    glm::mat4 model = camera->getModel();
    glm::mat4 view = camera->getView();
    glm::mat4 projection = camera->getProjection();
    
    glm::vec4 viewportdata = glm::vec4(0.0f, 0.0f, 1920.0f, 1080.0f);
    
    glm::vec3 pos = glm::vec3(x/(float)Chunk::subsize,y/(float)Chunk::subsize,z/(float)Chunk::subsize);
    //glm::vec3 posTest = glm::vec3(0,0,0);
    
    glm::vec3 project = glm::project(pos, view*model, projection, viewportdata);
    //glm::vec3 projectTest = glm::project(posTest, view*model, projection, viewportdata);
    
    float minx = project.x;
    float maxx = project.x;
    float miny = project.y;
    float maxy = project.y;
    
    pos = glm::vec3((x+size)/(float)Chunk::subsize,y/(float)Chunk::subsize,z/(float)Chunk::subsize);
    project = glm::project(pos, view*model, projection, viewportdata);
    
    minx = std::min(minx,project.x);
    maxx = std::max(maxx,project.x);
    miny = std::min(miny,project.y);
    maxy = std::max(maxy,project.y);

    pos = glm::vec3(x/(float)Chunk::subsize,y/(float)Chunk::subsize,(z+size)/(float)Chunk::subsize);
    project = glm::project(pos, view*model, projection, viewportdata);
    
    minx = std::min(minx,project.x);
    maxx = std::max(maxx,project.x);
    miny = std::min(miny,project.y);
    maxy = std::max(maxy,project.y);
    
    pos = glm::vec3((x+size)/(float)Chunk::subsize,y/(float)Chunk::subsize,(z+size)/(float)Chunk::subsize);
    project = glm::project(pos, view*model, projection, viewportdata);
    
    minx = std::min(minx,project.x);
    maxx = std::max(maxx,project.x);
    miny = std::min(miny,project.y);
    maxy = std::max(maxy,project.y);
    
    pos = glm::vec3(x/(float)Chunk::subsize,(y+size)/(float)Chunk::subsize,z/(float)Chunk::subsize);
    project = glm::project(pos, view*model, projection, viewportdata);
    
    minx = std::min(minx,project.x);
    maxx = std::max(maxx,project.x);
    miny = std::min(miny,project.y);
    maxy = std::max(maxy,project.y);
    
    pos = glm::vec3((x+size)/(float)Chunk::subsize,(y+size)/(float)Chunk::subsize,z/(float)Chunk::subsize);
    project = glm::project(pos, view*model, projection, viewportdata);
    
    minx = std::min(minx,project.x);
    maxx = std::max(maxx,project.x);
    miny = std::min(miny,project.y);
    maxy = std::max(maxy,project.y);
    
    pos = glm::vec3(x/(float)Chunk::subsize,(y+size)/(float)Chunk::subsize,(z+size)/(float)Chunk::subsize);
    project = glm::project(pos, view*model, projection, viewportdata);
    
    minx = std::min(minx,project.x);
    maxx = std::max(maxx,project.x);
    miny = std::min(miny,project.y);
    maxy = std::max(maxy,project.y);
    
    pos = glm::vec3((x+size)/(float)Chunk::subsize,(y+size)/(float)Chunk::subsize,(z+size)/(float)Chunk::subsize);
    project = glm::project(pos, view*model, projection, viewportdata);
    
    minx = std::min(minx,project.x);
    maxx = std::max(maxx,project.x);
    miny = std::min(miny,project.y);
    maxy = std::max(maxy,project.y);

    /*OctreeEntry* base = this->getLeaf(x, y, z);
    
    for(int _x = minx; _x<maxx; _x++)
        for(int _y = miny; _y<maxy; _y++)
        {
            pos = glm::vec3(_x,_y,0);

            glm::vec3 unProject = glm::unProject(pos, view*model, projection, viewportdata);
            
            glm::vec3 pos1 = glm::vec3(0,0,0);
            glm::vec3 pos2 = glm::vec3(1920,0,0);
            glm::vec3 pos3 = glm::vec3(0,1080,0);
            glm::vec3 pos4 = glm::vec3(1920,1080,0);
            
            glm::vec3 unProject1 = glm::unProject(pos1, view*model, projection, viewportdata);
            glm::vec3 unProject2 = glm::unProject(pos2, view*model, projection, viewportdata);
            glm::vec3 unProject3 = glm::unProject(pos3, view*model, projection, viewportdata);
            glm::vec3 unProject4 = glm::unProject(pos4, view*model, projection, viewportdata);

            glm::vec3 position = camera->getPosition();
            Ray* ray = new Ray(position, glm::vec3((x+size/2.0)/(float)Chunk::subsize,(y+size/2.0)/(float)Chunk::subsize,(z+size/2.0)/(float)Chunk::subsize));//unProject);
            
            for(int i = 0; i<100; i++)
            {
                glm::vec3 d = ray->move(i);

                OctreeEntry* entry = this->getLeaf(d.x*Chunk::subsize, d.y*Chunk::subsize, d.z*Chunk::subsize);
                if(entry != NULL)
                {
                    //return true;
                    if(entry == base)
                        return true;
                    else
                        break;
                }
            }
        }*/
    
    //return true;

    if(isCubeOccluded(x, y, z, size))
       return false;
    
    return true;
    
    if( x==0 )
    {
        if( !(visibility & RIGHT) && !(visibility & FRONT) && !(visibility & BACK) )
            return false;
    }
    
    if( (x+size-1)==((World::size*2+1)*Chunk::size*Chunk::subsize-1))
    {
        if( !(visibility & LEFT) && !(visibility & FRONT) && !(visibility & BACK) )
            return false;
    }
    
    if( (z+size-1)==((World::size*2+1)*Chunk::size*Chunk::subsize-1))
    {
        if( !(visibility & LEFT) && !(visibility & RIGHT) && !(visibility & BACK) )
            return false;
    }
    
    if( z==0 )
    {
        if( !(visibility & LEFT) && !(visibility & RIGHT) && !(visibility & FRONT) )
            return false;
    }
    
    if( x==0 || z==0 || (x+size-1)==((World::size*2+1)*Chunk::size*Chunk::subsize-1) || (y+size-1)==(Chunk::size*Chunk::subsize-1) || (z+size-1)==((World::size*2+1)*Chunk::size*Chunk::subsize-1) )
        return true;
    
    if(visibility > 0)
        return true;
    
    
    return false;
	// End of user code
}
void World::bufferizeEntry(VertexBuffer * vertexBuffer, unsigned char type, float p, float q, float r, int widthP, int widthQ, int widthR, unsigned char occlusion)
{
	// Start of user code bufferizeEntry
    int pInt = (int)p;
    double pDecimal = p-pInt;
    
    int qInt = (int)q;
    double qDecimal = q-qInt;
    
    int rInt = (int)r;
    double rDecimal = r-rInt;
    
    vector<GLuint>* data = vertexBuffer->getData();
    
    unsigned int _offset =  (   (int)(pDecimal / 0.0625) + (int)((pInt%8) << 4) + ((pInt/8) << 7) +
                    (((int)(qDecimal / 0.0625) + (int)((qInt%8) << 4) + ((qInt/8) << 7)) << 10) +
                    ( (( (int)(rDecimal / 0.0625) + (int)((rInt%8) << 4) + ((rInt/8) << 7) )) << 20) );
    
    data->push_back(_offset);
    
    unsigned int size = (type << 20) + (occlusion << 18) + ((widthP-1) << 12) + ((widthQ-1) << 6) + (widthR-1);
    
    data->push_back(size);
    return;
	// End of user code
}
unsigned char World::getCube(int x, int y, int z)
{
	// Start of user code getCube
    if(y > Chunk::size*Chunk::subsize)
        return 0;
    
    int abs_x = x;//+size*Chunk::size*Chunk::subsize;
    
    int abs_y = y;//+size*Chunk::size*Chunk::subsize;
    
    int abs_z = z;//+size*Chunk::size*Chunk::subsize;
    
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
Chunk* World::getChunk(int x, int y, int z)
{
	// Start of user code getChunk
    int p = x/(16.0*8.0);
    int q = x/(16.0*8.0);
    int r = x/(16.0*8.0);
    
    for(int i = 0; i < chunks.size(); i++)
    {
        Chunk* chunk = chunks[i];
        if(chunk->getP() == p && chunk->getQ() == q && chunk->getR() == r)
            return chunk;
    }
    return NULL;
	// End of user code
}
bool World::isCubeFree(int x, int y, int z, int size)
{
	// Start of user code isCubeFree
    unsigned char mask = Engine::getInstance()->getScene()->getSelectedCamera()->getMask();
    
    if((x+size-1)+1 >= Chunk::size*Chunk::subsize*World::size && (mask & RIGHT))
        return true;
    
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
OctreeEntry* World::getLeaf(int x, int y, int z)
{
	// Start of user code getLeaf
    if(y > Chunk::size*Chunk::subsize || y < 0)
        return NULL;
    
    if( x < 0 || z < 0 || x >= Chunk::size*Chunk::subsize*(size*2+1) || z >= Chunk::size*Chunk::subsize*(size*2+1))
        return NULL;
    
    int abs_x = x;//+size*Chunk::size*Chunk::subsize;
    
    int abs_y = y;//+size*Chunk::size*Chunk::subsize;
    
    int abs_z = z;//+size*Chunk::size*Chunk::subsize;
    
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
        OctreeEntry* entry = octree->getLeafAbs(x, y, z, Octree::size);
        return entry;
    }
    
    return NULL;
	// End of user code
}
bool World::isCubeOccluded(int x, int y, int z, int size)
{
	// Start of user code isCubeOccluded
    OctreeEntry* base = this->getLeaf(x, y, z);
    unsigned char mask = Engine::getInstance()->getScene()->getSelectedCamera()->getMask();
    glm::vec3 position = Engine::getInstance()->getScene()->getSelectedCamera()->getPosition();
    
    Ray* ray = NULL;
    
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            if(/*this->getCube(x-1, y+i,   z+j) == 0 &&*/ (mask & LEFT))
            {
                ray = new Ray(position, glm::vec3(x/(float)Chunk::subsize,(y+i)/(float)Chunk::subsize,(z+j)/(float)Chunk::subsize));
                if(collide(ray, x, y+i, z+j) == base)
                    return false;
            }
            if(/*this->getCube((x+size-1)+1, y+i,   z+j) == 0 &&*/ (mask & RIGHT))
            {
                ray = new Ray(position, glm::vec3((x+size-1)/(float)Chunk::subsize,(y+i)/(float)Chunk::subsize,(z+j)/(float)Chunk::subsize));
                if(collide(ray, (x+size-1), y+i, z+j) == base)
                    return false;
            }
            if(/*this->getCube(x+i, y-1,   z+j) == 0 &&*/ (mask & BOTTOM))
            {
                ray = new Ray(position, glm::vec3((x+i)/(float)Chunk::subsize,y/(float)Chunk::subsize,(z+j)/(float)Chunk::subsize));
                if(collide(ray, x+i, y, z+j) == base)
                    return false;
            }
            if(/*this->getCube(x+i, (y+size-1)+1,   z+j) == 0 &&*/ (mask & TOP))
            {
                ray = new Ray(position, glm::vec3((x+i)/(float)Chunk::subsize,(y+size-1)/(float)Chunk::subsize,(z+j)/(float)Chunk::subsize));
                if(collide(ray, x+i, y+size-1, z+j) == base)
                    return false;
            }
            if(/*this->getCube(x+i, y+j,   z-1) == 0 &&*/ (mask & BACK))
            {
                ray = new Ray(position, glm::vec3((x+i)/(float)Chunk::subsize,(y+i)/(float)Chunk::subsize,z/(float)Chunk::subsize));
                if(collide(ray, x+i, y+j, z) == base)
                    return false;
            }
            if(/*this->getCube(x+i, y+j,   (z+size-1)+1) == 0 &&*/ (mask & FRONT))
            {
                ray = new Ray(position, glm::vec3((x+i)/(float)Chunk::subsize,(y+j)/(float)Chunk::subsize,(z+size-1)/(float)Chunk::subsize));
                if(collide(ray, x+i, y+i, z+size-1) == base)
                    return false;
            }
        }
    
    delete ray;
    
    return true;
	// End of user code
}
OctreeEntry* World::collide(Ray * ray, int x, int y, int z)
{
	// Start of user code collide
    glm::vec3 d;
    for(int i = 0; i<100; i++)
    {
        d = ray->move(i);
        
        OctreeEntry* entry = this->getLeaf(d.x*Chunk::subsize, d.y*Chunk::subsize, d.z*Chunk::subsize);
        if(entry != NULL)
        {
            return entry;
        }
    }
    d = ray->move(46);
    return NULL;
	// End of user code
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
					
