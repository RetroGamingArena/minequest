#include <cstdlib>

#include "PerlinGenerator.h"
// Start of user code includes
#include "World.h"
#include "Chunk.h"
// End of user code

PerlinGenerator::PerlinGenerator(utils::NoiseMap _heightMap)
{
	heightMap = _heightMap;
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
    
    lowerXBound = 2.0;
    upperXBound = 3.0;
    lowerYBound = 1.0;
    upperYBound = 2.5;
    
    destSize = 16*16*3;//224 * 8;
    
    module::Perlin module;
    utils::NoiseMapBuilderPlane heightMapBuilder;
    
    heightMapBuilder.SetSourceModule (module);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.SetDestSize (destSize, destSize);
    heightMapBuilder.SetBounds (lowerXBound, upperXBound, lowerYBound, upperYBound);
    heightMapBuilder.Build ();
	// End of user code
}

// Start of user code methods
// End of user code

float PerlinGenerator::getY(float x, float z)
{
	// Start of user code getY
    int absBound = World::size*Chunk::size*Chunk::subsize;//(destSize/(Chunk::size*Chunk::subsize))/2;
    float height = heightMap.GetValue(x+absBound, z+absBound);
    if(height < -1)
        height = -1;
    if(height >= 1)
        height = 0.99999;
    return (height+1);
	// End of user code
}



utils::NoiseMap PerlinGenerator::getHeightMap()
{
	return heightMap;
}

void PerlinGenerator::setHeightMap(utils::NoiseMap _heightMap)
{
	heightMap = _heightMap;
}


