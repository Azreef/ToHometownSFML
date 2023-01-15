#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>
#include <fstream>
#include <sstream>
#include "ResourceManager.h"

//include "LevelManager.h"
#include "SystemManager.h";
#include "Menu.h"
class GameManager
{
private:
	//Variable
	sf::RenderWindow* window;
	sf::RenderWindow* loadingWindow;
	sf::Event event;

	Menu menu;
	bool levelIsSet;


	//Menu variable
	int currentLevel;
	int completedLevel;
	int currentMenu;
	bool isInmenu;
	bool menuIsSet;


	//gameplay Variable
	int remainingLive;
	sf::Time remainingTime;
	int remainingDistance;
	int gameState;

	int highScore[4];
	int currentScore;
	
	ResourceManager resourceManager;
	std::shared_ptr <SystemManager> systemManager;

	std::shared_ptr<sf::Texture>loadingTexture = resourceManager.getTexture("Asset/UI/loading.png");
	sf::Sprite loadingImage;
	
	
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
	void loadSave();
	void setSave();
	void resetSave();

};

