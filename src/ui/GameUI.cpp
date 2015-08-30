//
//  GameUI.cpp
//  minequest
//
//  Created by Julien CAILLABET on 30/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#include "Engine.h"
#include "GameUI.h"

GameUI::GameUI()
{
    fPSLabel = new Label("Test", 20, 20);
    controls.push_back(fPSLabel);
    progressBar = new ProgressBar(100,100, 17);
    controls.push_back(progressBar);
}

Label* GameUI::getFPSLabel()
{
    return fPSLabel;
}

void GameUI::setFPSLabel(Label* _fPSLabel)
{
    fPSLabel = _fPSLabel;
}

void GameUI::refresh()
{
    char* caption = new char[25];
    sprintf (caption, "Minequest - FPS: %i", Engine::getInstance()->getFPS());
    fPSLabel->setCaption(caption);
}