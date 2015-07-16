#ifndef __IndiceBuffer__
#define __IndiceBuffer__

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

#include "Buffer.h"


using namespace std;

// Start of user code class import
// End of user code

class IndiceBuffer : public Buffer
{
	// Start of user code private
	// End of user code
	vector<unsigned int>* data;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		IndiceBuffer(vector<unsigned int>* _data);
		IndiceBuffer();
		~IndiceBuffer();
		vector<unsigned int>* getData();
		void setData(unsigned int _data);
		void bind();
};

#endif
