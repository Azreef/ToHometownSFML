#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include <random>
#include "Entity.h"

#include "Player.h"


#define TOTAL_ENEMY 150

class GamePlayManager
{
private:
	//Variable
	Entity enemy[TOTAL_ENEMY];
	Entity repairPickup;
	Entity fuelPickup;
	Level level;
	Player player;
	
	
	sf::Time gameTime = sf::seconds(0);
	sf::Clock gameClock;
	int currentEnemy = 1;
	float enemySpeed;
	float currentDistance;
	int enemyInterval;
	bool powerUpSpawned = false;
	int spawnPickupRate;
	int spawnEnemyType; //0 = cars only   1 = cars and truck
	int levelType;


public:
	//Constructor
	GamePlayManager();
	GamePlayManager(float enemyInterval, int spawnPickupRate,int spawnEnemyType,int levelType);

	//Function
	void render(sf::RenderTarget* target);
	void update();
	void setEnemiesData();
	void spawnPickup();
	void setPlayerData(sf::Sprite);
	void setCurrentDistance(int distance);
	void setCurrentSpeed(int speed);
	int detectCollision();
	void spawnEntity();
	void initVariable();
	void pickupFixPos();

};

