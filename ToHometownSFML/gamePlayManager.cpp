#include "GamePlayManager.h"
#include <iostream>

//CONSTRUCTOR
GamePlayManager::GamePlayManager()
{
	repairPickup = Entity(0,-100, 1, 0);
	fuelPickup = Entity(0, -100, 1, 1);
	initVariable();

}


//FUNCTION 

//Update ==============================================================================

void GamePlayManager::update()
{
	spawnEntity();
	spawnPickup();
	repairPickup.update();
	fuelPickup.update();
}

int GamePlayManager::detectCollision()
{
	int returnInt = 0;
	for (int i = 0; i < TOTAL_ENEMY; i++)
	{
		if (player.getPlayerData().getGlobalBounds().intersects(enemy[i].getTempEntity().getGlobalBounds()))
		{
			if (!enemy[i].getIsDestroyed())
			{
				enemy[i].setIsDestroyed(true);
				returnInt = 1;
			}
		}

		if (player.getPlayerData().getGlobalBounds().intersects(repairPickup.getTempEntity().getGlobalBounds()))
		{
			if (!repairPickup.getIsDestroyed())
			{
				repairPickup.setIsDestroyed(true);
				repairPickup.setEntityPosition(-100, -100);
				returnInt = 2;
			}
		}

		if (player.getPlayerData().getGlobalBounds().intersects(fuelPickup.getTempEntity().getGlobalBounds()))
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
	for (int i = 0; i < TOTAL_ENEMY; i++)
	{
		enemy[i].setEntitySpeed(enemySpeed);
	}

	//Find current number of enemy spawn
	if (currentDistance / currentEnemy > enemyInterval && currentEnemy < TOTAL_ENEMY)
	{
		currentEnemy++;
		spawnPickup();
	}


	for (int i = 0; i < currentEnemy; i++)
	{
		enemy[i].update();
	}
}

void GamePlayManager::spawnPickup()
{
	repairPickup.setEntitySpeed(enemySpeed);

	fuelPickup.setEntitySpeed(enemySpeed);
	//std::cout << powerUpSpawned  << " | " << repairPickup.getTempEntity().getPosition().x << std::endl;
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
	
	if (repairPickup.getTempEntity().getPosition().x < 0 && fuelPickup.getTempEntity().getPosition().x < 0)
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
	for (int i = 0; i < currentEnemy; i++)
	{
		if (!enemy[i].getIsDestroyed())
		{
			enemy[i].render(target);
		}
	}

	repairPickup.render(target);
	fuelPickup.render(target);
}

//Setter ==============================================================================

void GamePlayManager::setEnemiesData()
{
	std::cout << "Loading Enemies" << std::endl;

	std::uniform_int_distribution<int> dist(650, 850);
	std::mt19937 randomNum;
	int randomPos[TOTAL_ENEMY];
	int randomType[TOTAL_ENEMY];


	//Randomnize Position
	for (int i = 0; i < TOTAL_ENEMY; i++)
	{
		randomPos[i] = dist(randomNum);
	}

	//Randomnize subType
	std::uniform_int_distribution<int> dist2(0, 1);
	for (int i = 0; i < TOTAL_ENEMY; i++)
	{
		randomType[i] = dist2(randomNum);
	}

	//Set Entity Data
	for (int i = 0; i < TOTAL_ENEMY; i++)
	{
		std::cout << i << std::endl;
		enemy[i] = Entity(1400, randomPos[i], 0, randomType[i]);
	}

	std::cout << "Done Loading" << std::endl;
}

void GamePlayManager::initVariable()
{

	enemyInterval = 800;
	spawnPickupRate = 1; // spawn chance every enemy spawn


}
void GamePlayManager::setPlayerData(sf::Sprite playerData)
{
	player.setPlayerSprite(playerData);
}

void GamePlayManager::setCurrentDistance(int distance)
{
	currentDistance = distance;
}

void GamePlayManager::setCurrentSpeed(int speed)
{
	enemySpeed = speed;
}


