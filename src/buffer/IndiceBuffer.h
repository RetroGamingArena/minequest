#ifndef __IndiceBuffer__
#define __IndiceBuffer__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

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
