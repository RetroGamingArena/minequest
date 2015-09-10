//
//  Cursor.cpp
//  minequest
//
//  Created by Julien CAILLABET on 10/09/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#include "Cursor.h"

Cursor::Cursor(int x, int y) :  Control(x, y)
{
    w = 10;
    h = 10;
}

void Cursor::render(std::vector<glm::vec2> &vertices, std::vector<glm::vec2> &UVs)
{
    // Start of user code render
    drawRect(vertices, UVs, x+w/2,   y,   1, h+1);
    drawRect(vertices, UVs, x,   y-h/2, w+1, 1);
    // End of user code
}