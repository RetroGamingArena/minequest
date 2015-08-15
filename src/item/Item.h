#ifndef __Item__
#define __Item__

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
#include "VertexBuffer.h"
// End of user code



using namespace std;

// Start of user code class import
// End of user code

class Item
{
	// Start of user code private
	// End of user code

	protected:
	// Start of user code protected
    bool falling;
	// End of user code
	float x;
	float y;
	float z;
	float lx;
	float ly;
	float lz;
	float dx;
	float dy;
	float dz;
	float weight;

	public:
		// Start of user code public
		// End of user code
	static float g;
		Item(float _x, float _y, float _z, float _lx, float _ly, float _lz, float _dx, float _dy, float _dz, float _weight, float _g);
		Item();
		virtual ~Item(){};
		float getX();
		void setX(float _x);
		float getY();
		void setY(float _y);
		float getZ();
		void setZ(float _z);
		float getLx();
		void setLx(float _lx);
		float getLy();
		void setLy(float _ly);
		float getLz();
		void setLz(float _lz);
		float getDx();
		void setDx(float _dx);
		float getDy();
		void setDy(float _dy);
		float getDz();
		void setDz(float _dz);
		float getWeight();
		void setWeight(float _weight);
		virtual bool live(double dt) = 0;
		virtual void draw(VertexBuffer * buffer) = 0;
		glm::vec3 getPosition();
		glm::vec3 getLook();
		bool tryMove();
};

#endif
