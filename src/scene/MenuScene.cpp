//
//  MenuScene.cpp
//  minequest
//
//  Created by Julien CAILLABET on 29/08/2015.
//  Copyright © 2015 RGA. All rights reserved.
//

#include "MenuScene.h"
#include "LoadingScene.h"
#include "Engine.h"
#include "MainUI.h"

MenuScene::MenuScene()
{
    background = new Background();
    this->uI = new MainUI();
    this->uI->addListener(this);
};

void MenuScene::onMouseMotion(double xpos, double ypos)
{
    if(this->uI != NULL)
        this->uI->onMouseMotion(xpos, ypos);
}

void MenuScene::onMouseButton(int button, int action)
{
    if(this->uI != NULL)
        this->uI->onMouseButton(button, action);
}

void MenuScene::onMouseScroll(double xoffset, double yoffset)
{

}
void MenuScene::onKey(int key, int scancode, int action, int mods)
{

}

void MenuScene::handle(Event * event)
{
    if(event->getID() == Event::ID_CLICKED)
    {
        LoadingScene* loadingScene = new LoadingScene();
        loadingScene->init();
        
        Engine* engine = Engine::getInstance();
        engine->setScene(loadingScene);
    }
}

void MenuScene::init()
{
    // Start of user code init
    // End of user code
}
void MenuScene::render()
{
    // Start of user code render
    Engine* engine = Engine::getInstance();
    Shader* shader = engine->getShaders()[0];

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if(background != NULL)
        background->render();
    
    if(uI != NULL)
        uI->render();
}