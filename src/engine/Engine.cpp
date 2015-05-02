#include <cstdlib>

#include "Engine.h"

Engine::Engine()
{
	// Start of user code constructor
    windowWidth = 1024;
    windowHeight = 768;
    if (!glfwInit())
        exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWmonitor *monitor = NULL;
    window = glfwCreateWindow(windowWidth, windowHeight, "Minequest", monitor, NULL);
	// End of user code
}

Engine* Engine::instance = NULL;

GLFWwindow* Engine::getWindow()
{
	return window;
}

void Engine::setWindow(GLFWwindow* _window)
{
	window = _window;
}
int Engine::getWindowWidth()
{
	return windowWidth;
}

void Engine::setWindowWidth(int _windowWidth)
{
	windowWidth = _windowWidth;
}
int Engine::getWindowHeight()
{
	return windowHeight;
}

void Engine::setWindowHeight(int _windowHeight)
{
	windowHeight = _windowHeight;
}

int Engine::run()
{
	// Start of user code run
    //window open
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    while (glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 )
    {
        /*scene->getCamera()->look();
        scene->render();*/
        
        //FPS
        /*nbFrames++;
        double currentTime = glfwGetTime();
        double dt = currentTime - lastTime;
        live(dt);
        if ( dt >= (1.0 / 60) )
        {
            FPS = nbFrames;
            Label* label = (Label*)scene->getUI()->getControls()[0];
            char caption [25];
            if(dynamic_cast<DebugUI*>(scene->getUI()) != 0)
            {
                sprintf (caption, "Minequest - FPS:  %i t", nbFrames);
                label->setCaption(caption);
            }
            nbFrames = 0;
            lastTime += 1.0;
        }*/
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    
    glfwTerminate();
    exit(EXIT_SUCCESS);
    
    return 0;
	// End of user code
}

Engine* Engine::getInstance()
{
	// Start of user code getInstance
    if(instance == NULL)
        instance = new Engine();
	// End of user code
	return instance;
}

Scene* Engine::getScene()
{
	// Start of user code getScene
	// End of user code
	return scene;
}

void Engine::setScene(Scene* _scene)
{
	scene = _scene;
}
					
