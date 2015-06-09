#ifndef __Player__
#define __Player__

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

#include "Item.h"


using namespace std;

// Start of user code class import
// End of user code

class Player : public Item
{
	// Start of user code private
	// End of user code
	bool falling;
	float hRotation;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		Player(bool _falling, float _hRotation);
		Player();
		~Player();
		bool getFalling();
		void setFalling(bool _falling);
		float getHRotation();
		void setHRotation(float _hRotation);
		bool live(double dt);
		void draw(VertexBuffer * buffer);
};

#endif
