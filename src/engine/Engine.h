#ifndef __Engine__
#define __Engine__

#include <GLFW/glfw3.h>

#include "Engine.h"
#include "Scene.h"

class Engine
{
	static Engine* instance;
	Scene* scene;
	GLFWwindow* window;
	int windowWidth;
	int windowHeight;

	public:
		Engine();
		GLFWwindow* getWindow();
		void setWindow(GLFWwindow* _window);
		int getWindowWidth();
		void setWindowWidth(int _windowWidth);
		int getWindowHeight();
		void setWindowHeight(int _windowHeight);
		int run();
		static Engine* getInstance();
		Scene* getScene();
		void setScene(Scene* _scene);
};

#endif
