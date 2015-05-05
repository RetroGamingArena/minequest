#include <cstdlib>

#include "Label.h"
// Start of user code includes
// End of user code

Label::Label(char* _caption)
{
	caption = _caption;
}

Label::Label()
{
	// Start of user code constructor
	// End of user code
}

// Start of user code methods
Label::Label(char* _caption, int _x, int _y)
{
    Label(caption);
    x = _x;
    y = _y;
}
// End of user code



char* Label::getCaption()
{
	return caption;
}

void Label::setCaption(char* _caption)
{
	caption = _caption;
}


