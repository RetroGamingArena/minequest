//
//  GenerationResult.h
//  minequest
//
//  Created by Julien CAILLABET on 21/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#ifndef GenerationResult_h
#define GenerationResult_h

struct GenerationResult
{
    OctreeEntry* octreeEntry;
    unsigned char type;
    unsigned char occlusion;
    
    bool equals(GenerationResult generationResult)
    {
        return generationResult.type == type && generationResult.occlusion == occlusion && octreeEntry == NULL && generationResult.octreeEntry == NULL;
    }
};

#endif /* GenerationResult_h */
