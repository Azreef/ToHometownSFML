#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>
#include "Button.h"

class Menu
{
private:
	int selectLevel;
	//sf::RectangleShape button[10];
	Button *button[10];

public:
	Menu();

	void mainMenu(sf::RenderWindow *window,bool *isInMenu, int *currentLevel,int *currentMenu );
	void resultMenu(sf::RenderWindow* window, bool* isInMenu, int* currentLevel, int gameState, int remainingLive, sf::Time remainingTime);
	void render(sf::RenderTarget* target);

	void createButton();



};

