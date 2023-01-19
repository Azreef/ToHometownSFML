#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <iostream>
#include <random>
#include <algorithm>

#include "Entity.h"
#include "Player.h"
#include "ResourceManager.h"



class GamePlayManager
{
private:
	//Variable
	
	std::vector<std::shared_ptr<Entity>> enemy;

	Entity repairPickup;
	Entity fuelPickup;
	Level level;
	Player player;
	ResourceManager resourceManager;
	sf::Sprite explosion;
	
	sf::Time gameTime = sf::seconds(0);
	sf::Clock gameClock;
	float enemySpeed;
	float currentDistance;
	int enemyInterval;
	bool powerUpSpawned = false;
	int spawnPickupRate;
	int spawnEnemyType; //0 = cars only   1 = cars and truck
	int levelType;
	int levelMin;

	std::shared_ptr<sf::Texture> carTexture[5];
	std::shared_ptr<sf::Texture> busTexture[5];
	std::shared_ptr<sf::Texture> repairTexture;
	std::shared_ptr<sf::Texture> fuelTexture;


	std::shared_ptr<sf::Texture> explosionTexture = resourceManager.getTexture("Asset/explosion.png");
	sf::Time explosionTimer;
	sf::Clock explosionClock;



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
	void setCurrentDistance(float distance);
	void setCurrentSpeed(float speed);
	int detectCollision();
	void spawnEntity();
	void initVariable();
	void pickupFixPos();
	void enemyFixPos();
	void spawnEnemy();
	void setEnemies();
	void setTexture();

};

