//
//  Voxel.h
//  minequest
//
//  Created by Julien CAILLABET on 15/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#ifndef Voxel_h
#define Voxel_h

struct Voxel
{
    unsigned short int x;
    unsigned short int y;
    unsigned short int z;
    unsigned short int size;
    unsigned char occlusion;
    unsigned char type;

    Voxel(){};
    Voxel(int x, int y, int z, int size, unsigned char occlusion, unsigned char type)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->size = size;
        this->occlusion = occlusion;
        this->type = type;
    }
};

#endif /* Voxel_h */
