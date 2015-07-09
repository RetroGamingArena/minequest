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
#include "Label.h"
#include "Label.h"

using namespace std;

// Start of user code class import
// End of user code

class DebugUI : public UI
{
	// Start of user code private
	// End of user code
	Label* cubesCountLabel;
	Label* occludedCountLabel;
	Label* instanceCountLabel;
	Label* fPSLabel;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		DebugUI();
		~DebugUI();
		Label* getCubesCountLabel();
		void setCubesCountLabel(Label* _cubesCountLabel);
		Label* getOccludedCountLabel();
		void setOccludedCountLabel(Label* _occludedCountLabel);
		Label* getInstanceCountLabel();
		void setInstanceCountLabel(Label* _instanceCountLabel);
		Label* getFPSLabel();
		void setFPSLabel(Label* _fPSLabel);
		void render();
		void refresh();
};

#endif
