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
#include "VBO.h"
#include "IndiceBuffer.h"

using namespace std;

class DoubleBuffer
{
	VertexBuffer* vertexBuffer;
	VBO* vBO;
	IndiceBuffer* indiceBuffer;

	protected:

	public:
		// Start of user code public
		// End of user code
		DoubleBuffer();
		VertexBuffer* getVertexBuffer();
		void setVertexBuffer(VertexBuffer* _vertexBuffer);
		VBO* getVBO();
		void setVBO(VBO* _vBO);
		IndiceBuffer* getIndiceBuffer();
		void setIndiceBuffer(IndiceBuffer* _indiceBuffer);
};

#endif
