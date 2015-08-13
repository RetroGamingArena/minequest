#include <cstdlib>

#include "ChunkProcessorTask.h"
// Start of user code includes
#include <iostream>
// End of user code


ChunkProcessorTask::ChunkProcessorTask()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

ChunkProcessorTask::~ChunkProcessorTask()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code

void ChunkProcessorTask::run()
{
	// Start of user code run
    chunk->getVertexBuffer()->getData()->clear();
    
    //double currentTime = glfwGetTime();
    
    unsigned char type = 1;
    unsigned char occlusion = 1;
    int _p = chunk->getP();//Chunk::subsize;
    int _q = chunk->getQ();//Chunk::subsize;
    int _r = chunk->getR();//Chunk::subsize;
    int chp = _p;
    int chq = _q;
    int chr = _r;
    int cup = 0;//_p % 8;
    int cuq = 0;//_q % 8;
    int cur = 0;//_r % 8;
    int pp = 0;//((int)chunk->getP())%Chunk::subsize;
    int qq = 0;//((int)chunk->getQ())%Chunk::subsize;
    int rr = 0;//((int)chunk->getR())%Chunk::subsize;
    int sizeM1 = 255;//size-1;
    unsigned int _offset =  (   pp + (int)(cup << 4) + (chp << 8) +
                             ((qq + (int)(cuq << 4) + (chq << 8)) << 10) +
                             ( (( rr + (int)(cur << 4) + (chr << 8) )) << 20) );
    chunk->getVertexBuffer()->getData()->push_back(_offset);
    unsigned int size = (type << 11) + (occlusion << 9) + (sizeM1);
    chunk->getVertexBuffer()->getData()->push_back(size);
    
    //vector<GLuint>* temp = processor->bufferize(chunk->getOctree());
    //currentTime = glfwGetTime() - currentTime;
    //std::cout << currentTime << std::endl;
    //chunk->getVertexBuffer()->getData()->insert(chunk->getVertexBuffer()->getData()->end(), temp->begin(), temp->end());
    //temp->clear();
    //delete temp;
    chunk->setBuffered(true);
    chunk->setBuffering(false);
    // End of user code
}





Processor* ChunkProcessorTask::getProcessor()
{
	// Start of user code getProcessor
	// End of user code
	return processor;
}

void ChunkProcessorTask::setProcessor(Processor* _processor)
{
	processor = _processor;
}
					
Chunk* ChunkProcessorTask::getChunk()
{
	// Start of user code getChunk
	// End of user code
	return chunk;
}

void ChunkProcessorTask::setChunk(Chunk* _chunk)
{
	chunk = _chunk;
}
					
