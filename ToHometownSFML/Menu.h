#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>

class Menu
{
private:
	int selectLevel;
	sf::RectangleShape button[10];

public:
	Menu();

	void mainMenu(sf::RenderWindow *window,bool *isInMenu, int *currentLevel );
	void render(sf::RenderTarget* target);

	void createButton();


};

