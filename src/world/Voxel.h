//
//  Voxel.h
//  minequest
//
//  Created by Julien CAILLABET on 15/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#ifndef Voxel_h
#define Voxel_h

#include <iostream>

struct Voxel
{
    unsigned short int x;
    unsigned short int y;
    unsigned short int z;
    
    /*double x_16;
    double y_16;
    double z_16;
    
    double x_size_16;
    double y_size_16;
    double z_size_16;*/
    
    double x_size_16_2;
    double y_size_16_2;
    double z_size_16_2;
    
    unsigned short int size;
    unsigned char occlusion;
    unsigned char type;
    
    unsigned char visible;
    bool occluded;

    struct offsetBitFiled
    {
        unsigned int pixelX  : 4;
        unsigned int cubeX   : 4;
        unsigned int chunkX  : 2;

        unsigned int pixelY  : 4;
        unsigned int cubeY   : 4;
        unsigned int chunkY  : 2;

        unsigned int pixelZ  : 4;
        unsigned int cubeZ   : 4;
        unsigned int chunkZ  : 2;
        unsigned int :2;
    };

    union OffsetField
    {
        unsigned int raw;
        offsetBitFiled field;
    };

    struct sizeBitField
    {
        unsigned int sizeX  : 7;
        unsigned int sizeY  : 7;
        unsigned int sizeZ  : 7;
        unsigned int occlusion  : 2;
        unsigned int type  : 9;
    };
    
    union SizeField
    {
        unsigned int raw;
        sizeBitField field;
    };
    
    OffsetField offsetRegister;
    SizeField sizeRegister;

    Voxel(){};
    Voxel(int x, int y, int z, int size, unsigned char occlusion, unsigned char type, unsigned char visible)
    {
        this->offsetRegister.raw = 0;
        this->sizeRegister.raw = 0;
        
        this->x = x;
        this->y = y;
        this->z = z;
        
        /*this->x_16 = this->x/16.0;
        this->y_16 = this->y/16.0;
        this->z_16 = this->z/16.0;*/
        
        this->size = size;
        
        /*this->x_size_16 = (this->x+this->size)/16.0;
        this->y_size_16 = (this->y+this->size)/16.0;
        this->z_size_16 = (this->z+this->size)/16.0;*/
        
        this->x_size_16_2 = (this->x+this->size/2.0)/16;
        this->y_size_16_2 = (this->y+this->size/2.0)/16;
        this->z_size_16_2 = (this->z+this->size/2.0)/16;
        
        this->occlusion = occlusion;
        this->type = type;
        
        this->offsetRegister.field.pixelX = this->x%16;
        this->offsetRegister.field.cubeX  = (this->x/16)%16;
        this->offsetRegister.field.chunkX = (this->x/16)/16;
        
        this->offsetRegister.field.pixelY = this->y%16;
        this->offsetRegister.field.cubeY  = (this->y/16)%16;
        this->offsetRegister.field.chunkY = (this->y/16)/16;
        
        this->offsetRegister.field.pixelZ = this->z%16;
        this->offsetRegister.field.cubeZ  = (this->z/16)%16;
        this->offsetRegister.field.chunkZ = (this->z/16)/16;
        
        sizeRegister.field.sizeX = this->size-1;
        sizeRegister.field.sizeY = this->size-1;
        sizeRegister.field.sizeZ = this->size-1;
        sizeRegister.field.type = this->type;
        sizeRegister.field.occlusion = this->occlusion;

        this->visible = visible;
    }
};

#endif /* Voxel_h */
