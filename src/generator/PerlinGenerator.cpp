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
    
    int seed = (rand() % INT_MAX)*2+INT_MIN;
    
    module::Billow baseFlatTerrain;
    baseFlatTerrain.SetFrequency (2.0);
    baseFlatTerrain.SetSeed(seed);
    
    module::ScaleBias flatTerrain;
    flatTerrain.SetSourceModule (0, baseFlatTerrain);
    flatTerrain.SetScale (0.5);
    
    module::Const ground;
    ground.SetConstValue(-0.00392156886);//-0.0078125);
    
    module::Billow selector;
    selector.SetSeed(seed);

    module::Select blend;
    blend.SetSourceModule(0, baseFlatTerrain);
    blend.SetSourceModule(1, ground);
    blend.SetControlModule(selector);
    blend.SetBounds(0, 1);
    blend.SetEdgeFalloff (0.125);
    
    utils::NoiseMapBuilderPlane heightMapBuilder;

    heightMapBuilder.SetSourceModule (blend);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.SetDestSize (destSize, destSize);
    
    heightMapBuilder.SetBounds (lowerXBound, upperXBound, lowerYBound, upperYBound);
    //heightMapBuilder.SetBounds (6.0, 10.0, 1.0, 5.0);
    
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
    return  (heightMap.GetValue(x, z)+1)*Chunk::size*Chunk::subsize/2;
    // End of user code
}

bool PerlinGenerator::isCubeUniform(int x, int y, int z, int size)
{
    if( getCubeType(x+size/2,y,z+size/2) == getCubeType(x+size/2,y+size-1,z+size/2) )
       return true;
    return false;
}

bool PerlinGenerator::isCubeFilled(int x, int y, int z, int size)
{
    if(size==1)
        return true;

    float yHeightMap = (y+size-1)*2.0/(Chunk::size*Chunk::subsize-1)-1;
    
    for(int _x = x; _x<x+size; _x++)
        for(int _z = z; _z<z+size; _z++)
        {
            if(heightMap.GetValue(_x, _z)<yHeightMap)
                return false;
        }
    return true;
}

bool PerlinGenerator::isCubeEmpty(int x, int y, int z, int size)
{
    if(size==1)
        return true;
    
    float yHeightMap = (y)*2.0/(Chunk::size*Chunk::subsize-1)-1;
    
    float waterHeightMap = (waterHeight)*2.0/(Chunk::size*Chunk::subsize)-1;
    
    for(int _x = x; _x<x+size; _x++)
        for(int _z = z; _z<z+size; _z++)
        {
            if(heightMap.GetValue(_x, _z) >= yHeightMap || heightMap.GetValue(_x, _z)<waterHeightMap)
            {
                return false;
            }
        }
    return true;
}

unsigned char PerlinGenerator::getCubeType(int x, int y, int z)
{
	// Start of user code getCubeType
    float height = (heightMap.GetValue(x, z)+1)*Chunk::size*Chunk::subsize/2;
    
    if(y<=height)
    {
        if(y < waterHeight-10)
            return 4;
        if(y < 127)
            return 3;
        if(y == 127)
            return 1;
        if(y < 200)
            return 5;
        else
            return 6;
    }
    else if(y>height && y <= waterHeight)
        return 2;
    else
        return 0;
	// End of user code
}

int PerlinGenerator::waterHeight = 117;

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




