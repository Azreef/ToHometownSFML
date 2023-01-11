#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include <random>
#include "Entity.h"

#include "Player.h"

#include <algorithm>
#include "ResourceManager.h"
#include <SFML/Audio.hpp>

#define TOTAL_ENEMY 50

class GamePlayManager
{
private:
	//Variable
	//Entity enemy[TOTAL_ENEMY];

	std::vector<std::shared_ptr<Entity>> enemy;

	//std::shared_ptr<Entity> enemy[TOTAL_ENEMY];
	Entity repairPickup;
	Entity fuelPickup;
	Level level;
	Player player;
	ResourceManager resourceManager;
	
	sf::Time gameTime = sf::seconds(0);
	sf::Clock gameClock;
	float enemySpeed;
	float currentDistance;
	int enemyInterval;
	bool powerUpSpawned = false;
	int spawnPickupRate;
	int spawnEnemyType; //0 = cars only   1 = cars and truck
	int levelType;

	std::shared_ptr<sf::Texture> carTexture = resourceManager.getTexture("Asset/car2.png");
	std::shared_ptr<sf::Texture> busTexture = resourceManager.getTexture("Asset/bus.png");
	std::shared_ptr<sf::Texture> repairTexture = resourceManager.getTexture("Asset/repairKit.png");
	std::shared_ptr<sf::Texture> fuelTexture = resourceManager.getTexture("Asset/fuel.png");
	
	sf::Sound hitSound;


public:
	//Constructor
	GamePlayManager();
	GamePlayManager(float enemyInterval, int spawnPickupRate,int spawnEnemyType,int levelType);
	~GamePlayManager();

	//Function
	void render(sf::RenderTarget* target);
	void update();
	void spawnPickup();
	void setPlayerData(sf::Sprite);
	void setCurrentDistance(int distance);
	void setCurrentSpeed(int speed);
	int detectCollision();
	void spawnEntity();
	void initVariable();
	void pickupFixPos();
	void spawnEnemy();
	void setEnemies();
	void setSoundFX();

};

