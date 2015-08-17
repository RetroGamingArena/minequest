//
//  VoxelBufferingTask.hpp
//  minequest
//
//  Created by Julien CAILLABET on 16/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#ifndef VoxelBufferingTask_cpp
#define VoxelBufferingTask_cpp

#include <stdio.h>

#include "Task.h"
#include "GameScene.h"

class VoxelBufferingTask : public Task
{
    public:
        GameScene* gameScene;
        void run();
};

#endif /* VoxelBufferingTask_cpp */
