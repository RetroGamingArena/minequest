#include <cstdlib>

#include "Processor.h"
// Start of user code includes
// End of user code


Processor::Processor()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}


// Start of user code methods
World* Processor::bufferizeWorld = NULL;


void Processor::bufferizeLeaf(Leaf * leaf, vector<GLuint>* vec, int p, int q, int r, int size)
{
    World* world = bufferizeWorld;//Engine::getInstance()->getWorld();
    
    unsigned char type = leaf->getType();
    unsigned char occlusion = leaf->getOcclusion();
    
    if(type > 0)
    {
        if(!leaf->occluded)
        {
            leaf->visible = world->isCubeVisible(p,q,r,size);
            leaf->occluded = true;
        }
        
        if(!world->isCubeInFrustum(p/Chunk::subsize,q/Chunk::subsize,r/Chunk::subsize,(p+size)/Chunk::subsize,(q+size)/Chunk::subsize,(r+size)/Chunk::subsize))
            return;
        
        if(leaf->visible)
        {
            if(world->isCubeFreeWithMask(p, q, r, size))
                //if(!world->isCubeOccluded(p,q,r,size))
                {
                    //---
                    
                    //vector<GLuint>* data = vertexBuffer->getData();
                    
                    int _p = p/Chunk::subsize;
                    int _q = q/Chunk::subsize;
                    int _r = r/Chunk::subsize;
                    
                    int chp = _p / 8;
                    int chq = _q / 8;
                    int chr = _r / 8;
                    
                    int cup = _p % 8;
                    int cuq = _q % 8;
                    int cur = _r % 8;
                    
                    int pp = ((int)p)%Chunk::subsize;
                    int qq = ((int)q)%Chunk::subsize;
                    int rr = ((int)r)%Chunk::subsize;
                    
                    int sizeM1 = size-1;
                    
                    unsigned int _offset =  (   pp + (int)(cup << 4) + (chp << 7) +
                                             ((qq + (int)(cuq << 4) + (chq << 7)) << 10) +
                                             ( (( rr + (int)(cur << 4) + (chr << 7) )) << 20) );
                    
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
                    
                    world->setOccludedCount(world->getOccludedCount()+1);
                }
        }
        else
            world->setInstanceCount(world->getInstanceCount()+1);
        world->setCubeCount(world->getCubeCount()+size*size*size);
    }
}
// End of user code






