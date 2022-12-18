#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>

#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "EnemyManager.h"

class GameManager
{
private:
	sf::RenderWindow* window;
	sf::Event event;
	Player player;
	Level level;
	Enemy enemy;
	EnemyManager enemyManager;
	
	

public:
	int currentDistance;

	//Function
	void openWindow();
	bool running();
	void initVariable();
	void render();
	void update();
	void pollEvent();
	void setData();
	void updateData();


	// Constructor
	GameManager();
	~GameManager();


};

