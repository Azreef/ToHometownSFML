#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include <random>
#include "Enemy.h"
#include "Level.h";
#include "Player.h";

#define TOTAL_ENEMY 15

class EnemyManager
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
	EnemyManager();

	//Function
	void render(sf::RenderTarget* target);
	void update();
	void setEnemiesData();
	void setPlayerData(sf::Sprite);
	void detectCollision();



};

