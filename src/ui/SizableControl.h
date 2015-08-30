//
//  SizableControl.hpp
//  minequest
//
//  Created by Julien CAILLABET on 29/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#ifndef SizableControl_cpp
#define SizableControl_cpp

#include <stdio.h>

//#include "Control.h"

class SizableControl //: public Control
{
    protected:
        int w;
        int h;
    
    public:
        SizableControl(){};
        int getW(){return w;};
        int getH(){return h;};
        void setW(int w){this->w = w;};
        void setH(int h){this->h = h;};

};

#endif /* SizableControl_cpp */
