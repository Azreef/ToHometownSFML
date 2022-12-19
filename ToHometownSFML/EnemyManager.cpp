#include "EnemyManager.h"
#include <iostream>

//CONSTRUCTOR
EnemyManager::EnemyManager()
{
}


//FUNCTION 

//Update ==============================================================================

void EnemyManager::update()
{
	//Set all enemies speed to be the same
	this->enemySpeed = level.getRoadSpeed();


	//Set current distance
	currentDistance = level.getCurrentDistance();


	for (int i = 0; i < TOTAL_ENEMY; i++)
	{
		enemy[i].setEnemySpeed(enemySpeed);
	}

	//Find current number of enemy spawn
	if (this->currentDistance / this->currentEnemy > 1000 && this->currentEnemy < TOTAL_ENEMY)
	{
		this->currentEnemy++;
	}
	
	for (int i = 0; i < this->currentEnemy; i++)
	{
		this->enemy[i].update();
	}

	this->detectCollision();
}

void EnemyManager::detectCollision()
{

	for (int i = 0; i < TOTAL_ENEMY; i++)
	{
		if (player.getPlayerData().getGlobalBounds().intersects(enemy[i].getTempEnemy().getGlobalBounds()))
		{
			if (!enemy[i].getIsDestroyed())
			{
				enemy[i].setIsDestroyed(true);
				mechanicManager.removeLive();
			}
		}
	}
}

//Draw   ==============================================================================

void EnemyManager::render(sf::RenderTarget* target)
{

	for (int i = 0; i < this->currentEnemy; i++)
	{
		if (!enemy[i].getIsDestroyed())
		{
			this->enemy[i].render(target);
		}

	}

}

//Setter ==============================================================================

void EnemyManager::setEnemiesData()
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

	//Randomnize Type
	std::uniform_int_distribution<int> dist2(0, 1);
	for (int i = 0; i < TOTAL_ENEMY; i++)
	{
		randomType[i] = dist2(randomNum);
	}

	//Set Enemy Data
	for (int i = 0; i < TOTAL_ENEMY; i++)
	{
		std::cout << i << std::endl;
		enemy[i] = Enemy(1300, randomPos[i], randomType[i]);
	}

	std::cout << "Done Loading" << std::endl;
}

void EnemyManager::setPlayerData(sf::Sprite playerData)
{
	this->player.setPlayerSprite(playerData);;
}


