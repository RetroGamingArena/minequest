#include <cstdlib>

#include "DebugUI.h"
// Start of user code includes
#include "Label.h"
#include "Engine.h"
// End of user code


DebugUI::DebugUI()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
           fPSLabel = new Label("Test", 20, 20);
    cubesCountLabel = new Label("Test", 20, 40);
    controls.push_back(fPSLabel);
	controls.push_back(cubesCountLabel);
    // End of user code
}

DebugUI::~DebugUI()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code

void DebugUI::render()
{
	// Start of user code render
    UI::render();
	// End of user code
}
void DebugUI::refresh()
{
	// Start of user code refresh
    char* caption = new char[25];
    sprintf (caption, "Minequest - FPS:  %i t", Engine::getInstance()->getFPS());
    fPSLabel->setCaption(caption);
    
    char* caption2 = new char[25];
    sprintf (caption2, "Cubs count:  %i t", Engine::getInstance()->getWorld()->getCubeCount());
    cubesCountLabel->setCaption(caption2);
	// End of user code
}





