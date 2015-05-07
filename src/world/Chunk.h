#ifndef __Chunk__
#define __Chunk__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
// End of user code



using namespace std;

// Start of user code class import
// End of user code

class Chunk
{
	float p;
	float q;
	float r;

	protected:

	public:
		// Start of user code public
		// End of user code
		Chunk(float _p, float _q, float _r);
		Chunk();
		float getP();
		void setP(float _p);
		float getQ();
		void setQ(float _q);
		float getR();
		void setR(float _r);
};

#endif
