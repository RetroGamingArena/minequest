#ifndef __Transmitter__
#define __Transmitter__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>
#include <noise/noise.h>
#include "noiseutils.h"

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
// End of user code


#include "Listener.h"
#include "Event.h"

using namespace std;

// Start of user code class import
// End of user code

class Transmitter
{

	protected:
	vector<Listener*> listeners;
	vector<Event*> events;

	public:
		// Start of user code public
		// End of user code
		Transmitter();
		virtual ~Transmitter(){};
		void fireEvent(Event * event);
		void addListener(Listener * listener);
		virtual void poly() = 0;
		vector<Listener*> getListeners();
		void setListenersAt(Listener* _listeners, int indice);
		vector<Event*> getEvents();
		void setEventsAt(Event* _events, int indice);
};

#endif
