#include <cstdlib>

#include "Leaf.h"
// Start of user code includes
#include "Chunk.h"
#include "Engine.h"
// End of user code

Leaf::Leaf(unsigned char _type, unsigned char _occlusion)
{
	type = _type;
	occlusion = _occlusion;
}

Leaf::Leaf()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    occluded = 0;
    visible = 0;
	// End of user code
}

Leaf::~Leaf()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
World* Leaf::bufferizeWorld = NULL;;
// End of user code

bool Leaf::isCompressible()
{
	// Start of user code isCompressible
    return false;
	// End of user code
}
int Leaf::getCode()
{
	// Start of user code getCode
    return type;
	// End of user code
}
unsigned char Leaf::getAbs(int x, int y, int z, int size)
{
	// Start of user code getAbs
    return type;
	// End of user code
}
void Leaf::bufferize(VertexBuffer * vertexBuffer, float p, float q, float r, float size)
{
	// Start of user code bufferize
    World* world = bufferizeWorld;//Engine::getInstance()->getWorld();
    
    if(getType() > 0)
    {
        if(!occluded)
        {
            visible = true;//world->isCubeVisible(p,q,r,size);
            occluded = true;
        }
        
        if(!world->isCubeInFrustum(p/Chunk::subsize,q/Chunk::subsize,r/Chunk::subsize,(p+size)/Chunk::subsize,(q+size)/Chunk::subsize,(r+size)/Chunk::subsize))
            return;
        
        //if(visible)
        {
            //if(!world->isCubeOccluded(p,q,r,size))
            {
                //bufferizeWorld->bufferizeEntry(vertexBuffer, type, p/Chunk::subsize, q/Chunk::subsize, r/Chunk::subsize, size, size, size, occlusion);
                
                //---
                
                vector<GLuint>* data = vertexBuffer->getData();
                
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
                 
                data->push_back(_offset);
                 
                unsigned int size = (type << 20) + (occlusion << 18) + ((sizeM1) << 12) + ((sizeM1) << 6) + (sizeM1);
                 
                data->push_back(size);
                
                /*int sizeM1 = size-1;
                
                int pInt = (int)_p;
                double pDecimal = _p-pInt;
                 
                int qInt = (int)_q;
                double qDecimal = _q-qInt;
                 
                int rInt = (int)_r;
                double rDecimal = _r-rInt;*/
                 
                //vector<GLuint>* data = vertexBuffer->getData();
                 
                //unsigned int _offset =  (   (int)(pDecimal / 0.0625) + (int)((pInt%8) << 4) + ((pInt/8) << 7) +
                // (((int)(qDecimal / 0.0625) + (int)((qInt%8) << 4) + ((qInt/8) << 7)) << 10) +
                // ( (( (int)(rDecimal / 0.0625) + (int)((rInt%8) << 4) + ((rInt/8) << 7) )) << 20) );
                 
                //data->push_back(_offset);
                 
                //unsigned int size = (type << 20) + (occlusion << 18) + ((sizeM1) << 12) + ((sizeM1) << 6) + (sizeM1);
                 
                //data->push_back(size);
                //---
                
                //world->setOccludedCount(world->getOccludedCount()+1);
            }
        }
        //else
        //{}//world->setInstanceCount(world->getInstanceCount()+1);
        //world->setCubeCount(world->getCubeCount()+size*size*size);
    }
	// End of user code
}
OctreeEntry* Leaf::getLeafAbs(int x, int y, int z, int size)
{
	// Start of user code getLeafAbs
    return this;
	// End of user code
}



unsigned char Leaf::getType()
{
	// Start of user code getType
	// End of user code
	return type;
}

void Leaf::setType(unsigned char _type)
{
	type = _type;
}

unsigned char Leaf::getOcclusion()
{
	// Start of user code getOcclusion
	// End of user code
	return occlusion;
}

void Leaf::setOcclusion(unsigned char _occlusion)
{
	occlusion = _occlusion;
}



