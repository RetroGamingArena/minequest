
#include <cstdlib>

#include "Processor.h"
// Start of user code includes
#include "CubeFace.h"
#include <iostream>
// End of user code


Processor::Processor()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    buffered = false;
    vec = new vector<GLuint>;
	// End of user code
}


// Start of user code methods
glm::vec4 Processor::viewport = glm::vec4(0,0,1920,1080);
glm::vec3 Processor::vertexPosition;
glm::vec4 Processor::viewSpace;
glm::vec4 Processor::position;

Ray* Processor::ray = NULL;
int Processor::rayCastStep = 1;
double Processor::_x = 0;
double Processor::_y = 0;
glm::vec4 Processor::unproj;
OctreeEntry* Processor::base = NULL;
OctreeEntry* Processor::octreeEntry = NULL;
Empty* Processor::empty = NULL;
glm::vec3 Processor::d;
int Processor::end;

//Camera* World::camera = NULL;
double Processor::near = 0;//0.997;
World* Processor::bufferizeWorld = NULL;
std::mutex* Processor::addVoxelMutex = new std::mutex();

void Processor::addVoxel(Voxel voxel)
{
    addVoxelMutex->lock();
    //voxels.push_back(voxel);
    addVoxelMutex->unlock();
}

#define ANG2RAD 3.14159265358979323846/180.0

bool Processor::isPointInFrustum(double x, double y, double z)
{
    vertexPosition = glm::vec3(x,y,z);
    viewSpace = Scene::VM * glm::vec4(vertexPosition,1);
    position = Scene::projection * viewSpace;
    
    //position.x /= position.w;
    //position.y /= position.w;
    
    if(position.z < 0)
        return false;
    if(position.x>=-position.w && position.y>=-position.w && position.x<=position.w && position.y<=position.w )
    //if(position.x>=0 && position.y>=0 && position.x<=1920 && position.y<=1080 )
        return true;
    else
        return false;
}

bool Processor::isCubeInFrustum(double x1, double y1, double z1, double x2, double y2, double z2)
{
    // Start of user code isCubeInFrustum
    
    if(isPointInFrustum(x1, y1, z1))
        return true;
    if(isPointInFrustum(x2, y1, z1))
        return true;
    if(isPointInFrustum(x1, y1, z2))
        return true;
    if(isPointInFrustum(x2, y1, z2))
        return true;
    if(isPointInFrustum(x1, y2, z1))
        return true;
    if(isPointInFrustum(x2, y2, z1))
        return true;
    if(isPointInFrustum(x1, y2, z2))
        return true;
    if(isPointInFrustum(x2, y2, z2))
        return true;
    
    /*Camera* camera = Engine::getInstance()->getScene()->getSelectedCamera();
    
    glm::vec3 p(x1,y1,z1);
    
    float pcz,pcx,pcy,aux;
    
    float farD = 200.0f;
    float nearD = 0.009f;
    float angle = 70.0f;
    float ratio = 192.0f / 108.0f;
    float tang = (float)tan(ANG2RAD * angle * 0.5);

    glm::vec3 v = p-camera->getPosition();
    
    glm::vec3 Z;
    Z = camera->getCenter() - p;
    
    float length = Z.length();
    Z = Z / length;

    glm::vec3 X = Z * camera->getUp();
    
    length = Z.length();
    X = X / length;
    
    glm::vec3 Y = X * Z;
    
    pcz = v.x*-Z.x + v.y*-Z.y + v.z*-Z.z;
    if (pcz > farD || pcz < nearD)
        return false;
    
    pcy = v.x*Y.x + v.y*Y.y + v.z*Y.z;
    aux = pcz * tang;
    if (pcy > aux || pcy < -aux)
        return false;
    
    pcz = v.x*X.x + v.y*X.y + v.z*X.z;
    aux = aux * ratio;
    if (pcx > aux || pcx < -aux)
        return false;
    
    p = glm::vec3(x2,y2,z2);
    
    v = p-camera->getPosition();
    
    Z = camera->getCenter() - p;
    
    length = Z.length();
    Z = glm::normalize(Z);
    
    X = Z * camera->getUp();
    
    length = Z.length();
    X= X / length;
    
    Y = X * Z;
    
    pcz = v.x*-Z.x + v.y*-Z.y + v.z*-Z.z;
    if (pcz > farD || pcz < nearD)
        return false;
    
    pcy = v.x*Y.x + v.y*Y.y + v.z*Y.z;
    aux = pcz * tang;
    if (pcy > aux || pcy < -aux)
        return false;
    
    pcz = v.x*X.x + v.y*X.y + v.z*X.z;
    aux = aux * ratio;
    if (pcx > aux || pcx < -aux)
        return false;*/
    
    return false;

    // End of user code
}

bool Processor::isCubeVisible(int x, int y, int z, int size)
{
    // Start of user code isCubeVisible
    
    int maxPosition = (Chunk::size*Chunk::subsize-1);
    int sizeM1 = size-1;
    int yPSize = y+size;
    int chunksWidth = World::size*2+1;
    
    //ground occlusion
    if( y==0 )// && x>0 && z>0 && (x+sizeM1)<maxPosition && (z+sizeM1)<maxPosition )
        return false;
    
    //geometry occlusion
    if(!isCubeFree(x, y, z, size))
        return false;
    
    //side occlusion
    if( x==0 )
    {
        if( bufferizeWorld->getCube(x, yPSize, z)>0 )
            return false;
    }
    
    if( (x+sizeM1)==((chunksWidth)*maxPosition))
    {
        if( bufferizeWorld->getCube(x, yPSize, z)>0 )
            return false;
    }
    
    if( (z+sizeM1)==((chunksWidth)*maxPosition))
    {
        if( bufferizeWorld->getCube(x, yPSize, z)>0 )
            return false;
    }
    
    if( z==0 )
    {
        if( bufferizeWorld->getCube(x, yPSize, z)>0 )
            return false;
    }
    
    return true;
    // End of user code
}

bool Processor::isCubeFree(int x, int y, int z, int size)
{
    // Start of user code isCubeFree
    for(int i = size-1; i >= 0; i--)
        for(int j = size-1; j >= 0; j--)
        {
            if(bufferizeWorld->getCube(x-1, y+i,   z+j) == 0)
                return true;
            if(bufferizeWorld->getCube((x+size-1)+1, y+i,   z+j) == 0)
                return true;
            if(bufferizeWorld->getCube(x+i, y-1,   z+j) == 0)
                return true;
            if(bufferizeWorld->getCube(x+i, (y+size-1)+1,   z+j) == 0)
                return true;
            if(bufferizeWorld->getCube(x+i, y+j,   z-1) == 0)
                return true;
            if(bufferizeWorld->getCube(x+i, y+j,   (z+size-1)+1) == 0)
                return true;
        }
    return false;
    // End of user code
}

bool Processor::isCubeFreeWithMask(int x, int y, int z, int size)
{
    // Start of user code isCubeFree
    unsigned char mask = Engine::getInstance()->getScene()->getSelectedCamera()->getMask();
    
    for(int i = size-1; i >= 0; i--)
        for(int j = size-1; j >= 0; j--)
        {
            if(bufferizeWorld->getCube(x-1, y+i,   z+j) == 0 && (mask & LEFT))
                return true;
            if(bufferizeWorld->getCube((x+size-1)+1, y+i,   z+j) == 0 && (mask & RIGHT))
                return true;
            if(bufferizeWorld->getCube(x+i, y-1,   z+j) == 0 && (mask & BOTTOM))
                return true;
            if(bufferizeWorld->getCube(x+i, (y+size-1)+1,   z+j) == 0 && (mask & TOP))
                return true;
            if(bufferizeWorld->getCube(x+i, y+j,   z-1) == 0 && (mask & BACK))
                return true;
            if(bufferizeWorld->getCube(x+i, y+j,   (z+size-1)+1) == 0 && (mask & FRONT))
                return true;
        }
    return false;
    // End of user code
}

bool Processor::isCubeFreeWithMask(int x, int y, int z, int size, unsigned char mask)
{
    for(int i = size-1; i >= 0; i--)
        for(int j = size-1; j >= 0; j--)
        {
            if(bufferizeWorld->getCube(x-1, y+i,   z+j) == 0 && (mask & LEFT))
                return true;
            if(bufferizeWorld->getCube((x+size-1)+1, y+i,   z+j) == 0 && (mask & RIGHT))
                return true;
            if(bufferizeWorld->getCube(x+i, y-1,   z+j) == 0 && (mask & BOTTOM))
                return true;
            if(bufferizeWorld->getCube(x+i, (y+size-1)+1,   z+j) == 0 && (mask & TOP))
                return true;
            if(bufferizeWorld->getCube(x+i, y+j,   z-1) == 0 && (mask & BACK))
                return true;
            if(bufferizeWorld->getCube(x+i, y+j,   (z+size-1)+1) == 0 && (mask & FRONT))
                return true;
        }
    return false;
}

void Processor::bufferizeVoxels(/*vector<GLuint>* vec*/)
{
    vector<Chunk*> chunks = Engine::getInstance()->getWorld()->getChunks();
    
    Voxel voxel;
    
    int p = voxel.x;
    int q = voxel.y;
    int r = voxel.z;
    int size = voxel.size;
    int occlusion = voxel.occlusion;
    int type = voxel.type;
    
    int _p = 0;
    int _q = 0;
    int _r = 0;
    
    int chp = 0;
    int chq = 0;
    int chr = 0;
    
    int cup = 0;
    int cuq = 0;
    int cur = 0;
    
    int pp = 0;
    int qq = 0;
    int rr = 0;
    
    int sizeM1 = 0;
    
    unsigned int _offset = 0;
    unsigned int _size = 0;
    
    double currentTime = glfwGetTime();
    
    vec->clear();
    
    Chunk* chunk = NULL;
    
    int bad = 0;
    
    glm::vec3 d;
    
    unsigned char mask = TOP;
    
    Camera* camera = Engine::getInstance()->getScene()->getSelectedCamera();
    
    for(int c = 0; c < chunks.size(); c++)
    {
        chunk = chunks[c];
        if(!isCubeInFrustum(chunk->getP()*Chunk::size, chunk->getQ()*Chunk::size, chunk->getR()*Chunk::size, (chunk->getP()+1)*Chunk::size, (chunk->getQ()+1)*Chunk::size, (chunk->getR()+1)*Chunk::size))
            continue;
    for(int i = 0; i < chunks[c]->voxels.size(); i++)
    {
        voxel = chunk->voxels[i];
        
        p = voxel.x;
        q = voxel.y;
        r = voxel.z;
        size = voxel.size;
        
        if(!isCubeInFrustum((float)p/Chunk::subsize,(float)q/Chunk::subsize,(float)r/Chunk::subsize,(float)(p+size)/Chunk::subsize,(float)(q+size)/Chunk::subsize,(float)(r+size)/Chunk::subsize))
        {
            //bad++;
            continue;
        }
        occlusion = voxel.occlusion;
        type = voxel.type;
        
        d = glm::vec3(voxel.x/Chunk::subsize, voxel.y/Chunk::subsize, voxel.z/Chunk::subsize) - camera->getPosition();
        
        mask = TOP;
        if(voxel.z/Chunk::subsize>camera->getPosition().z)
            mask |= BACK;
        if(voxel.x/Chunk::subsize<camera->getPosition().x)
            mask |= RIGHT;
        if(voxel.z/Chunk::subsize<camera->getPosition().z)
            mask |= FRONT;
        if(voxel.x/Chunk::subsize>camera->getPosition().x)
            mask |= LEFT;
        
        if(isCubeFreeWithMask(p, q, r, size, mask))
        //if(!isCubeOccluded(p,q,r,size, mask))
        {
            _p = p/Chunk::subsize;
            _q = q/Chunk::subsize;
            _r = r/Chunk::subsize;
         
            chp = _p / 16;
            chq = _q / 16;
            chr = _r / 16;
         
            cup = _p % 16;
            cuq = _q % 16;
            cur = _r % 16;
         
            pp = p%Chunk::subsize;
            qq = q%Chunk::subsize;
            rr = r%Chunk::subsize;
         
            sizeM1 = size-1;
         
            _offset =  (   pp + (cup << 4) + (chp << 8) +
         ((qq + (cuq << 4) + (chq << 8)) << 10) +
         ( (( rr + (cur << 4) + (chr << 8) )) << 20) );
         
            vec->push_back(_offset);
         
            _size = (type << 20) + (occlusion << 18) + ((sizeM1) << 12) + ((sizeM1) << 6) + (sizeM1);
         
            vec->push_back(_size);
        
        }
        //else
        //    bad++;
    }
    }
    //usleep(1000000);
    currentTime = glfwGetTime() - currentTime;
    std::cout << currentTime << std::endl;
}

bool Processor::isCubeOccluded(int x, int y, int z, int size, unsigned char mask)
{
    if(mask & BOTTOM)
        if(!isPointOccluded(x+size/2.0, y, z+size/2.0))
            return false;
    if(mask & LEFT)
        if(!isPointOccluded(x, y+size/2.0, z+size/2.0))
            return false;
    if(mask & FRONT)
        if(!isPointOccluded(x+size/2.0, y+size/2.0, z+size))
            return false;
    if(mask & RIGHT)
        if(!isPointOccluded(x+size, y+size/2.0, z+size/2.0))
            return false;
    if(mask & BACK)
        if(!isPointOccluded(x+size/2.0, y+size/2.0, z))
            return false;
    if(mask & TOP)
        if(!isPointOccluded(x+size/2.0, y+size, z+size/2.0))
            return false;
    
    return true;
}

bool Processor::isPointOccluded(int x, int y, int z)
{
    vertexPosition = glm::vec3(x,y,z);
    vertexPosition /= Chunk::subsize;
    
    viewSpace = Scene::VM * glm::vec4(vertexPosition,1);
    position = Scene::projection * viewSpace;
    
    if(position.z < 0)
        return true;
    if(position.x<-position.w || position.y<-position.w || position.x>position.w || position.y>position.w )
        return true;
    
    _x = position.x+position.w;
    _y = position.y+position.w;
    
    _x = 1920 * _x / (2*position.w);
    _y = 1080 * _y / (2*position.w);
    
    unproj = glm::inverse(Scene::projection * Scene::VM) * glm::vec4(_x,_y,0.0009f,1);
    
    unproj.w = 1.0 / unproj.w;
    
    unproj.x *= unproj.w;
    unproj.y *= unproj.w;
    unproj.z *= unproj.w;
    
    base = bufferizeWorld->getLeaf(x, y, z);
    
    ray = new Ray(glm::vec3(x,y,z), glm::vec3(unproj.x*Chunk::subsize, unproj.y*Chunk::subsize, unproj.z*Chunk::subsize));
    
    end = max(end, (int)abs(ray->getStart().x-ray->getDirection().x));
    end = max(end, (int)abs(ray->getStart().y-ray->getDirection().y));
    end = max(end, (int)abs(ray->getStart().z-ray->getDirection().z));
    
    //OctreeEntry* octreeEntry = NULL;
    
    d = ray->move(end);
    
    for(int i = 0; i < end/rayCastStep; i+=rayCastStep)
    {
        d = ray->move(i);
        if(d.x < 0 || d.y < 0 || d.z < 0 || d.x > Chunk::size*Chunk::subsize*(World::size*2+1) || d.y > Chunk::size*Chunk::subsize || d.z > Chunk::size*Chunk::subsize*(World::size*2+1))
            return false;
        
        octreeEntry = bufferizeWorld->getLeaf(d.x, d.y, d.z);
        
        if(octreeEntry != NULL)
        {
            empty = dynamic_cast<Empty*>(octreeEntry);
            if(empty!=NULL)
                continue;
            if(octreeEntry != base)
                return true;
        }
    }
    
    return false;
}

void Processor::bufferizeLeaf(Chunk* chunk, Leaf * leaf, vector<GLuint>* vec, int p, int q, int r, int size)
{
    if(leaf->occluded && !leaf->visible)
        return;
    
    unsigned char type = leaf->getType();
    unsigned char occlusion = leaf->getOcclusion();
    
    if(type > 0)
    {
        if(!leaf->occluded)
        {
            leaf->visible = isCubeVisible(p,q,r,size);
            leaf->occluded = true;
        }
        
        if(leaf->visible)
        {
            chunk->voxels.push_back(Voxel(p,q,r,size, occlusion, type));
            //addVoxel(Voxel(p,q,r,size, leaf->getOcclusion(), leaf->getType()));
            
            //voxels.push_back(Voxel(p,q,r,size, leaf->getOcclusion(), leaf->getType()));
            
            //if(!isCubeInFrustum(p/Chunk::subsize,q/Chunk::subsize,r/Chunk::subsize,(p+size)/Chunk::subsize,(q+size)/Chunk::subsize,(r+size)/Chunk::subsize))
            //    return;
            
            //if(isCubeFreeWithMask(p, q, r, size))
                //if(!bufferizeWorld->isCubeOccluded(p,q,r,size))
                {
                    //---
                    
                    //vector<GLuint>* data = vertexBuffer->getData();
                    
                    /*int _p = p/Chunk::subsize;
                    int _q = q/Chunk::subsize;
                    int _r = r/Chunk::subsize;
                    
                    int chp = _p / 16;
                    int chq = _q / 16;
                    int chr = _r / 16;
                    
                    int cup = _p % 16;
                    int cuq = _q % 16;
                    int cur = _r % 16;
                    
                    int pp = ((int)p)%Chunk::subsize;
                    int qq = ((int)q)%Chunk::subsize;
                    int rr = ((int)r)%Chunk::subsize;
                    
                    int sizeM1 = size-1;
                    
                    unsigned int _offset =  (   pp + (int)(cup << 4) + (chp << 8) +
                                             ((qq + (int)(cuq << 4) + (chq << 8)) << 10) +
                                             ( (( rr + (int)(cur << 4) + (chr << 8) )) << 20) );
                    
                    vec->push_back(_offset);
                    
                    unsigned int size = (type << 20) + (occlusion << 18) + ((sizeM1) << 12) + ((sizeM1) << 6) + (sizeM1);
                    
                    vec->push_back(size);*/
                    
                    //bufferizeWorld->setOccludedCount(bufferizeWorld->getOccludedCount()+1);
                }
        }
        //else
        //    bufferizeWorld->setInstanceCount(bufferizeWorld->getInstanceCount()+1);
        //bufferizeWorld->setCubeCount(bufferizeWorld->getCubeCount()+size*size*size);
    }
}
// End of user code






