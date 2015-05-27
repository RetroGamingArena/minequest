#include <cstdlib>

#include "PerlinGenerator.h"
// Start of user code includes
#include "World.h"
#include "Chunk.h"
// End of user code

PerlinGenerator::PerlinGenerator(utils::NoiseMap _heightMap, int _waterHeight)
{
	heightMap = _heightMap;
	waterHeight = _waterHeight;
}

PerlinGenerator::PerlinGenerator()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    float lowerXBound;
    float upperXBound;
    float lowerYBound;
    float upperYBound;
    
    int destSize;
    
    lowerXBound = 0.0;
    upperXBound = 0.8*(World::size+1);
    
    lowerYBound = 0.0;
    upperYBound = 0.8*(World::size+1);
    
    destSize = Chunk::size*Chunk::subsize*(World::size*2+1);
    
    module::Perlin module;
    utils::NoiseMapBuilderPlane heightMapBuilder;
    
    //module.SetSeed(rand() % 10000);
    heightMapBuilder.SetSourceModule (module);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.SetDestSize (destSize, destSize);
    heightMapBuilder.SetBounds (lowerXBound, upperXBound, lowerYBound, upperYBound);
    heightMapBuilder.Build ();
	// End of user code
}

PerlinGenerator::~PerlinGenerator()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code

float PerlinGenerator::getY(float x, float z)
{
	// Start of user code getY
    float height = heightMap.GetValue(x, z);
    
    if(height < -1)
        height = -1;
    if(height >= 1)
        height = 0.99999;
    height=(height+1);
	
    unsigned char type;
    if(height<16*Chunk::size*Chunk::subsize/32)
        type = 2; //dirt
    else if(height<18*Chunk::size*Chunk::subsize/32)
        type = 3; //sand
    else if(height<20*Chunk::size*Chunk::subsize/32)
        type = 1; //grass
    else if(height<25*Chunk::size*Chunk::subsize/32)
        type = 4; //dirt
    else if(height<28*Chunk::size*Chunk::subsize/32)
        type = 5; //rock
    else
        type = 6; //snow
    return type;
    // End of user code
}
unsigned char PerlinGenerator::getCubeType(int x, int y, int z)
{
	// Start of user code getCubeType
    int absBound = World::size*Chunk::size*Chunk::subsize;//(destSize/(Chunk::size*Chunk::subsize))/2;
    
    float height = heightMap.GetValue(absBound+x, absBound+z);

    height=(height+1);
    
    height*=Chunk::size*Chunk::subsize/2;
    
    if(y<height && y >= waterHeight+40)
        return 6;
    if(y<height && y >= waterHeight+10)
        return 5;
    if(y<height && y >= waterHeight+2)
        return 1;
    if(y<height && y >= waterHeight+1)
        return 3;
    if(y>height && y <= waterHeight)
        return 2;
    if(height<y)
        return 0;
    
    return 4;
    
    //unsigned char type;
    
    /*if(y<16*Chunk::size*Chunk::subsize/32)
        type = 2; //dirt
    else if(y<18*Chunk::size*Chunk::subsize/32)
        type = 3; //sand
    else if(y<20*Chunk::size*Chunk::subsize/32)
        type = 1; //grass
    else if(y<25*Chunk::size*Chunk::subsize/32)
        type = 4; //dirt
    else if(y<28*Chunk::size*Chunk::subsize/32)
        type = 5; //rock
    else
        type = 6; //snow*/
    
    //return type;
	// End of user code
}


int PerlinGenerator::waterHeight = 10;	

utils::NoiseMap PerlinGenerator::getHeightMap()
{
	// Start of user code getHeightMap
	// End of user code
	return heightMap;
}

void PerlinGenerator::setHeightMap(utils::NoiseMap _heightMap)
{
	heightMap = _heightMap;
}

int PerlinGenerator::getWaterHeight()
{
	// Start of user code getWaterHeight
	// End of user code
	return waterHeight;
}




