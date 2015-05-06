#ifndef __DoubleBuffer__
#define __DoubleBuffer__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
// End of user code


#include "VertexBuffer.h"
#include "IndiceBuffer.h"
#include "VBO.h"

using namespace std;

class DoubleBuffer
{
	VertexBuffer* vertexBuffer;
	IndiceBuffer* indiceBuffer;
	VBO* vBO;

	protected:

	public:
		// Start of user code public
		// End of user code
		DoubleBuffer();
		VertexBuffer* getVertexBuffer();
		void setVertexBuffer(VertexBuffer* _vertexBuffer);
		IndiceBuffer* getIndiceBuffer();
		void setIndiceBuffer(IndiceBuffer* _indiceBuffer);
		VBO* getVBO();
		void setVBO(VBO* _vBO);
};

#endif
