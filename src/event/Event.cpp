#include <cstdlib>

#include "Event.h"
// Start of user code includes
// End of user code

Event::Event(const char * _ID, void* _source, const char * _ID_CHANGED, const char * _ID_FINISHED)
{
	ID = _ID;
	source = _source;
	ID_CHANGED = _ID_CHANGED;
	ID_FINISHED = _ID_FINISHED;
}

Event::Event()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

Event::~Event()
{
	// Start of user code destructor
    //delete[] ID;
	// End of user code
}

// Start of user code methods
Event::Event(const char * _ID, void* _source)
{
    ID = _ID;
    source = _source;
}
// End of user code



const char * Event::ID_CHANGED = "CHANGED";	
const char * Event::ID_FINISHED = "FINISHED";	
const char * Event::ID_CLICKED = "CLICKED";

const char * Event::getID()
{
	// Start of user code getID
	// End of user code
	return ID;
}

void Event::setID(const char * _ID)
{
	ID = _ID;
}

void* Event::getSource()
{
	// Start of user code getSource
	// End of user code
	return source;
}

void Event::setSource(void* _source)
{
	source = _source;
}



