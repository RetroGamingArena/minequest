#ifndef __DoubleBuffer__
#define __DoubleBuffer__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>


#include "VertexBuffer.h"
#include "IndiceBuffer.h"

using namespace std;

class DoubleBuffer
{
	VertexBuffer* vertexBuffer;
	IndiceBuffer* indiceBuffer;

	protected:

	public:
		// Start of user code public
		// End of user code
		DoubleBuffer();
		VertexBuffer* getVertexBuffer();
		void setVertexBuffer(VertexBuffer* _vertexBuffer);
		IndiceBuffer* getIndiceBuffer();
		void setIndiceBuffer(IndiceBuffer* _indiceBuffer);
};

#endif
