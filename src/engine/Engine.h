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

// Start of user code includes
// End of user code


#include "WorldProcessor.h"
#include "Scene.h"
#include "Shader.h"
#include "Player.h"
#include "Engine.h"
#include "World.h"

using namespace std;

// Start of user code class import
// End of user code

class Engine
{
	WorldProcessor* worldProcessor;
	Scene* scene;
	vector<Shader*> shaders;
	Player* player;
	static Engine* instance;
	World* world;
	GLFWwindow* window;
	int windowWidth;
	int windowHeight;

	protected:

	public:
		// Start of user code public
		// End of user code
		Engine(GLFWwindow* _window, int _windowWidth, int _windowHeight);
		Engine();
		~Engine();
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
		WorldProcessor* getWorldProcessor();
		void setWorldProcessor(WorldProcessor* _worldProcessor);
		Scene* getScene();
		void setScene(Scene* _scene);
		vector<Shader*> getShaders();
		Player* getPlayer();
		void setPlayer(Player* _player);
		static Engine* getInstance();
		World* getWorld();
		void setWorld(World* _world);
};

#endif
