#include <cstdlib>

#include "VoxelVBO.h"
// Start of user code includes
// End of user code


VoxelVBO::VoxelVBO()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    attributes.push_back(new Attribute(3,0,"Point"));
    attributes.push_back(new Attribute(1,0,"AO"));
    
    attributes.push_back(new Attribute(1,1,"Point"));
    //attributes.push_back(new Attribute(1,1,"Type"));
    attributes.push_back(new Attribute(1,1,"Size"));
    //attributes.push_back(new Attribute(1,1,"AO"));
	// End of user code
}

VoxelVBO::~VoxelVBO()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code






