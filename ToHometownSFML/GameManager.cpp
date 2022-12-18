#include "GameManager.h"
#include <iostream>


//Function
void GameManager::openWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1280, 1080), "To Hometown");
    this->window->setFramerateLimit(60);
}

bool GameManager::running()
{
    return this->window->isOpen();
}


void GameManager::initVariable()
{
    this->window = nullptr;
}

//Render
void GameManager::render()
{
    this->window->clear();
    this->level.render(this->window);
    this->enemyManager.render(this->window);
    this->player.render(this->window);
   
   
    this->window->display();
    
}

void GameManager::update()
{
    this->pollEvent();
    this->updateData();
    this->player.update();
    this->level.update();
    this->enemyManager.update();
    
   
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

void GameManager::setData()
{
    enemyManager.setEnemiesData();
}

void GameManager::updateData()
{
    enemyManager.setPlayerData(player.getPlayerData());
}


//Constructor
GameManager::GameManager()
{
    this->initVariable();
    this->openWindow();
}

GameManager::~GameManager()
{
    delete this->window;
}

