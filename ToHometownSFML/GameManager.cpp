#include "GameManager.h"

void GameManager::openWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1280, 1080), "To Hometown");
    this->window->setFramerateLimit(60);
}

bool GameManager::running()
{
    while (this->window->isOpen())
    {
        while (this->window->pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed)
            {
                return false;
            }
        }

    }
}


void GameManager::initVariable()
{
    this->window = nullptr;
}

GameManager::GameManager()
{
    this->initVariable();
    this->openWindow();
}


GameManager::~GameManager()
{
    delete this->window;
}

