#ifndef __DebugUI__
#define __DebugUI__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>
#include <noise/noise.h>
#include "noiseutils.h"

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code defines
// End of user code

// Start of user code includes
// End of user code

#include "UI.h"

#include "Label.h"
#include "Label.h"

using namespace std;

// Start of user code class import
// End of user code

class DebugUI : public UI
{
	// Start of user code private
	// End of user code
	Label* fPSLabel;
	Label* cubesCountLabel;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		DebugUI();
		~DebugUI();
		Label* getFPSLabel();
		void setFPSLabel(Label* _fPSLabel);
		Label* getCubesCountLabel();
		void setCubesCountLabel(Label* _cubesCountLabel);
		void render();
		void refresh();
};

#endif
