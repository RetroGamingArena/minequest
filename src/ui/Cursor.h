//
//  Cursor.hpp
//  minequest
//
//  Created by Julien CAILLABET on 10/09/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#ifndef Cursor_cpp
#define Cursor_cpp

#include <stdio.h>
#include <vector>

#include "Control.h"
#include "SizableControl.h"

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

class Cursor : public Control, public SizableControl
{
    public:
        Cursor(int x, int y);
        Cursor(){};
        ~Cursor(){};
        void render(std::vector<glm::vec2> &vertices, std::vector<glm::vec2> &UVs);
        void refresh(){};
        void mouseMove(double xpos, double ypos) {};
        void mouseButton(int button, int action){};
};

#endif /* Cursor_cpp */
