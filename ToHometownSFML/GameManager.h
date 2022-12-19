#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>

#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "EnemyManager.h"
#include "MechanicManager.h"

class GameManager
{
private:
	//Variable
	sf::RenderWindow* window;
	sf::Event event;
	Player player;
	Level level;
	Enemy enemy;
	EnemyManager enemyManager;
	MechanicManager mechanicManager;
	

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
	void setData();
	void updateData();

};

