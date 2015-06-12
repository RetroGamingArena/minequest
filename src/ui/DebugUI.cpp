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
    cubesCountLabel = new Label("Test", 20, 70);
    instanceCountLabel = new Label("Test", 20, 120);
    occludedCountLabel = new Label("Test", 20, 170);
    controls.push_back(fPSLabel);
	controls.push_back(cubesCountLabel);
    controls.push_back(instanceCountLabel);
    controls.push_back(occludedCountLabel);
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
    sprintf (caption2, "Cubes count:  %i t", Engine::getInstance()->getWorld()->getCubeCount());
    cubesCountLabel->setCaption(caption2);
	
    char* caption3 = new char[25];
    sprintf (caption3, "Instances count:  %i t", Engine::getInstance()->getWorld()->getInstanceCount());
    instanceCountLabel->setCaption(caption3);
    
    char* caption4 = new char[25];
    sprintf (caption4, "Occluded count:  %i t", Engine::getInstance()->getWorld()->getOccludedCount());
    occludedCountLabel->setCaption(caption4);
    // End of user code
}





Label* DebugUI::getCubesCountLabel()
{
	// Start of user code getCubesCountLabel
	// End of user code
	return cubesCountLabel;
}

void DebugUI::setCubesCountLabel(Label* _cubesCountLabel)
{
	cubesCountLabel = _cubesCountLabel;
}
					
Label* DebugUI::getFPSLabel()
{
	// Start of user code getFPSLabel
	// End of user code
	return fPSLabel;
}

void DebugUI::setFPSLabel(Label* _fPSLabel)
{
	fPSLabel = _fPSLabel;
}
					
Label* DebugUI::getOccludedCountLabel()
{
	// Start of user code getOccludedCountLabel
	// End of user code
	return occludedCountLabel;
}

void DebugUI::setOccludedCountLabel(Label* _occludedCountLabel)
{
	occludedCountLabel = _occludedCountLabel;
}
					
Label* DebugUI::getInstanceCountLabel()
{
	// Start of user code getInstanceCountLabel
	// End of user code
	return instanceCountLabel;
}

void DebugUI::setInstanceCountLabel(Label* _instanceCountLabel)
{
	instanceCountLabel = _instanceCountLabel;
}
					
