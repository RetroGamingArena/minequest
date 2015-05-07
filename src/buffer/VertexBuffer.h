#ifndef __VertexBuffer__
#define __VertexBuffer__

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

// Start of user code class import
// End of user code

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
