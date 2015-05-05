#ifndef __VertexBuffer__
#define __VertexBuffer__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "Buffer.h"


using namespace std;

class VertexBuffer : public Buffer
{
	vector<GLfloat> data;

	protected:

	public:
		// Start of user code public
		// End of user code
		VertexBuffer(vector<GLfloat> _data);
		VertexBuffer();
		vector<GLfloat> getData();
		void setData(GLfloat _data);
};

#endif
