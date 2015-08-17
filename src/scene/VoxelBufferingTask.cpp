//
//  VoxelBufferingTask.cpp
//  minequest
//
//  Created by Julien CAILLABET on 16/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#include "VoxelBufferingTask.h"

void VoxelBufferingTask::run()
{
    gameScene->getWorldProcessor()->bufferizeVoxels();
}