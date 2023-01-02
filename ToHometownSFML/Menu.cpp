#include "Menu.h"

Menu::Menu()
{
	createButton();
}

void Menu::mainMenu(sf::RenderWindow *window,bool *isInMenu, int* currentLevel, int* currentMenu)
{

	
	button[0] = new Button(sf::Vector2f(50, 50), sf::Vector2f(400, 150), "Level 1", 100);
	button[1] = new Button(sf::Vector2f(50, 250), sf::Vector2f(400, 150), "Level 2", 100);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::RenderWindow& w = *window;

		sf::Vector2i mousePos = sf::Mouse::getPosition(w);

		/*if (button[0].getGlobalBounds().contains(sf::Vector2f(mousePos)))
		{
			*currentLevel = 0;
			*isInMenu = false;

		}
		else if (button[1].getGlobalBounds().contains(sf::Vector2f(mousePos)))
		{
			*currentLevel = 1;
			*isInMenu = false;
		}*/
	}
}

void Menu::resultMenu(sf::RenderWindow* window, bool* isInMenu, int* currentLevel, int gameState, int remainingLive, sf::Time remainingTime)
{
	
}


void Menu::render(sf::RenderTarget* target)
{
	for (int i = 0; i < 10; i++)
	{
		if (button[i]->isExist)
		{
			button[i]->draw(target);

		}
	}
}


void Menu::createButton()
{
	for (int i = 0; i < 10; i++)
	{
		button[i] = new Button();
	}
}
