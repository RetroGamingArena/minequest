#include <cstdlib>

#include "LoadingUI.h"
// Start of user code includes
#include "Label.h"
// End of user code


LoadingUI::LoadingUI()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    controls.push_back(new Label("Loading...", 20, 20));
	// End of user code
}

LoadingUI::~LoadingUI()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code

void LoadingUI::render()
{
	// Start of user code render
    UI::render();
	// End of user code
}
void LoadingUI::refresh()
{
	// Start of user code refresh
	// End of user code
}





