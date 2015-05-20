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


#include "VertexBuffer.h"
#include "IndiceBuffer.h"
#include "VBO.h"

using namespace std;

// Start of user code class import
// End of user code

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
		~DoubleBuffer();
		void bufferizeIndice(float indice);
		void bufferizeVertex(float x, float y, float z, float type, float ao);
		void bufferizeSquare(float x1, float y1, float z1, float x2, float y2, float z2, float type, float* ao);
		VertexBuffer* getVertexBuffer();
		void setVertexBuffer(VertexBuffer* _vertexBuffer);
		IndiceBuffer* getIndiceBuffer();
		void setIndiceBuffer(IndiceBuffer* _indiceBuffer);
		VBO* getVBO();
		void setVBO(VBO* _vBO);
};

#endif
