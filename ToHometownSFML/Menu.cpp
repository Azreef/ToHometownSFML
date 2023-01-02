#include "Menu.h"

Menu::Menu()
{
	createButton();
}

void Menu::mainMenu(sf::RenderWindow *window,bool *isInMenu, int* currentLevel)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::RenderWindow& w = *window;

		sf::Vector2i mousePos = sf::Mouse::getPosition(w);

		if (button[0].getGlobalBounds().contains(sf::Vector2f(mousePos)))
		{
			*currentLevel = 0;
			*isInMenu = false;

		}
		else if (button[1].getGlobalBounds().contains(sf::Vector2f(mousePos)))
		{
			*currentLevel = 1;
			*isInMenu = false;
		}
	}
}


void Menu::render(sf::RenderTarget* target)
{
	target->draw(button[0]);
	target->draw(button[1]);
}


void Menu::createButton()
{
	for (int i = 0; i < 5; i++)
	{
		button[i].setSize(sf::Vector2f(300, 100));
		button[i].setFillColor(sf::Color::White);
	}

	button[0].setPosition(300, 300);
	button[1].setPosition(300, 500);
}
