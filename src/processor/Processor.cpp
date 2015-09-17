
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
OctreeEntry<Voxel*>* Processor::base = NULL;
OctreeEntry<Voxel*>* Processor::octreeEntry = NULL;
Empty<Voxel*>* Processor::empty = NULL;
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
    
    if(position.z / position.w < 0.0009f)
        return false;
    if(position.x>=-position.w && position.y>=-position.w && position.x<=position.w && position.y<=position.w )
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
    
    return false;

    // End of user code
}

char Processor::isCubeVisible(int x, int y, int z, int size)
{
    // Start of user code isCubeVisible
    
    char visible = 0;
    
    int maxPosition = (Chunk::size*Chunk::subsize-1);
    int sizeM1 = size-1;
    int yPSize = y+size;
    int chunksWidth = World::size*2+1;
    
    //ground occlusion
    if( y==0 && bufferizeWorld->getCube(x, y+size, z) > 0)
        return 0;
    
    //geometry occlusion
    //if(!isCubeFree(x, y, z, size))
    //    return 0;
    
    //side occlusion
    if( x==0 )
    {
        if( bufferizeWorld->getCube(x, yPSize, z)>0 )
            return false;
    }
    
    if( (x+sizeM1)==((chunksWidth)*maxPosition))
    {
        if( bufferizeWorld->getCube(x, yPSize, z)>0 )
            return 0;
    }
    
    if( (z+sizeM1)==((chunksWidth)*maxPosition))
    {
        if( bufferizeWorld->getCube(x, yPSize, z)>0 )
            return 0;
    }
    
    if( z==0 )
    {
        if( bufferizeWorld->getCube(x, yPSize, z)>0 )
            return 0;
    }
    
    //geometry occlusion
    for(int i = size-1; i >= 0; i--)
        for(int j = size-1; j >= 0; j--)
        {
            if(!(visible & LEFT))
                if(bufferizeWorld->getCube(x-1, y+i,   z+j) == 0)
                    visible |= LEFT;
            if(!(visible & RIGHT))
                if(bufferizeWorld->getCube((x+size-1)+1, y+i,   z+j) == 0)
                    visible |= RIGHT;
            if(!(visible & BOTTOM))
                if(bufferizeWorld->getCube(x+i, y-1,   z+j) == 0)
                    visible |= BOTTOM;
            if(!(visible & TOP))
                if(bufferizeWorld->getCube(x+i, (y+size-1)+1,   z+j) == 0)
                    visible |= TOP;
            if(!(visible & BACK))
                if(bufferizeWorld->getCube(x+i, y+j,   z-1) == 0)
                    visible |= BACK;
            if(!(visible & FRONT))
                if(bufferizeWorld->getCube(x+i, y+j,   (z+size-1)+1) == 0)
                    visible |= FRONT;
        }
    
    if(visible)
    {
        int a = 2;
    }
    
    return visible;
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
    
    Voxel* voxel;
    
    /*int p = voxel.x;
    int q = voxel.y;
    int r = voxel.z;
    int size = voxel.size;
    int occlusion = voxel.occlusion;
    int type = voxel.type;*/
    
    vec->clear();
    
    Chunk* chunk = NULL;
    
    glm::vec3 d;
    
    unsigned char mask = TOP;
    
    Camera* camera = Engine::getInstance()->getScene()->getSelectedCamera();
    
    double currentTime = glfwGetTime();
    
    for(int c = 0; c < chunks.size(); c++)
    {
        chunk = chunks[c];
        if(!isCubeInFrustum(chunk->getP()*Chunk::size, chunk->getQ()*Chunk::size, chunk->getR()*Chunk::size, (chunk->getP()+1)*Chunk::size, (chunk->getQ()+1)*Chunk::size, (chunk->getR()+1)*Chunk::size))
            continue;
        for(int i = 0; i < chunks[c]->voxels.size(); i++)
        {
            voxel = chunk->voxels[i];
        
            /*p = voxel.x;
            q = voxel.y;
            r = voxel.z;
            size = voxel.size;*/
            
            mask = TOP;
            if(voxel->z/Chunk::subsize>camera->getPosition().z)
                mask |= BACK;
            if(voxel->x/Chunk::subsize<camera->getPosition().x)
                mask |= RIGHT;
            if(voxel->z/Chunk::subsize<camera->getPosition().z)
                mask |= FRONT;
            if(voxel->x/Chunk::subsize>camera->getPosition().x)
                mask |= LEFT;
            
            /*if(isPointInFrustum(x1, y1, z1))
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
             return true;*/
            
            //if(!isCubeInFrustum((float)p/Chunk::subsize,(float)q/Chunk::subsize,(float)r/Chunk::subsize,(float)(p+size)/Chunk::subsize,(float)(q+size)/Chunk::subsize,(float)(r+size)/Chunk::subsize))
            //if(!isCubeInFrustum(voxel.x_16, voxel.y_16, voxel.z_16, voxel.x_size_16, voxel.y_size_16, voxel.z_size_16))
            //    continue;
            
            //if(!isCubeFreeWithMask(p, q, r, size, mask))
            //    continue;
            
            if( (mask & TOP && !(voxel->visible & TOP)) &&
                (mask & BOTTOM && !(voxel->visible & BOTTOM)) &&
                (mask & LEFT && !(voxel->visible & LEFT)) &&
                (mask & RIGHT && !(voxel->visible & RIGHT)) &&
                (mask & FRONT && !(voxel->visible & FRONT)) &&
                (mask & BACK && !(voxel->visible & BACK)))
                    continue;
            
            bool draw = true;
            
            vertexPosition = glm::vec3(voxel->x_size_16_2, voxel->y_size_16_2, voxel->z_size_16_2);
            viewSpace = Scene::VM * glm::vec4(vertexPosition,1);
            position = Scene::projection * viewSpace;
                
            if( !(position.z / position.w > 0.0009f && position.x>=-position.w && position.y>=-position.w && position.x<=position.w && position.y<=position.w) )
                continue;
            
            /*_x = position.x+position.w;
            _y = position.y+position.w;
            
            _x = 1920 * _x / (2*position.w);
            _y = 1080 * _y / (2*position.w);
            
            unproj = glm::inverse(Scene::projection * Scene::VM) * glm::vec4(_x,_y,0.0009f,200.0f);//1);
            
            unproj.w = 1.0 / unproj.w;
            
            unproj.x *= unproj.w;
            unproj.y *= unproj.w;
            unproj.z *= unproj.w;
            
            base = bufferizeWorld->getLeaf(voxel.x, voxel.y, voxel.z);
            
            empty = dynamic_cast<Empty*>(base);
            
            ray = new Ray(glm::vec3(voxel.x, voxel.y, voxel.z), glm::vec3(unproj.x*Chunk::subsize, unproj.y*Chunk::subsize, unproj.z*Chunk::subsize));
            
            end = max(end, (int)abs(ray->getStart().x-ray->getDirection().x));
            end = max(end, (int)abs(ray->getStart().y-ray->getDirection().y));
            end = max(end, (int)abs(ray->getStart().z-ray->getDirection().z));
            
            d = ray->move(end);
            
            draw = true;
            
            for(int i = 0; i < end/rayCastStep; i+=rayCastStep)
            {
                d = ray->move(i);
                if(d.x < 0 || d.y < 0 || d.z < 0 || d.x > Chunk::size*Chunk::subsize*(World::size*2+1) || d.y > Chunk::size*Chunk::subsize || d.z > Chunk::size*Chunk::subsize*(World::size*2+1))
                {
                    delete ray;
                    //draw = true;
                    break;
                }
                
                octreeEntry = bufferizeWorld->getLeaf(d.x, d.y, d.z);
                
                if(octreeEntry != NULL)
                {
                    empty = dynamic_cast<Empty*>(octreeEntry);
                    if(empty!=NULL)
                    {
                        delete empty;
                        continue;
                    }
                    if(octreeEntry != base)
                    {
                        draw = false;
                        break;
                    }
                }
            }*/
            
            if(draw)
            {
                vec->push_back(voxel->offsetRegister.raw);
                vec->push_back(voxel->sizeRegister.raw);
            }
            
            /*if(mask & TOP)
            {
                vertexPosition = glm::vec3(voxel.x_size_16_2, voxel.y_size_16, voxel.z_size_16_2);
                viewSpace = Scene::VM * glm::vec4(vertexPosition,1);
                position = Scene::projection * viewSpace;
                
                if(position.z / position.w > 0.0009f && position.x>=-position.w && position.y>=-position.w && position.x<=position.w && position.y<=position.w )
                {
                    vec->push_back(voxel.offsetRegister.raw);
                    vec->push_back(voxel.sizeRegister.raw);
                    continue;
                }
            }
            if(mask & BACK)
            {
                vertexPosition = glm::vec3(voxel.x_size_16_2, voxel.y_size_16_2, voxel.z_16);
                viewSpace = Scene::VM * glm::vec4(vertexPosition,1);
                position = Scene::projection * viewSpace;
                
                if(position.z / position.w > 0.0009f && position.x>=-position.w && position.y>=-position.w && position.x<=position.w && position.y<=position.w )
                {
                    vec->push_back(voxel.offsetRegister.raw);
                    vec->push_back(voxel.sizeRegister.raw);
                    continue;
                }
            }
            if(mask & RIGHT)
            {
                vertexPosition = glm::vec3(voxel.x_size_16, voxel.y_size_16_2, voxel.z_size_16_2);
                viewSpace = Scene::VM * glm::vec4(vertexPosition,1);
                position = Scene::projection * viewSpace;
                
                if(position.z / position.w > 0.0009f && position.x>=-position.w && position.y>=-position.w && position.x<=position.w && position.y<=position.w )
                {
                    vec->push_back(voxel.offsetRegister.raw);
                    vec->push_back(voxel.sizeRegister.raw);
                    continue;
                }
            }
            if(mask & FRONT)
            {
                vertexPosition = glm::vec3(voxel.x_size_16_2, voxel.y_size_16_2, voxel.z_size_16);
                viewSpace = Scene::VM * glm::vec4(vertexPosition,1);
                position = Scene::projection * viewSpace;
                
                if(position.z / position.w > 0.0009f && position.x>=-position.w && position.y>=-position.w && position.x<=position.w && position.y<=position.w )
                {
                    vec->push_back(voxel.offsetRegister.raw);
                    vec->push_back(voxel.sizeRegister.raw);
                    continue;
                }
            }
            if(mask & LEFT)
            {
                vertexPosition = glm::vec3(voxel.x_16, voxel.y_size_16_2, voxel.z_size_16_2);
                viewSpace = Scene::VM * glm::vec4(vertexPosition,1);
                position = Scene::projection * viewSpace;
                
                if(position.z / position.w > 0.0009f && position.x>=-position.w && position.y>=-position.w && position.x<=position.w && position.y<=position.w )
                {
                    vec->push_back(voxel.offsetRegister.raw);
                    vec->push_back(voxel.sizeRegister.raw);
                    continue;
                }
            }
            if(mask & BOTTOM)
            {
                vertexPosition = glm::vec3(voxel.x_size_16_2, voxel.y_16, voxel.z_size_16_2);
                viewSpace = Scene::VM * glm::vec4(vertexPosition,1);
                position = Scene::projection * viewSpace;
                
                if(position.z / position.w > 0.0009f && position.x>=-position.w && position.y>=-position.w && position.x<=position.w && position.y<=position.w )
                {
                    vec->push_back(voxel.offsetRegister.raw);
                    vec->push_back(voxel.sizeRegister.raw);
                    continue;
                }
            }*/
            
            //vec->push_back(voxel.offsetRegister.raw);
            //vec->push_back(voxel.sizeRegister.raw);
        
            //occlusion = voxel.occlusion;
            //type = voxel.type;
        
            //d = glm::vec3(voxel.x/Chunk::subsize, voxel.y/Chunk::subsize, voxel.z/Chunk::subsize) - camera->getPosition();
        
            
        
        //if(isCubeFreeWithMask(p, q, r, size, mask))
        //if(!isCubeOccluded(p,q,r,size, mask))
            {
                //vec->push_back(voxel.offsetRegister.raw);
         
                //vec->push_back(voxel.sizeRegister.raw);
            }
        }
    }
    currentTime = glfwGetTime() - currentTime;
    std::cout << currentTime << std::endl;
}

bool Processor::isCubeOccluded(int x, int y, int z, int size, unsigned char mask)
{
    unsigned char cpt = 0;

    if(mask & BOTTOM)
        if(isPointOccluded(x, y, z, size/2.0, 0, size/2.0))
        //if(isPointOccluded(x+size/2.0, y, z+size/2.0))
            cpt++;//return false;
    if(mask & LEFT)
        if(isPointOccluded(x, y, z, 0, size/2.0,size/2.0))
        //if(isPointOccluded(x, y+size/2.0, z+size/2.0))
            cpt++;//return false;
    if(mask & FRONT)
        if(isPointOccluded(x, y, z, size/2.0, size/2.0, size))
        //if(isPointOccluded(x+size/2.0, y+size/2.0, z+size))
            cpt++;//return false;
    if(mask & RIGHT)
        if(isPointOccluded(x, y, z, size, size/2.0, size/2.0))
        //if(isPointOccluded(x+size, y+size/2.0, z+size/2.0))
            cpt++;//return false;
    if(mask & BACK)
        if(isPointOccluded(x, y, z, size/2.0, size/2.0, 0))
        //if(isPointOccluded(x+size/2.0, y+size/2.0, z))
            cpt++;//return false;
    if(mask & TOP)
        if(isPointOccluded(x, y, z, size/2.0, size, size/2.0))
        //if(isPointOccluded(x+size/2.0, y+size, z+size/2.0))
            cpt++;//return false;

    if(cpt == 3)
        return true;
    return false;
}

bool Processor::isPointOccluded(int x, int y, int z, double dx, double dy, double dz)
{
    vertexPosition = glm::vec3(x+dx,y+dy,z+dz);
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
    
    unproj = glm::inverse(Scene::projection * Scene::VM) * glm::vec4(_x,_y,0.0009f,200.0f);//1);
    
    unproj.w = 1.0 / unproj.w;
    
    unproj.x *= unproj.w;
    unproj.y *= unproj.w;
    unproj.z *= unproj.w;
    
    base = bufferizeWorld->getLeaf(x, y, z);
    
    empty = dynamic_cast<Empty<Voxel*>*>(base);
    
    ray = new Ray(glm::vec3(x,y,z), glm::vec3(unproj.x*Chunk::subsize, unproj.y*Chunk::subsize, unproj.z*Chunk::subsize));
    
    end = max(end, (int)abs(ray->getStart().x-ray->getDirection().x));
    end = max(end, (int)abs(ray->getStart().y-ray->getDirection().y));
    end = max(end, (int)abs(ray->getStart().z-ray->getDirection().z));
    
    d = ray->move(end);
    
    for(int i = 0; i < end/rayCastStep; i+=rayCastStep)
    {
        d = ray->move(i);
        if(d.x < 0 || d.y < 0 || d.z < 0 || d.x > Chunk::size*Chunk::subsize*(World::size*2+1) || d.y > Chunk::size*Chunk::subsize || d.z > Chunk::size*Chunk::subsize*(World::size*2+1))
        {
            delete ray;
            return false;
        }
        
        octreeEntry = bufferizeWorld->getLeaf(d.x, d.y, d.z);
        
        if(octreeEntry != NULL)
        {
            empty = dynamic_cast<Empty<Voxel*>*>(octreeEntry);
            if(empty!=NULL)
            {
                delete empty;
                continue;
            }
            if(octreeEntry != base)
            {
                delete ray;
                return true;
            }
        }
    }
    
    delete ray;
    return false;
}

void Processor::bufferizeLeaf(Chunk* chunk, Leaf<Voxel*> * leaf, vector<GLuint>* vec, int p, int q, int r, int size)
{
    if(leaf->getValue()->occluded && !leaf->getValue()->visible)
        return;
    
    //unsigned char type = leaf->getType();
    //unsigned char occlusion = leaf->getOcclusion();
    
    if(leaf->getValue()->sizeRegister.field.type > 0)
    {
        if(!leaf->getValue()->occluded)
        {
            leaf->getValue()->visible = isCubeVisible(p,q,r,size);
            leaf->getValue()->occluded = true;
        }
        
        if(leaf->getValue()->visible)
        {
            chunk->voxels.push_back(leaf->getValue());//Voxel(p,q,r,size, occlusion, type, leaf->visible));
        }
    }
}
// End of user code






