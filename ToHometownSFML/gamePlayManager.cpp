#include "GamePlayManager.h"
#include <iostream>

//CONSTRUCTOR
GamePlayManager::GamePlayManager()
{
	initVariable();
}

GamePlayManager::GamePlayManager(float enemyInterval, int spawnPickupRate, int spawnEnemyType,int levelType)
{
	repairPickup = Entity(0, -100, 1, 0);
	fuelPickup = Entity(0, -100, 1, 1);

	this->enemyInterval = enemyInterval;
	this->spawnPickupRate = spawnPickupRate;
	this->spawnEnemyType = spawnEnemyType;
	this->levelType = levelType;
	setEnemies();
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
}

int GamePlayManager::detectCollision()
{
	std::cout << player.getPlayerHitBox().getGlobalBounds().left << std::endl;
	int returnInt = 0;
	for (int i = 0; i < enemy.size(); i++)
	{
		if (player.getPlayerHitBox().getGlobalBounds().intersects(enemy[i]->getEntity().getGlobalBounds()))
		{
			if (!enemy[i]->getIsDestroyed())
			{
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
	//std::cout << enemy.size() << std::endl;

	//Find current number of enemy spawn
	if (currentDistance / currentEnemy > enemyInterval && currentEnemy < TOTAL_ENEMY)
	{
		//spawnEnemy();
		spawnPickup();
		
		currentEnemy++;

	}

	for (int i = 0; i < currentEnemy; i++)
	{
		enemy[i]->update();
	}

	//if (currentEnemy > TOTAL_ENEMY)
	//{
	//	//currentEnemy = 0;
	//	resetEnemyPos();
	//	//reset pos

	//}
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
		std::uniform_real_distribution<double> dist2(650, 850);

		randomChanceSpawn = dist(mt);
		randomChooseType = dist1(mt);
		randomSetPosition = dist2(mt);

		//std::cout << random << std::endl;
		if (randomChanceSpawn == 1)
		{
			if (randomChooseType == 1)//spawn repair
			{
				std::cout << "Spawn Repair" << std::endl;
				repairPickup.setIsDestroyed(false);
				repairPickup.setEntityPosition(1300, randomSetPosition);
			}
			else if (randomChooseType == 2)//spawn fuel
			{
				std::cout << "Spawn Fuel" << std::endl;
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
}

//Setter ==============================================================================

//void GamePlayManager::setEnemiesData()
//{
//	std::cout << "Loading Enemies" << std::endl;
//	int min;
//
//	if (levelType == 0)
//	{
//		min = 650;
//	}
//	else if (levelType == 1)
//	{
//		min = 420;	
//	}
//
//
//	std::uniform_int_distribution<int> dist(min, 850);
//	std::uniform_int_distribution<int> dist2(0, 1);
//	std::mt19937 randomNum;
//	int randomPos[TOTAL_ENEMY];
//	int randomID[TOTAL_ENEMY];
//
//
//	//Randomnize Position
//	 
//	for (int i = 0; i < TOTAL_ENEMY; i++)
//	{
//		randomPos[i] = dist(randomNum);
//	}
//
//	//Randomnize subType
//
//	//Spawn Type 1
//	if (spawnEnemyType == 0)
//	{
//		for (int i = 0; i < TOTAL_ENEMY; i++)
//		{
//			randomID[i] = 0;
//		}
//
//	}
//	else if (spawnEnemyType == 1)
//	{
//		std::uniform_int_distribution<int> dist2(0, 1);
//		for (int i = 0; i < TOTAL_ENEMY; i++)
//		{
//			randomID[i] = dist2(randomNum);
//		}
//	}
//	
//	//Set Entity Data
//	//for (int i = 0; i < TOTAL_ENEMY; i = i + 1)
//	//{
//		//std::cout << i << std::endl;
//
//		/*enemy[i] = std::make_shared<Entity>(1400, randomPos[i], 0, randomID[i]);
//		enemy[i+1] = std::make_shared<Entity>(1400, randomPos[i+1], 0, randomID[i+1]);
//		enemy[i + 2] = std::make_shared<Entity>(1400, randomPos[i + 1], 0, randomID[i + 1]);*/
//		//enemy[i] = Entity(1400, randomPos[i], 0, randomID[i]);
//		enemy.push_back(std::make_shared<Entity>(1400, randomPos[i], 0, randomID[i]));
//	
//	//}
//
//	std::cout << "Done Loading" << std::endl;
//}




void GamePlayManager::initVariable()
{
	enemyInterval = 800;
	spawnPickupRate = 1; // spawn chance every enemy spawn
}
void GamePlayManager::pickupFixPos()
{
	//for (int i = 0; i < TOTAL_ENEMY; i++)
	//{
		if (fuelPickup.getEntity().getGlobalBounds().intersects(enemy[currentEnemy - 1]->getEntity().getGlobalBounds()))
		{
			fuelPickup.setEntityPosition(fuelPickup.getEntity().getPosition().x + 50, fuelPickup.getEntity().getPosition().y);
			std::cout << "Fixed" << std::endl;
		}

		if (repairPickup.getEntity().getGlobalBounds().intersects(enemy[currentEnemy - 1]->getEntity().getGlobalBounds()))
		{
			repairPickup.setEntityPosition(repairPickup.getEntity().getPosition().x + 50, repairPickup.getEntity().getPosition().y);
			std::cout << "Fixed" << std::endl;
		}

	//}
}

void GamePlayManager::resetEnemyPos()
{
	int min;

	if (levelType == 0)
	{
		min = 650;
	}
	else if (levelType == 1)
	{
		min = 420;
	}

	std::uniform_int_distribution<int> dist(min, 850);
	std::mt19937 randomNum;
	
	//Randomnize Position
	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i]->setEntityPosition(1400, dist(randomNum));
	}
	
}
void GamePlayManager::spawnEnemy()
{
	//
	//Determine Type
	
	int enemyType;
	if (spawnEnemyType == 0)
	{
		enemyType = 0;
			
	}
	else if (spawnEnemyType == 1)
	{
		std::uniform_int_distribution<int> dist1(0, 1);
		std::mt19937 rng;
		rng.seed(std::random_device()());
		enemyType = dist1(rng);
	}

	//Determine position
	int min;
	if (levelType == 0)
	{
		min = 650;
	}
	else if (levelType == 1)
	{
		min = 420;
	}

	std::uniform_int_distribution<int> dist2(min, 850);
	std::mt19937 rng;
	rng.seed(std::random_device()());
	int pos = dist2(rng);

	enemy.push_back(std::make_shared<Entity>(1400, pos, 0, enemyType));
	

	std::cout << enemy.size() << std::endl;
	
	
}
void GamePlayManager::setEnemies()
{
	for (int i = 0; i < TOTAL_ENEMY; i++)
	{
		spawnEnemy();
	}
}
void GamePlayManager::setPlayerData(sf::Sprite playerData)
{
	player.setPlayerSprite(playerData);
	player.updateHitbox();
}

void GamePlayManager::setCurrentDistance(int distance)
{
	currentDistance = distance;
}

void GamePlayManager::setCurrentSpeed(int speed)
{
	enemySpeed = speed;
}


