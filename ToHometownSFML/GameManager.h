#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"


class GameManager
{
private:
	sf::RenderWindow* window;
	sf::Event event;
	Player player;
	

public:
	
	//Function
	void openWindow();
	bool running();
	void initVariable();
	void render();
	void update();
	void pollEvent();

	// Constructor
	GameManager();
	~GameManager();


};

