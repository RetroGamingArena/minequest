#include <cstdlib>

#include "World.h"
// Start of user code includes
#include "PerlinGenerator.h"
#include "ChunkTask.h"
#include "Chunk.h"
#include "Engine.h"
#include "CubeFace.h"
#include "Empty.h"
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
            chunks.push_back(chunk);
            if(p==0 && r==0)
            {
                center = chunk;
            }
        }
    
    ChunkTask* chunkTask = new ChunkTask();
    chunkTask->setChunk(center);
    chunkTask->setWorldGenerator(worldGenerator);
    center->setGenerated(true);
    chunkTask->run();
    cubeCount = 0;
    instanceCount = 0;
    occludedCount = 0;
    
    // End of user code
}

World::~World()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
//glm::vec4 World::viewport = glm::vec4(0,0,1920,1080);
Camera* World::camera = NULL;
//double World::near = 0;//0.997;



bool World::isCubeRayCasted(int x, int y, int z, int size)
{
    //raycast occlusion
    if(!isCubeOccluded(x, y, z, size))
        return true;
    else
        return false;
}
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
                buildedTask = chunkTask;
                //mutex->unlock();
                return chunkTask;
            }
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
	// End of user code
}
unsigned char World::getCube(int x, int y, int z)
{
	// Start of user code getCube
    int chunkSize = Chunk::size*Chunk::subsize;
    int worldSize = Chunk::size*Chunk::subsize*(1+size*2);
    
    if(y >= chunkSize)
        return 0;
    
    if(x >= worldSize)
        return 0;
    
    if(z >= worldSize)
        return 0;
    
    int abs_x = x;
    
    int abs_y = y;
    
    int abs_z = z;
    
    int p = abs_x / chunkSize;
    //int q = abs_y / (Chunk::size*Chunk::subsize);
    int r = abs_z / chunkSize;
    
    Chunk* chunk = chunks[ (p)*( (size)*2+1) + r ];
    
    int sx = abs_x % chunkSize;
    int sy = abs_y % chunkSize;
    int sz = abs_z % chunkSize;

    Octree* octree = chunk->getOctree();
    return octree->getAbs(sx, sy, sz, Octree::size);
    
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

OctreeEntry* World::getLeaf(int x, int y, int z)
{
	// Start of user code getLeaf
    if(y > Chunk::size*Chunk::subsize || y < 0)
        return NULL;
    
    if( x < 0 || z < 0 || x >= Chunk::size*Chunk::subsize*(size*2+1) || z >= Chunk::size*Chunk::subsize*(size*2+1))
        return NULL;
    
    int abs_x = x;
    
    int abs_y = y;
    
    int abs_z = z;
    
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
        OctreeEntry* entry = octree->getLeafAbs(sx, sy, sz, Octree::size);
        return entry;
    }
    
    return NULL;
	// End of user code
}
bool World::isCubeOccluded(int x, int y, int z, int size)
{
	// Start of user code isCubeOccluded
    OctreeEntry* base = this->getLeaf(x, y, z);
    
    OctreeEntry* collided = NULL;
    
    unsigned char mask = Engine::getInstance()->getScene()->getSelectedCamera()->getMask();
    Camera* camera = Engine::getInstance()->getScene()->getSelectedCamera();
    glm::vec3 position = camera->getPosition();
    
    float xRay = x + size / 2.0;
    float yRay = y + size / 2.0;
    float zRay = z + size / 2.0;
    
    glm::vec4 viewport = glm::vec4(0,0,1920,1080);
    
    glm::vec3 projection1 = glm::project(glm::vec3(x/16.0,       y/16.0,        z/16.0)/*x/16.0,y/16.0,z/16.0)*/, Scene::VM, Scene::projection, viewport);
    
    if(projection1.x < 0 || projection1.y < 0 || projection1.x > 1920 || projection1.y > 1080)
        return true;
    
    glm::vec3 projection2 = glm::project(glm::vec3((x+size)/16.0,y/16.0,        z/16.0), Scene::VM, Scene::projection, viewport);
    
    if(projection2.x < 0 || projection2.y < 0 || projection2.x > 1920 || projection2.y > 1080)
        return true;
    
    glm::vec3 projection3 = glm::project(glm::vec3(x/16.0,       y/16.0,        (z+size)/16.0), Scene::VM, Scene::projection, viewport);
    
    if(projection3.x < 0 || projection3.y < 0 || projection3.x > 1920 || projection3.y > 1080)
        return true;
    
    glm::vec3 projection4 = glm::project(glm::vec3((x+size)/16.0,y/16.0,        (z+size)/16.0), Scene::VM, Scene::projection, viewport);
    
    if(projection4.x < 0 || projection4.y < 0 || projection4.x > 1920 || projection4.y > 1080)
        return true;
    
    glm::vec3 projection5 = glm::project(glm::vec3(x/16.0,       (y+size)/16.0, z/16.0), Scene::VM, Scene::projection, viewport);
    
    if(projection5.x < 0 || projection5.y < 0 || projection5.x > 1920 || projection5.y > 1080)
        return true;
    
    glm::vec3 projection6 = glm::project(glm::vec3((x+size)/16.0,(y+size)/16.0, z/16.0), Scene::VM, Scene::projection, viewport);
    
    if(projection6.x < 0 || projection6.y < 0 || projection6.x > 1920 || projection6.y > 1080)
        return true;
    
    glm::vec3 projection7 = glm::project(glm::vec3(x/16.0,       (y+size)/16.0, (z+size)/16.0), Scene::VM, Scene::projection, viewport);
    
    if(projection7.x < 0 || projection7.y < 0 || projection7.x > 1920 || projection7.y > 1080)
        return true;
    
    glm::vec3 projection8 = glm::project(glm::vec3((x+size)/16.0,(y+size)/16.0, (z+size)/16.0), Scene::VM, Scene::projection, viewport);

    if(projection8.x < 0 || projection8.y < 0 || projection8.x > 1920 || projection8.y > 1080)
        return true;
    
    float projectionXmin = min(projection1.x, projection2.x);
    projectionXmin = min(projectionXmin, projection3.x);
    projectionXmin = min(projectionXmin, projection4.x);
    projectionXmin = min(projectionXmin, projection5.x);
    projectionXmin = min(projectionXmin, projection6.x);
    projectionXmin = min(projectionXmin, projection7.x);
    projectionXmin = min(projectionXmin, projection8.x);
    
    float projectionXmax = max(projection1.x, projection2.x);
    projectionXmax = max(projectionXmax, projection3.x);
    projectionXmax = max(projectionXmax, projection4.x);
    projectionXmax = max(projectionXmax, projection5.x);
    projectionXmax = max(projectionXmax, projection6.x);
    projectionXmax = max(projectionXmax, projection7.x);
    projectionXmax = max(projectionXmax, projection8.x);
    
    float projectionYmin = min(projection1.y, projection2.y);
    projectionYmin = min(projectionYmin, projection3.y);
    projectionYmin = min(projectionYmin, projection4.y);
    projectionYmin = min(projectionYmin, projection5.y);
    projectionYmin = min(projectionYmin, projection6.y);
    projectionYmin = min(projectionYmin, projection7.y);
    projectionYmin = min(projectionYmin, projection8.y);
    
    float projectionYmax = max(projection1.y, projection2.y);
    projectionYmax = max(projectionYmax, projection3.y);
    projectionYmax = max(projectionYmax, projection4.y);
    projectionYmax = max(projectionYmax, projection5.y);
    projectionYmax = max(projectionYmax, projection6.y);
    projectionYmax = max(projectionYmax, projection7.y);
    projectionYmax = max(projectionYmax, projection8.y);
    
    Ray* ray = NULL;
    
    glm::vec3 unprojection;
    float step = 0.1;
    position *= 16.0;
    //float i = projection1.x;
    //float j = projection1.y;
    
    for(float i = projectionXmin; i < projectionXmax; i+=step)
        for(float j = projectionYmin; j < projectionYmax; j+=step)
        {
            unprojection = glm::unProject(glm::vec3(i, j, 1.0), Scene::VM, Scene::projection, viewport);
            
            unprojection *= 16.0;
            
            ray = new Ray(position, unprojection);
            
            collided = collide(ray, xRay, yRay, zRay);
            if(collided == base)
                return false;
        }
    
    return true;
	// End of user code
}
OctreeEntry* World::collide(Ray * ray, int x, int y, int z)
{
	// Start of user code collide
    glm::vec3 d;
    
    double start = ray->enterCube(0, 0, 0, Chunk::size*(size*2+1) *Chunk::subsize-1, Chunk::size *Chunk::subsize-1, Chunk::size*(size*2+1) *Chunk::subsize-1);
    double end = ray->exitCube(0, 0, 0, Chunk::size*(size*2+1) *Chunk::subsize-1, Chunk::size *Chunk::subsize-1, Chunk::size*(size*2+1) *Chunk::subsize-1);
    
    double iX = (x - ray->getStart().x )/ray->getNormalizedPoint().x;
    double iY = (y - ray->getStart().y )/ray->getNormalizedPoint().y;
    double iZ = (z - ray->getStart().z )/ray->getNormalizedPoint().z;
    
    //OctreeEntry* entry = this->getLeaf(x, y, z);
    
    double div = (Chunk::size*Chunk::subsize);
    
    int p = 0;
    int q = 0;
    int r = 0;
    
    double x1 = 0;
    double y1 = 0;
    double z1 = 0;
    double x2 = 0;
    double y2 = 0;
    double z2 = 0;
    
    double _end = 0;
    
    for(double i = start; i<end; )
    {
        d = ray->move(i);
        
        OctreeEntry* entry = this->getLeaf(d.x, d.y, d.z);
        
        if(entry==NULL)
        {
            OctreeEntry* _entry = this->getLeaf(d.x*Chunk::subsize, d.y*Chunk::subsize, d.z*Chunk::subsize);
            if(_entry==NULL)
            {
                _entry = this->getLeaf(d.x*Chunk::subsize, d.y*Chunk::subsize, d.z*Chunk::subsize);
            }
            _entry = NULL;
        }
        
        Empty* empty = dynamic_cast<Empty*>(entry);
        
        if(empty == NULL)
        {
            return entry;
        }
        else
        {
            div = (Chunk::size*Chunk::subsize);
            
            p = d.x / div;
            q = d.y / div;
            r = d.z / div;
            
            x1 = p*div + empty->getX();
            y1 = q*div + empty->getY();
            z1 = r*div + empty->getZ();
            x2 = p*div + (empty->getX()+empty->getSize());
            y2 = q*div + (empty->getY()+empty->getSize());
            z2 = r*div + (empty->getZ()+empty->getSize());

            _end = ray->exitCube(x1, y1, z1, x2, y2, z2);
            
            if(_end > iX && _end > iY && _end > iZ)
                return this->getLeaf(x, y, z);

            i=_end;
            delete empty;
        }
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

