#include "GameManager.h"
#include <iostream>

//CONSTRUCTOR

GameManager::GameManager()
{
    initVariable();
    openWindow();
}

GameManager::~GameManager()
{
    delete window;
}

//FUNCTION 

//Update ==============================================================================

void GameManager::update()
{
    system.update();
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

    system.render(window);

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


