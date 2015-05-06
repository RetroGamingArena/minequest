#ifndef __Engine__
#define __Engine__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <thread>
#include <mutex>

#include "../depends/glm/glm.hpp"
#include "../depends/glm/gtc/matrix_transform.hpp"

// Start of user code includes
// End of user code


#include "Engine.h"
#include "WorldProcessor.h"
#include "Shader.h"
#include "Player.h"
#include "World.h"
#include "Scene.h"

using namespace std;

class Engine
{
	static Engine* instance;
	WorldProcessor* worldProcessor;
	vector<Shader*> shaders;
	Player* player;
	World* world;
	Scene* scene;
	GLFWwindow* window;
	int windowWidth;
	int windowHeight;

	protected:

	public:
		// Start of user code public
		// End of user code
		Engine(GLFWwindow* _window, int _windowWidth, int _windowHeight);
		Engine();
		GLFWwindow* getWindow();
		void setWindow(GLFWwindow* _window);
		int getWindowWidth();
		void setWindowWidth(int _windowWidth);
		int getWindowHeight();
		void setWindowHeight(int _windowHeight);
		int run();
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
		static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
		static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
		void init();
		static Engine* getInstance();
		WorldProcessor* getWorldProcessor();
		void setWorldProcessor(WorldProcessor* _worldProcessor);
		vector<Shader*> getShaders();
		Player* getPlayer();
		void setPlayer(Player* _player);
		World* getWorld();
		void setWorld(World* _world);
		Scene* getScene();
		void setScene(Scene* _scene);
};

#endif
