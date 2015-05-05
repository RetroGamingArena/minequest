#ifndef __Label__
#define __Label__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

#include "Control.h"


using namespace std;

class Label : public Control
{
	char* caption;

	protected:

	public:
		// Start of user code public
        Label(char* _caption, int x, int y);
		// End of user code
		Label(char* _caption);
		Label();
		char* getCaption();
		void setCaption(char* _caption);
};

#endif
