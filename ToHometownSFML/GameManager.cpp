#include "GameManager.h"
#include <iostream>

//CONSTRUCTOR

GameManager::GameManager()
{
    initVariable();
    openWindow();
    currentLevel = 0;
    completedLevel = 0;
    currentMenu = 0;
    levelIsSet = false;
    isInmenu = true;
   
}   

GameManager::~GameManager()
{
    delete window;
}

//FUNCTION 

//Update ==============================================================================

void GameManager::update()
{
    //Menu

    //Menu UI
    if (isInmenu)
    {
        levelIsSet = false;
        if (!menuIsSet)
        {
            if (currentMenu == 0)
            {
                //Main Menu
                
                //gameState = 0;
                menu.mainMenu(window, &isInmenu, &currentLevel, &currentMenu);
                //menuIsSet = true;
            }
            else if (currentMenu == 1)
            {
                //Select Level
                menu.selectMenu(window, &isInmenu, &currentLevel, &currentMenu,completedLevel);

            }
            else if (currentMenu == 2)
            {
                //Stage Screen
                menu.stageMenu(window, &isInmenu, &currentLevel);
            }
            else if (currentMenu == 3)
            {
                //Result Screen
                menu.resultMenu(window, &isInmenu, &currentLevel, &currentMenu, gameState, remainingLive, remainingTime, remainingDistance, &completedLevel);
            }
            else if (currentMenu == 4)
            {
                //End Screen
            }
        }
    }
    
    //Load Levels
    if (!isInmenu)
    {
        if (!levelIsSet)
        {
          
            std::shared_ptr<SystemManager> systemManager(new SystemManager(currentLevel));
            this->systemManager = systemManager;

            levelIsSet = true;
        }
    }
    

    //Update Levels
    if (!isInmenu)
    {
        systemManager->update();

        //Update Levels Variable
        systemManager->updateGameValue(&gameState, &remainingTime, &remainingLive, &remainingDistance);

        //Gameplay Finished (Stop Gameplay loop)
        if (gameState != 0) 
        {
           currentMenu = 3;
           isInmenu = true;
        }
 
    }

    pollEvent();
    
}

void GameManager::pollEvent()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                window->close();
            break;

        }
    }
}

bool GameManager::running()
{
    return window->isOpen();
}

//Draw   ==============================================================================

void GameManager::render()
{
    window->clear();

    
    if (isInmenu)//Render Menu UI
    {       
        menu.render(window);      
    }
   
    else //Render Gameplay
    {
        systemManager->render(window);
    }

    window->display();
   
}

//Setter ==============================================================================
void GameManager::openWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(1280, 1080), "To Hometown", sf::Style::Close);
    window->setFramerateLimit(60);
}

void GameManager::initVariable()
{
    window = nullptr;
}


