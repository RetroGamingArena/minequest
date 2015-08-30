//
//  MainUI.hpp
//  minequest
//
//  Created by Julien CAILLABET on 29/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#ifndef MainUI_cpp
#define MainUI_cpp

#include <stdio.h>

#include "UI.h"
#include "Button.h"
#include "Listener.h"

class MainUI : public UI, public Listener
{
    Button* startButton;
    
    public:
        MainUI();
        ~MainUI(){};
        void render(){UI::render();};
        void refresh(){};
        void handle(Event * event);
        void poly(){};
};

#endif /* MainUI_cpp */
