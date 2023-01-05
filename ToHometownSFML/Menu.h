#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include "Button.h"
#include <string>

class Menu
{
private:
	int selectLevel;
	Button button[10];
	sf:: Text text[10];
	sf::Font font;
	bool hasClicked;
	sf::Time clickTimer;
	sf::Clock clock;
	bool timerStarted;

public:
	Menu();
	void setText(int id, sf::Vector2f position, int size, sf::String content);
	void mainMenu(sf::RenderWindow *window,bool *isInMenu, int *currentLevel,int *currentMenu);
	void selectMenu(sf::RenderWindow* window, bool* isInMenu, int* currentLevel, int* currentMenu);
	void stageMenu(sf::RenderWindow* window, bool* isInMenu, int* currentLevel);
	void resultMenu(sf::RenderWindow* window, bool* isInMenu, int* currentLevel, int* currentMenu, int gameState, int remainingLive, sf::Time remainingTime,int remainingDistance, int* completedLevel);
	void render(sf::RenderTarget* target);
	void stopDoubleClick();

	void refreshButton();
	void refreshText();


};

