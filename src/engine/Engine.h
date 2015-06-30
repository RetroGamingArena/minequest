#ifndef __Engine__
#define __Engine__

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


#include "Engine.h"
#include "Scene.h"
#include "Player.h"
#include "Shader.h"
#include "World.h"

using namespace std;

// Start of user code class import
// End of user code

class Engine
{
	// Start of user code private
	// End of user code
	static Engine* instance;
	Scene* scene;
	Player* player;
	vector<Shader*> shaders;
	World* world;
	GLFWwindow* window;
	int windowWidth;
	int windowHeight;
	float oldTime;
	float currentTime;
	int FPS;

	protected:
	// Start of user code protected
	// End of user code

	public:
		// Start of user code public
		// End of user code
		Engine(GLFWwindow* _window, int _windowWidth, int _windowHeight, float _oldTime, float _currentTime, int _FPS);
		Engine();
		~Engine();
		GLFWwindow* getWindow();
		void setWindow(GLFWwindow* _window);
		int getWindowWidth();
		void setWindowWidth(int _windowWidth);
		int getWindowHeight();
		void setWindowHeight(int _windowHeight);
		float getOldTime();
		void setOldTime(float _oldTime);
		float getCurrentTime();
		void setCurrentTime(float _currentTime);
		int getFPS();
		void setFPS(int _FPS);
		int run();
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
		static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
		static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
		void init();
		float getDt();
		void refresh();
		static Engine* getInstance();
		Scene* getScene();
		void setScene(Scene* _scene);
		Player* getPlayer();
		void setPlayer(Player* _player);
		vector<Shader*> getShaders();
		void setShadersAt(Shader* _shaders, int indice);
		World* getWorld();
		void setWorld(World* _world);
};

#endif
