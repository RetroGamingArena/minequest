#ifndef __DoubleBuffer__
#define __DoubleBuffer__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"


#include "IndiceBuffer.h"
#include "VBO.h"
#include "VertexBuffer.h"

using namespace std;

class DoubleBuffer
{
	IndiceBuffer* indiceBuffer;
	VBO* vBO;
	VertexBuffer* vertexBuffer;

	protected:

	public:
		// Start of user code public
		// End of user code
		DoubleBuffer();
		IndiceBuffer* getIndiceBuffer();
		void setIndiceBuffer(IndiceBuffer* _indiceBuffer);
		VBO* getVBO();
		void setVBO(VBO* _vBO);
		VertexBuffer* getVertexBuffer();
		void setVertexBuffer(VertexBuffer* _vertexBuffer);
};

#endif
