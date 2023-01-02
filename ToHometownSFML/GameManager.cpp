#include "GameManager.h"
#include <iostream>

//CONSTRUCTOR

GameManager::GameManager()
{
    initVariable();
    openWindow();
    currentLevel = 0;
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
    if (isInmenu)
    {
        if (currentMenu == 0)
        {
            menu.mainMenu(window, &isInmenu, &currentLevel,&currentMenu);
        }


    }
    
    //Load Levels
    if (!isInmenu)
    {
        if (!levelIsSet)
        {
            systemManager = new SystemManager(currentLevel);
            levelIsSet = true;
        }


    }
    
    //Update Levels

    if (!isInmenu)
    {
        systemManager->update();

        systemManager->updateGameValue(&gameState, &remainingTime, &remainingLive);

        std::cout << gameState << std::endl;
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

    //levelManager.render(window);


    if (isInmenu)
    {
        if (currentLevel == 0)
        {
            menu.render(window);
        }
    }
   
    else
    {
        systemManager->render(window);
    }

    window->display();
   
}

//Setter ==============================================================================
void GameManager::openWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(1280, 1080), "To Hometown");
    window->setFramerateLimit(60);
}

void GameManager::initVariable()
{
    window = nullptr;
}


