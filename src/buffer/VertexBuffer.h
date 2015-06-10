#ifndef __VertexBuffer__
#define __VertexBuffer__

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

class VertexBuffer : public Buffer
{
	// Start of user code private
	// End of user code
	vector<GLfloat>* data;
	vector<GLfloat>* base;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		VertexBuffer(vector<GLfloat>* _data, vector<GLfloat>* _base);
		VertexBuffer();
		~VertexBuffer();
		vector<GLfloat>* getData();
		void setData(GLfloat _data);
		vector<GLfloat>* getBase();
		void setBase(GLfloat _base);
		void init();
		void bind();
};

#endif
