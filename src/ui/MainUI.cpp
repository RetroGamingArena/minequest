//
//  MainUI.cpp
//  minequest
//
//  Created by Julien CAILLABET on 29/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#include "MainUI.h"

MainUI::MainUI()
// Start of user code super class
// End of user code
{
    // Start of user code constructor
    startButton = new Button("Start", 20, 20);
    controls.push_back(startButton);
    
    startButton->addListener(this);
    // End of user code
}

void MainUI::handle(Event * event)
{
    if(event->getID() == Event::ID_CLICKED)
    {
        fireEvent(event);
    }
}