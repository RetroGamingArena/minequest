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
glm::vec4 World::viewport = glm::vec4(0,0,1920,1080);
Camera* World::camera = NULL;
double World::near = 0.997;

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
    
    int maxPosition = (Chunk::size*Chunk::subsize-1);
    int sizeM1 = size-1;
    int yPSize = y+size;
    int chunksWidth = World::size*2+1;
    
    //ground occlusion
    if( y==0 && x>0 && z>0 && (x+sizeM1)<maxPosition && (z+sizeM1)<maxPosition )
        return false;
    
    //geometry occlusion
    if(!isCubeFree(x, y, z, size))
        return false;
    
    //edge occlusion
    if( x==0 )
    {
        if( getCube(x, yPSize, z)>0 )
            return false;
    }
    
    if( (x+sizeM1)==((chunksWidth)*maxPosition))
    {
        if( getCube(x, yPSize, z)>0 )
            return false;
    }
    
    if( (z+sizeM1)==((chunksWidth)*maxPosition))
    {
        if( getCube(x, yPSize, z)>0 )
            return false;
    }
    
    if( z==0 )
    {
        if( getCube(x, yPSize, z)>0 )
            return false;
    }
    
    return true;
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
	// End of user code
}
unsigned char World::getCube(int x, int y, int z)
{
	// Start of user code getCube
    if(y >= Chunk::size*Chunk::subsize)
        return 0;
    
    if(x >= Chunk::size*Chunk::subsize*(1+size*2))
        return 0;
    
    if(z >= Chunk::size*Chunk::subsize*(1+size*2))
        return 0;
    
    int abs_x = x;
    
    int abs_y = y;
    
    int abs_z = z;
    
    int p = abs_x / (Chunk::size*Chunk::subsize);
    //int q = abs_y / (Chunk::size*Chunk::subsize);
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
    glm::vec3 position = Engine::getInstance()->getScene()->getSelectedCamera()->getPosition();
    
    position.x =  position.x * Chunk::subsize;
    position.y =  position.y * Chunk::subsize;
    position.z =  position.z * Chunk::subsize;

    Ray* ray = NULL;
    
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            if((mask & LEFT))
            {
                ray = new Ray(position, glm::vec3(x,(y+i),(z+j)));
                collided = collide(ray, x, y+i, z+j);
                if(collided == base)
                    return false;
                if(collided == NULL)
                    return false;
            }
            if((mask & RIGHT))
            {
                ray = new Ray(position, glm::vec3((x+size-1),(y+i),(z+j)));
                collided = collide(ray, (x+size-1), y+i, z+j);
                if(collided == base)
                    return false;
                if(collided == NULL)
                    return false;
            }
            if((mask & BOTTOM))
            {
                ray = new Ray(position, glm::vec3((x+i),y,(z+j)));
                collided = collide(ray, x+i, y, z+j);
                if(collided == base)
                    return false;
                if(collided == NULL)
                    return false;
            }
            if((mask & TOP))
            {
                ray = new Ray(position, glm::vec3((x+i),(y+size-1),(z+j)));
                collided = collide(ray, x+i, y+size-1, z+j);
                if(collided == base)
                    return false;
                if(collided == NULL)
                    return false;
            }
            if((mask & BACK))
            {
                ray = new Ray(position, glm::vec3((x+i),(y+i),z));
                collided = collide(ray, x+i, y+j, z);
                if(collided == base)
                    return false;
                if(collided == NULL)
                    return false;
            }
            if((mask & FRONT))
            {
                ray = new Ray(position, glm::vec3((x+i),(y+j),(z+size-1)));
                collided = collide(ray, x+i, y+i, z+size-1);
                if(collided == base)
                    return false;
                if(collided == NULL)
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
double World::isCubeInFrustum(double x1, double y1, double z1, double x2, double y2, double z2)
{
	// Start of user code isCubeInFrustum
    /*Camera* camera = Engine::getInstance()->getScene()->getSelectedCamera();
    glm::mat4  projection = camera->getProjection();*/
    glm::vec3 project;
    //glm::mat4 VM = camera->getView()*camera->getModel();
    
    project = glm::project(glm::vec3(x1,y1,z1), Scene::VM, Scene::projection, viewport);
    
    if(project.z <= near)
        return false;
    if( project.z>0 && project.x>=0 && project.x<=1920 && project.y>=0 && project.y<=1080)
        return true;
    project = glm::project(glm::vec3(x2,y1,z1), Scene::VM, Scene::projection, viewport);
    if(project.z <= near)
        return false;
    if( project.z>0 && project.x>=0 && project.x<=1920 && project.y>=0 && project.y<=1080)
        return true;
    project = glm::project(glm::vec3(x1,y1,z2), Scene::VM, Scene::projection, viewport);
    if(project.z <= near)
        return false;
    if( project.z>0 && project.x>=0 && project.x<=1920 && project.y>=0 && project.y<=1080)
        return true;
    project = glm::project(glm::vec3(x2,y1,z2), Scene::VM, Scene::projection, viewport);
    if(project.z <= near)
        return false;
    if( project.z>0 && project.x>=0 && project.x<=1920 && project.y>=0 && project.y<=1080)
        return true;
    project = glm::project(glm::vec3(x1,y2,z1), Scene::VM, Scene::projection, viewport);
    if(project.z <= near)
        return false;
    if( project.z>0 && project.x>=0 && project.x<=1920 && project.y>=0 && project.y<=1080)
        return true;
    project = glm::project(glm::vec3(x2,y2,z1), Scene::VM, Scene::projection, viewport);
    if(project.z <= near)
        return false;
    if( project.z>0 && project.x>=0 && project.x<=1920 && project.y>=0 && project.y<=1080)
        return true;
    project = glm::project(glm::vec3(x1,y2,z2), Scene::VM, Scene::projection, viewport);
    if(project.z <= near)
        return false;
    if( project.z>0 && project.x>=0 && project.x<=1920 && project.y>=0 && project.y<=1080)
        return true;
    project = glm::project(glm::vec3(x2,y2,z2), Scene::VM, Scene::projection, viewport);
    if(project.z <= near)
        return false;
    if( project.z>0 && project.x>=0 && project.x<=1920 && project.y>=0 && project.y<=1080)
        return true;
    
    return false;

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

