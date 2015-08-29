//
//  GenerationResult.h
//  minequest
//
//  Created by Julien CAILLABET on 21/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#include "Voxel.h"

#ifndef GenerationResult_h
#define GenerationResult_h

struct GenerationResult
{
    OctreeEntry<Voxel*>* octreeEntry;
    unsigned char type;
    unsigned char occlusion;
    
    bool equals(GenerationResult generationResult)
    {
        return generationResult.type == type && generationResult.occlusion == occlusion && octreeEntry == NULL && generationResult.octreeEntry == NULL;
    }
};

#endif /* GenerationResult_h */
