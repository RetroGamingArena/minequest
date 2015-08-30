//
//  Button.cpp
//  minequest
//
//  Created by Julien CAILLABET on 29/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#include "Button.h"

Button::Button(char* _caption, int _x, int _y)
{
    this->caption = new char[strlen(_caption)];
    strcpy(this->caption, _caption);
    x = _x;
    y = _y;
    h = 20;
    w = 200;
    mouseOn = false;
    clickedEvent = new Event(Event::ID_CLICKED, this);
}

void Button::mouseMove(double xpos, double ypos)
{
    mouseOn = false;
    if(xpos<x*pixelSize)
        return;
    if(ypos<1080-(y+h)*pixelSize)
        return;
    if(xpos>(x+w)*pixelSize)
        return;
    if(ypos>1080-y*pixelSize)
        return;
    mouseOn = true;
}

void Button::mouseButton(int button, int action)
{
    if(mouseOn)
    {
        fireEvent(clickedEvent);
    }
}

void Button::render(std::vector<glm::vec2> &vertices, std::vector<glm::vec2> &UVs)
{
    // Start of user code render
    drawRect(vertices, UVs, x,   y,   w, 1);
    drawRect(vertices, UVs, x,   y+h, 1, h);
    drawRect(vertices, UVs, x+w, y+h, 1, h+1);
    drawRect(vertices, UVs, x,   y+h, w, 1);
    
    if(mouseOn)
        drawRect(vertices, UVs, x+1, y+h, w-1, h);
    // End of user code
}
void Button::refresh()
{
    // Start of user code refresh
    // End of user code
}