#include "GamePlayManager.h"
#include <iostream>

//CONSTRUCTOR
GamePlayManager::GamePlayManager()
{
	initVariable();
}

GamePlayManager::GamePlayManager(float enemyInterval, int spawnPickupRate, int spawnEnemyType,int levelType)
{
	setTexture();

	if (levelType == 0)
	{
		levelMin = 700;
	}
	else if (levelType == 1)
	{
		levelMin = 420;
	}
	
	repairPickup = Entity(0, -100, 1, 0, repairTexture);
	fuelPickup = Entity(0, -100, 1, 1, fuelTexture);

	explosion.setTexture(*explosionTexture);
	explosion.setScale(0.15, 0.15);
	explosionTimer = sf::seconds(4);
	this->enemyInterval = enemyInterval;
	this->spawnPickupRate = spawnPickupRate;
	this->spawnEnemyType = spawnEnemyType;
	this->levelType = levelType;
	

	setEnemies();
	spawnEnemy();
}

GamePlayManager::~GamePlayManager()
{
}


//FUNCTION 

//Update ==============================================================================

void GamePlayManager::update()
{
	spawnEntity();
	spawnPickup();
	repairPickup.update();
	fuelPickup.update();
	pickupFixPos();
	enemyFixPos();

	explosion.setPosition(sf::Vector2f (player.getPlayerData().getPosition().x + 45, player.getPlayerData().getPosition().y - 15));
	explosionTimer = explosionClock.getElapsedTime();
}

int GamePlayManager::detectCollision()
{
	int returnInt = 0;
	for (int i = 0; i < enemy.size(); i++)
	{
		if (player.getPlayerHitBox().getGlobalBounds().intersects(enemy[i]->getEntity().getGlobalBounds()))
		{
			if (!enemy[i]->getIsDestroyed())
			{
				explosionClock.restart();
				enemy[i]->setIsDestroyed(true);
				returnInt = 1;
			}
		}

		if (player.getPlayerHitBox().getGlobalBounds().intersects(repairPickup.getEntity().getGlobalBounds()))
		{
			if (!repairPickup.getIsDestroyed())
			{
				repairPickup.setIsDestroyed(true);
				repairPickup.setEntityPosition(-100, -100);
				returnInt = 2;
			}
		}

		if (player.getPlayerHitBox().getGlobalBounds().intersects(fuelPickup.getEntity().getGlobalBounds()))
		{
			if (!fuelPickup.getIsDestroyed())
			{
				fuelPickup.setIsDestroyed(true);
				fuelPickup.setEntityPosition(-100, -100);
				returnInt = 3;
			}
		}
	}

	return returnInt;

	
}

void GamePlayManager::spawnEntity()
{
	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i]->setEntitySpeed(enemySpeed);
	}

	//Spawn Entities
	if (currentDistance / enemy.size() > enemyInterval)
	{
		spawnEnemy();
		spawnPickup();
	}

	for (int i = 0; i < enemy.size() - 1; i++)
	{
		enemy[i]->update();
	}

}

void GamePlayManager::spawnPickup()
{
	repairPickup.setEntitySpeed(enemySpeed);

	fuelPickup.setEntitySpeed(enemySpeed);
	
	if (!powerUpSpawned)
	{
		int randomChanceSpawn;
		int randomChooseType;
		int randomSetPosition;
	
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> dist(1, spawnPickupRate);
		std::uniform_real_distribution<double> dist1(1, 3);
		std::uniform_real_distribution<double> dist2(levelMin, 850);

		randomChanceSpawn = dist(mt);
		randomChooseType = dist1(mt);
		randomSetPosition = dist2(mt);


		if (randomChanceSpawn == 1)
		{
			if (randomChooseType == 1)//spawn repair
			{
				repairPickup.setIsDestroyed(false);
				repairPickup.setEntityPosition(1300, randomSetPosition);
			}
			else if (randomChooseType == 2)//spawn fuel
			{
				fuelPickup.setIsDestroyed(false);
				fuelPickup.setEntityPosition(1300, randomSetPosition);
			}
			
		}
	}
	
	if (repairPickup.getEntity().getPosition().x < 0 && fuelPickup.getEntity().getPosition().x < 0)
	{
		powerUpSpawned = false;
		
	}
	else
	{
		powerUpSpawned = true;
	}
	
}

//Draw   ==============================================================================

void GamePlayManager::render(sf::RenderTarget* target)
{
	for (int i = 0; i < enemy.size(); i++)
	{
		if (!enemy[i]->getIsDestroyed())
		{
			enemy[i]->render(target);
		}
	}

	repairPickup.render(target);
	fuelPickup.render(target);

	if (explosionTimer.asSeconds() < 0.3)
	{
		target->draw(explosion);
	}
	
}

//Setter ==============================================================================

void GamePlayManager::initVariable()
{
	enemyInterval = 800;
	spawnPickupRate = 1; // spawn chance every enemy spawn
}
void GamePlayManager::pickupFixPos()
{
	for (int i = 0; i < enemy.size(); i++)
	{
		if (fuelPickup.getEntity().getGlobalBounds().intersects(enemy[i]->getEntity().getGlobalBounds()))
		{
			fuelPickup.setEntityPosition(fuelPickup.getEntity().getPosition().x + 50, fuelPickup.getEntity().getPosition().y);
		}

		if (repairPickup.getEntity().getGlobalBounds().intersects(enemy[i]->getEntity().getGlobalBounds()))
		{
			repairPickup.setEntityPosition(repairPickup.getEntity().getPosition().x + 50, repairPickup.getEntity().getPosition().y);
		}
	}
	

	
}

void GamePlayManager::enemyFixPos()
{
	if (enemy[enemy.size() - 1]->getEntity().getGlobalBounds().intersects(enemy[enemy.size() - 2]->getEntity().getGlobalBounds()))
	{
		enemy[enemy.size() - 1]->setEntityPosition(enemy[enemy.size() - 1]->getEntity().getPosition().x + 100, enemy[enemy.size() - 1]->getEntity().getPosition().y);
	}
}

void GamePlayManager::spawnEnemy()
{
	//Determine Colour
	int textureColor;

	std::uniform_int_distribution<int> dist0(0, 4);
	std::mt19937 rngColor;
	rngColor.seed(std::random_device()());

	textureColor = dist0(rngColor);

	//Determine Type
	int enemyType;
	if (spawnEnemyType == 0)
	{
		enemyType = 0;
			
	}
	else if (spawnEnemyType == 1)
	{
		std::uniform_int_distribution<int> dist1(0, 3);
		std::mt19937 rngType;
		rngType.seed(std::random_device()());
		if (dist1(rngType) < 3)
		{
			enemyType = 0;
		}
		else
		{
			enemyType = 1;
		}
	}

	//Determine position
	std::uniform_int_distribution<int> dist2(levelMin, 920);
	std::mt19937 rngPos;
	rngPos.seed(std::random_device()());
	int pos = dist2(rngPos);

	if (enemyType == 0)
	{
		enemy.push_back(std::make_shared<Entity>(1400, pos, 0, enemyType, carTexture[textureColor]));
	}
	else if (enemyType == 1)
	{
		enemy.push_back(std::make_shared<Entity>(1400, pos, 0, enemyType, busTexture[textureColor]));
	}
	
}
void GamePlayManager::setEnemies()
{
	
	spawnEnemy();

	
}

void GamePlayManager::setTexture()
{
	//car texture

	carTexture[0] = resourceManager.getTexture("Asset/car1.png");
	carTexture[1] = resourceManager.getTexture("Asset/car2.png");
	carTexture[2] = resourceManager.getTexture("Asset/car3.png");
	carTexture[3] = resourceManager.getTexture("Asset/car4.png");
	carTexture[4] = resourceManager.getTexture("Asset/car5.png");

	//set bus
	busTexture[0] = resourceManager.getTexture("Asset/bus1.png");
	busTexture[1] = resourceManager.getTexture("Asset/bus2.png");
	busTexture[2] = resourceManager.getTexture("Asset/bus3.png");
	busTexture[3] = resourceManager.getTexture("Asset/bus4.png");
	busTexture[4] = resourceManager.getTexture("Asset/bus5.png");


	//set pickup
	repairTexture = resourceManager.getTexture("Asset/repairKit.png");
	fuelTexture = resourceManager.getTexture("Asset/fuel.png");
}

void GamePlayManager::setPlayerData(sf::Sprite playerData)
{
	player.setPlayerSprite(playerData);
	player.updateHitbox();
}

void GamePlayManager::setCurrentDistance(float distance)
{
	currentDistance = distance;
}

void GamePlayManager::setCurrentSpeed(float speed)
{
	enemySpeed = speed;
}


