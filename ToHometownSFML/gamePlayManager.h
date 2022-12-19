#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include <random>
#include "Enemy.h"

#include "Player.h"


#define TOTAL_ENEMY 150

class GamePlayManager
{
private:
	//Variable
	Enemy enemy[TOTAL_ENEMY];
	Level level;
	Player player;
	
	
	sf::Time gameTime = sf::seconds(0);
	sf::Clock gameClock;
	int currentEnemy = 1;
	int enemySpeed;
	int currentDistance;

public:
	//Constructor
	GamePlayManager();

	//Function
	void render(sf::RenderTarget* target);
	void update();
	void setEnemiesData();
	void setPlayerData(sf::Sprite);
	void setCurrentDistance(int distance);
	void setCurrentSpeed(int speed);
	void detectCollision();
	void spawnEnemies();

};

