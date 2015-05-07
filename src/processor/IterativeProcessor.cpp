#include <cstdlib>

#include "IterativeProcessor.h"
// Start of user code includes
// End of user code


IterativeProcessor::IterativeProcessor()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

// Start of user code methods
// End of user code

void IterativeProcessor::bufferize(GameScene * gameScene, World * world)
{
	// Start of user code bufferize
    /*int x = 0;
    int y = 0;
    int z = 0;
    
    int p = 0;
    int q = 0;
    int r = 0;
    
    float size = 1.0 / Chunk::subsize;
    
    float type = 2;
    
    float* ao = new float[4];
    
    ao[0] = 0;
    ao[1] = 0;
    ao[2] = 0;
    ao[3] = 0;
    
    Cube::bufferizeSquare(scene, x+p, y+q,      z+r, x+p+size, y+q,      z+r+size, type, ao); //bottom
    
    Cube::bufferizeIndice(scene, 0);
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 3);
    
    ao[0] = 1;
    ao[1] = 1;
    ao[2] = 1;
    ao[3] = 1;
    
    Cube::bufferizeSquare(scene, x+p, y+q+size, z+r, x+p+size, y+q+size, z+r+size, type, ao); //top
    
    Cube::bufferizeIndice(scene, 4);
    Cube::bufferizeIndice(scene, 5);
    Cube::bufferizeIndice(scene, 6);
    Cube::bufferizeIndice(scene, 7);
    
    Cube::bufferizeIndice(scene, 0);
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 4);
    Cube::bufferizeIndice(scene, 5);
    
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 3);
    Cube::bufferizeIndice(scene, 5);
    Cube::bufferizeIndice(scene, 7);
    
    Cube::bufferizeIndice(scene, 3);
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 7);
    Cube::bufferizeIndice(scene, 6);
    
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 0);
    Cube::bufferizeIndice(scene, 6);
    Cube::bufferizeIndice(scene, 4);
    
    threadCount = 5;
    this->start();
    while(isRunning()){}
    
    for(int i=0; i < world->getChunks().size() ; i++)
    {
        Chunk* chunk = world->getChunks()[i];
        scene->getBuffer()->getData()->insert(scene->getBuffer()->getData()->end(), chunk->getBuffer()->getData()->begin(), chunk->getBuffer()->getData()->end());
        chunk->getBuffer()->getData()->clear();
    }*/
	// End of user code
}





