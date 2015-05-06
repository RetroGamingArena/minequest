#ifndef __IndiceBuffer__
#define __IndiceBuffer__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
// End of user code

#include "Buffer.h"


using namespace std;

class IndiceBuffer : public Buffer
{
	vector<unsigned int> data;

	protected:

	public:
		// Start of user code public
		// End of user code
		IndiceBuffer(vector<unsigned int> _data);
		IndiceBuffer();
		vector<unsigned int> getData();
		void setData(unsigned int _data);
};

#endif
