#include <cstdlib>

#include "Engine.h"
// Start of user code includes
#include "LoadingScene.h"
#include "WorldShader.h"
#include "TextShader.h"
#include "BackgroundShader.h"
#include "WorldProcessor.h"
#include "Label.h"
#include "DebugUI.h"
// End of user code

Engine::Engine(GLFWwindow* _window, int _windowWidth, int _windowHeight, float _oldTime, float _currentTime, int _FPS)
{
	window = _window;
	windowWidth = _windowWidth;
	windowHeight = _windowHeight;
	oldTime = _oldTime;
	currentTime = _currentTime;
	FPS = _FPS;
}

Engine::Engine()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

Engine::~Engine()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code


Engine* Engine::instance = NULL;


GLFWwindow* Engine::getWindow()
{
	// Start of user code getWindow
	// End of user code
	return window;
}

void Engine::setWindow(GLFWwindow* _window)
{
	window = _window;
}

int Engine::getWindowWidth()
{
	// Start of user code getWindowWidth
	// End of user code
	return windowWidth;
}

void Engine::setWindowWidth(int _windowWidth)
{
	windowWidth = _windowWidth;
}

int Engine::getWindowHeight()
{
	// Start of user code getWindowHeight
	// End of user code
	return windowHeight;
}

void Engine::setWindowHeight(int _windowHeight)
{
	windowHeight = _windowHeight;
}

float Engine::getOldTime()
{
	// Start of user code getOldTime
	// End of user code
	return oldTime;
}

void Engine::setOldTime(float _oldTime)
{
	oldTime = _oldTime;
}

float Engine::getCurrentTime()
{
	// Start of user code getCurrentTime
	// End of user code
	return currentTime;
}

void Engine::setCurrentTime(float _currentTime)
{
	currentTime = _currentTime;
}

int Engine::getFPS()
{
	// Start of user code getFPS
	// End of user code
	return FPS;
}

void Engine::setFPS(int _FPS)
{
	FPS = _FPS;
}


int Engine::run()
{
	// Start of user code run
    init();
    
    //window open
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    //TODO : field
    int nbFrames = 0;
    double lastTime;
    
    while (glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 )
    {
        if(scene->getSelectedCamera() != NULL)
            scene->getSelectedCamera()->look();
        scene->render();
        
        //FPS
        nbFrames++;
        double currentTime = glfwGetTime();
        double dt = currentTime - lastTime;
        //double FPS;
        //live(dt);
        if ( dt >= (1.0 / 60) )
        {
            FPS = nbFrames;
            
            /*Label* label = (Label*)scene->getUI()->getControls()[0];
            char caption [25];
            if(dynamic_cast<DebugUI*>(scene->getUI()) != 0)
            {
                sprintf (caption, "Minequest - FPS:  %i t", nbFrames);
                label->setCaption(caption);
            }*/
            
            nbFrames = 0;
            lastTime += 1.0;
        }
        
        refresh();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    
    glfwTerminate();
    exit(EXIT_SUCCESS);
    
    return 0;
	// End of user code
}
void Engine::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	// Start of user code mouseButtonCallback
    Engine* engine = getInstance();
    engine->getScene()->getSelectedCamera()->onMouseButton(button, action);
	// End of user code
}
void Engine::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	// Start of user code cursorPositionCallback
    Engine* engine = getInstance();
    engine->getScene()->onMouseMotion(xpos, ypos);
	// End of user code
}
void Engine::scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	// Start of user code scrollCallback
    Engine* engine = getInstance();
    engine->getScene()->onMouseScroll(xoffset, yoffset);
	// End of user code
}
void Engine::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// Start of user code keyCallBack
    Engine* engine = getInstance();
    engine->getScene()->onKey(key, scancode, action, mods);
    // End of user code
}
void Engine::init()
{
	// Start of user code init
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
    
    glfwMakeContextCurrent(window);
    
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);
    glfwSetScrollCallback(window, scrollCallback);
    glfwSetKeyCallback(window, keyCallBack);
    
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
        exit(EXIT_FAILURE);
    if(!GLEW_EXT_geometry_shader4)
    {
        fprintf(stderr, "No support for geometry shaders found\n");
        exit(1);
    }
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glCreateShader(GL_GEOMETRY_SHADER);
    glDepthFunc(GL_LESS);
    
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    //glFrontFace(GL_CW);
    
    shaders.push_back(new WorldShader());
    shaders.push_back(new TextShader());
    shaders.push_back(new BackgroundShader());
    
    //VBOScene::programID = ShaderLoader::load( "shaders/vertexShader.glsl", "shaders/fragmentShader.glsl", NULL);//"shaders/geometryShader.glsl");
    //Scene::matrixID = glGetUniformLocation(VBOScene::programID, "MVP");
    
    /*Scene::mMatrixID = glGetUniformLocation(VBOScene::programID, "M");
     Scene::vMatrixID = glGetUniformLocation(VBOScene::programID, "V");
     Scene::pMatrixID = glGetUniformLocation(VBOScene::programID, "P");*/
    
    player = new Player();
    
    //camera = new TrackBallCamera();
    scene = new LoadingScene();
    //scene = new VoxelScene(window);
    scene->init();
    
    oldTime = glfwGetTime();
	currentTime = glfwGetTime();
    // End of user code
}
float Engine::getDt()
{
	// Start of user code getDt
    return currentTime - oldTime;
	// End of user code
}
void Engine::refresh()
{
	// Start of user code refresh
    oldTime = currentTime;
    currentTime = glfwGetTime();
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

vector<Shader*> Engine::getShaders()
{
	// Start of user code getShaders
	// End of user code
	return shaders;
}

void Engine::setShadersAt(Shader* _shaders, int indice)
{
	shaders[indice] = _shaders;
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
					
World* Engine::getWorld()
{
	// Start of user code getWorld
	// End of user code
	return world;
}

void Engine::setWorld(World* _world)
{
	world = _world;
}
					
Player* Engine::getPlayer()
{
	// Start of user code getPlayer
	// End of user code
	return player;
}

void Engine::setPlayer(Player* _player)
{
	player = _player;
}
					
