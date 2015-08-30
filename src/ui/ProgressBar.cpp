//
//  ProgressBar.cpp
//  minequest
//
//  Created by Julien CAILLABET on 30/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#include "ProgressBar.h"

ProgressBar::ProgressBar(int _x, int _y, int _maxValue)
{
    this->maxValue = _maxValue;
    this->value = 0;
    x = _x;
    y = _y;
    h = 20;
    w = 200;
}

void ProgressBar::render(std::vector<glm::vec2> &vertices, std::vector<glm::vec2> &UVs)
{
    drawRect(vertices, UVs, x,   y,   w, 1);
    drawRect(vertices, UVs, x,   y+h, 1, h);
    drawRect(vertices, UVs, x+w, y+h, 1, h+1);
    drawRect(vertices, UVs, x,   y+h, w, 1);
    
    drawRect(vertices, UVs, x+1, y+h, (w-1)*value/maxValue, h);
}

void ProgressBar::refresh()
{

}

void ProgressBar::mouseMove(double xpos, double ypos)
{

}

void ProgressBar::mouseButton(int button, int action)
{

}