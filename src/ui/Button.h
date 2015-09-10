//
//  Button.hpp
//  minequest
//
//  Created by Julien CAILLABET on 29/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#ifndef Button_cpp
#define Button_cpp

#include <stdio.h>
#include <vector>

#include "Label.h"
#include "SizableControl.h"
#include "Transmitter.h"
#include "Event.h"

class Button : public Label, public SizableControl, public Transmitter
{
    bool mouseOn;
    Event* clickedEvent;
    
    public:
        Button(char* _caption, int _x, int _y);
        ~Button(){};
        void render(std::vector<glm::vec2> &vertices, std::vector<glm::vec2> &UVs);
        void refresh();
        void mouseMove(double xpos, double ypos);
        void mouseButton(int button, int action);
        void poly(){};
};

#endif /* Button_cpp */
