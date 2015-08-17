
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
//Camera* World::camera = NULL;
double Processor::near = 0;//0.997;
World* Processor::bufferizeWorld = NULL;
std::mutex* Processor::addVoxelMutex = new std::mutex();

void Processor::addVoxel(Voxel voxel)
{
    addVoxelMutex->lock();
    voxels.push_back(voxel);
    addVoxelMutex->unlock();
}

#define ANG2RAD 3.14159265358979323846/180.0

double Processor::isCubeInFrustum(double x1, double y1, double z1, double x2, double y2, double z2)
{
    // Start of user code isCubeInFrustum
    
    Camera* camera = Engine::getInstance()->getScene()->getSelectedCamera();
    
    glm::vec3 p(x1,y1,z1);
    
    float pcz,pcx,pcy,aux;
    
    float farD = 200.0f;
    float nearD = 0.009f;
    float angle = 70.0f;
    float ratio = 192.0f / 108.0f;
    float tang = (float)tan(ANG2RAD * angle * 0.5);

    // compute vector from camera position to p
    glm::vec3 v = p-camera->getPosition();//camPos;
    
    glm::vec3 Z;
    Z = camera->getCenter() - p;
    
    float length = Z.length();
    Z = Z / length;//glm::normalize(Z);

    glm::vec3 X = Z * camera->getUp();
    
    length = Z.length();
    X = X / length;//glm::normalize(X);
    
    // the real "up" vector is the cross product of X and Z
    glm::vec3 Y = X * Z;
    
    // compute and test the Z coordinate
    pcz = v.x*-Z.x + v.y*-Z.y + v.z*-Z.z;
    if (pcz > farD || pcz < nearD)
        return false;
    
    // compute and test the Y coordinate
    pcy = v.x*Y.x + v.y*Y.y + v.z*Y.z;
    aux = pcz * tang;
    if (pcy > aux || pcy < -aux)
        return false;
    
    // compute and test the X coordinate
    pcz = v.x*X.x + v.y*X.y + v.z*X.z;
    aux = aux * ratio;
    if (pcx > aux || pcx < -aux)
        return false;
    
    p = glm::vec3(x2,y2,z2);
    
    // compute vector from camera position to p
    v = p-camera->getPosition();//camPos;
    
    Z = camera->getCenter() - p;
    
    length = Z.length();
    Z = glm::normalize(Z);
    
    X = Z * camera->getUp();
    
    length = Z.length();
    X= X / length;//glm::normalize(X);
    
    // the real "up" vector is the cross product of X and Z
    Y = X * Z;
    
    // compute and test the Z coordinate
    pcz = v.x*-Z.x + v.y*-Z.y + v.z*-Z.z;
    if (pcz > farD || pcz < nearD)
        return false;
    
    // compute and test the Y coordinate
    pcy = v.x*Y.x + v.y*Y.y + v.z*Y.z;
    aux = pcz * tang;
    if (pcy > aux || pcy < -aux)
        return false;
    
    // compute and test the X coordinate
    pcz = v.x*X.x + v.y*X.y + v.z*X.z;
    aux = aux * ratio;
    if (pcx > aux || pcx < -aux)
        return false;
    
    return true;
    

    
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

void Processor::bufferizeVoxels(/*vector<GLuint>* vec*/)
{
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

    int good = 0;
    int bad = 0;
    
    vec->clear();
    
    for(int i = 0; i < voxels.size(); i++)
    {
        voxel = voxels[i];
        
        p = voxel.x;
        q = voxel.y;
        r = voxel.z;
        size = voxel.size;
        
        if(!isCubeInFrustum((float)p/Chunk::subsize,(float)q/Chunk::subsize,(float)r/Chunk::subsize,(float)(p+size)/Chunk::subsize,(float)(q+size)/Chunk::subsize,(float)(r+size)/Chunk::subsize))
        {
            bad++;
            //continue;
        }
        good++;

        occlusion = voxel.occlusion;
        type = voxel.type;
        
        //if(isCubeFreeWithMask(p, q, r, size))
        //if(!bufferizeWorld->isCubeOccluded(p,q,r,size))
        {
            //---
        
            //vector<GLuint>* data = vertexBuffer->getData();
        
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
        
            //bufferizeWorld->setOccludedCount(bufferizeWorld->getOccludedCount()+1);
        }
    }
    
    if(vec->size() < 1000)
    {
        int a = 1;
    }
    
    currentTime = glfwGetTime() - currentTime;
    std::cout << currentTime << std::endl;
}

void Processor::bufferizeLeaf(Leaf * leaf, vector<GLuint>* vec, int p, int q, int r, int size)
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
            addVoxel(Voxel(p,q,r,size, leaf->getOcclusion(), leaf->getType()));
            
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






