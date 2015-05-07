#ifndef __DoubleBuffer__
#define __DoubleBuffer__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>
#include <noise/noise.h>
#include "noiseutils.h"

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
// End of user code


#include "VBO.h"
#include "IndiceBuffer.h"
#include "VertexBuffer.h"

using namespace std;

// Start of user code class import
// End of user code

class DoubleBuffer
{
	VBO* vBO;
	IndiceBuffer* indiceBuffer;
	VertexBuffer* vertexBuffer;

	protected:

	public:
		// Start of user code public
		// End of user code
		DoubleBuffer();
		VBO* getVBO();
		void setVBO(VBO* _vBO);
		IndiceBuffer* getIndiceBuffer();
		void setIndiceBuffer(IndiceBuffer* _indiceBuffer);
		VertexBuffer* getVertexBuffer();
		void setVertexBuffer(VertexBuffer* _vertexBuffer);
};

#endif
