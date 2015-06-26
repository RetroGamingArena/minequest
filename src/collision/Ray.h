#ifndef __Ray__
#define __Ray__

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



using namespace std;

// Start of user code class import
// End of user code

class Ray
{
	// Start of user code private
	// End of user code
	glm::vec3 start;
	glm::vec3 direction;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		Ray(glm::vec3 _start, glm::vec3 _direction);
		Ray();
		~Ray();
		glm::vec3 getStart();
		void setStart(glm::vec3 _start);
		glm::vec3 getDirection();
		void setDirection(glm::vec3 _direction);
		glm::vec3 move(int i);
		glm::vec3 getNormalizedPoint();
};

#endif
