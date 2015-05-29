#ifndef __Event__
#define __Event__

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



using namespace std;

// Start of user code class import
// End of user code

class Event
{
	const char * ID;
	void* source;

	protected:

	public:
		// Start of user code public
        Event(const char * _ID, void* _source);
		// End of user code
	static const char * ID_CHANGED;
		Event(const char * _ID, void* _source, const char * _ID_CHANGED);
		Event();
		~Event();
		const char * getID();
		void setID(const char * _ID);
		void* getSource();
		void setSource(void* _source);
};

#endif
