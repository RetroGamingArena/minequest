#include <cstdlib>

#include "Transmitter.h"
// Start of user code includes
// End of user code


Transmitter::Transmitter()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

Transmitter::~Transmitter()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code





void Transmitter::fireEvent(Event * event)
{
	// Start of user code fireEvent
    for(int i=0; i<listeners.size(); i++)
    {
        listeners[i]->handle(event);
    }
	// End of user code
}
void Transmitter::addListener(Listener * listener)
{
	// Start of user code addListener
    listeners.push_back(listener);
	// End of user code
}

vector<Event*> Transmitter::getEvents()
{
	// Start of user code getEvents
	// End of user code
	return events;
}

void Transmitter::setEventsAt(Event* _events, int indice)
{
	events[indice] = _events;
}

vector<Listener*> Transmitter::getListeners()
{
	// Start of user code getListeners
	// End of user code
	return listeners;
}

void Transmitter::setListenersAt(Listener* _listeners, int indice)
{
	listeners[indice] = _listeners;
}

