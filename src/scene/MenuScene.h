//
//  MenuScene.hpp
//  minequest
//
//  Created by Julien CAILLABET on 29/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#ifndef MenuScene_cpp
#define MenuScene_cpp

#include <stdio.h>

#include "Scene.h"
#include "Listener.h"

class MenuScene : public Scene, public Listener
{
    public:
    MenuScene();
    ~MenuScene(){};
    void init();
    void render();
    void onMouseButton(int button, int action);
    void onMouseMotion(double xpos, double ypos);
    void onMouseScroll(double xoffset, double yoffset);
    void onKey(int key, int scancode, int action, int mods);
    void handle(Event * event);
    void poly(){};
};

#endif /* MenuScene_cpp */
