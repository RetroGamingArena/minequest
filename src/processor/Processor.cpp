#include <cstdlib>

#include "Processor.h"
// Start of user code includes
#include "CubeFace.h"
// End of user code


Processor::Processor()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}


// Start of user code methods
glm::vec4 Processor::viewport = glm::vec4(0,0,1920,1080);
//Camera* World::camera = NULL;
double Processor::near = 0;//0.997;
World* Processor::bufferizeWorld = NULL;

double Processor::isCubeInFrustum(double x1, double y1, double z1, double x2, double y2, double z2)
{
    // Start of user code isCubeInFrustum
    glm::vec3 project;
    
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

void Processor::bufferizeLeaf(Leaf * leaf, vector<GLuint>* vec, int p, int q, int r, int size)
{
    unsigned char type = leaf->getType();
    unsigned char occlusion = leaf->getOcclusion();
    
    if(type > 0)
    {
        if(!leaf->occluded)
        {
            leaf->visible = isCubeVisible(p,q,r,size);
            leaf->occluded = true;
        }
        
        if(!isCubeInFrustum(p/Chunk::subsize,q/Chunk::subsize,r/Chunk::subsize,(p+size)/Chunk::subsize,(q+size)/Chunk::subsize,(r+size)/Chunk::subsize))
            return;
        
        if(leaf->visible)
        {
            if(isCubeFreeWithMask(p, q, r, size))
                if(!bufferizeWorld->isCubeOccluded(p,q,r,size))
                {
                    //---
                    
                    //vector<GLuint>* data = vertexBuffer->getData();
                    
                    int _p = p/Chunk::subsize;
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
                    
                    vec->push_back(size);
                    
                    //vector<GLuint>* data = vertexBuffer->getData();
                    
                    //unsigned int _offset =  (   (int)(pDecimal / 0.0625) + (int)((pInt%8) << 4) + ((pInt/8) << 7) +
                    // (((int)(qDecimal / 0.0625) + (int)((qInt%8) << 4) + ((qInt/8) << 7)) << 10) +
                    // ( (( (int)(rDecimal / 0.0625) + (int)((rInt%8) << 4) + ((rInt/8) << 7) )) << 20) );
                    
                    //data->push_back(_offset);
                    
                    //unsigned int size = (type << 20) + (occlusion << 18) + ((sizeM1) << 12) + ((sizeM1) << 6) + (sizeM1);
                    
                    //data->push_back(size);
                    //---
                    
                    bufferizeWorld->setOccludedCount(bufferizeWorld->getOccludedCount()+1);
                }
        }
        else
            bufferizeWorld->setInstanceCount(bufferizeWorld->getInstanceCount()+1);
        bufferizeWorld->setCubeCount(bufferizeWorld->getCubeCount()+size*size*size);
    }
}
// End of user code






