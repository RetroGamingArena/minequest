#ifndef __Engine__
#define __Engine__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <vector>


#include "Scene.h"
#include "Shader.h"
#include "Player.h"
#include "Engine.h"

using namespace std;

class Engine
{
	Scene* scene;
	vector<Shader*> shaders;
	Player* player;
	static Engine* instance;
	GLFWwindow* window;
	int windowWidth;
	int windowHeight;

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
		Scene* getScene();
		void setScene(Scene* _scene);
		vector<Shader*> getShaders();
		Player* getPlayer();
		void setPlayer(Player* _player);
		static Engine* getInstance();
};

#endif
