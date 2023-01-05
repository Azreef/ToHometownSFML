#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>

//include "LevelManager.h"
#include "SystemManager.h";
#include "Menu.h"
class GameManager
{
private:
	//Variable
	sf::RenderWindow* window;
	sf::Event event;
	//LevelManager levelManager;

	Menu menu;
	bool levelIsSet;


	//Menu variable
	int currentLevel;
	int currentMenu;
	bool isInmenu;
	bool menuIsSet;


	//gameplay Variable
	int remainingLive;
	sf::Time remainingTime;
	int gameState;

	SystemManager* systemManager;

	
public:
	// Constructor
	GameManager();
	~GameManager();


	//Function
	void openWindow();
	bool running();
	void initVariable();
	void render();
	void update();
	void pollEvent();

};

