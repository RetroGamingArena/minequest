//
//  ProgressBar.hpp
//  minequest
//
//  Created by Julien CAILLABET on 30/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#ifndef ProgressBar_cpp
#define ProgressBar_cpp

#include <stdio.h>

#include "Control.h"
#include "SizableControl.h"

class ProgressBar : public Control, public SizableControl
{
    int maxValue;
    int value;
    
    public:
        ProgressBar(int _x, int _y, int _maxValue);
        ~ProgressBar(){};
        void render(std::vector<glm::vec2> &vertices, std::vector<glm::vec2> &UVs);
        void refresh();
        int getValue(){return value;};
        void setValue(int value){this->value = value;};
        void mouseMove(double xpos, double ypos);
        void mouseButton(int button, int action);
};

#endif /* ProgressBar_cpp */
