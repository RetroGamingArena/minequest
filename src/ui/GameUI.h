//
//  GameUI.hpp
//  minequest
//
//  Created by Julien CAILLABET on 30/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#ifndef GameUI_cpp
#define GameUI_cpp

#include <stdio.h>

#include "Label.h"
#include "ProgressBar.h"
#include "UI.h"
#include "Cursor.h"

class GameUI : public UI
{
    Label* fPSLabel;
    ProgressBar* progressBar;
    Cursor* cursor;
    
    public:
        GameUI();
        ~GameUI(){};
        ProgressBar* getProgressBar(){return progressBar;};
        Label* getFPSLabel();
        void setFPSLabel(Label* _fPSLabel);
        void render(){UI::render();};
        void refresh();
};

#endif /* GameUI_cpp */
