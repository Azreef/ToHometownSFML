#include "GameManager.h"
#include <iostream>

//CONSTRUCTOR

GameManager::GameManager()
{
    this->initVariable();
    this->openWindow();
}

GameManager::~GameManager()
{
    delete this->window;
}

//FUNCTION 

//Update ==============================================================================

void GameManager::update()
{
    this->pollEvent();
    this->updateData();
    this->player.update();
    this->level.update();
    this->enemyManager.update();
    this->mechanicManager.update();

}

void GameManager::pollEvent()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->event.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;

        }
    }
}

bool GameManager::running()
{
    return this->window->isOpen();
}

//Draw   ==============================================================================

void GameManager::render()
{
    this->window->clear();
    this->level.render(this->window);
    this->enemyManager.render(this->window);
    this->player.render(this->window);


    this->window->display();

}

//Setter ==============================================================================
void GameManager::openWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1280, 1080), "To Hometown");
    this->window->setFramerateLimit(60);
}

void GameManager::initVariable()
{
    this->window = nullptr;
}

void GameManager::setData()
{
    enemyManager.setEnemiesData();
}

void GameManager::updateData()
{
    enemyManager.setPlayerData(player.getPlayerData());
    enemyManager.setCurrentDistance(level.getCurrentDistance());
    enemyManager.setCurrentSpeed(level.getRoadSpeed());
    mechanicManager.setCurrentDistance(level.getCurrentDistance());

}
