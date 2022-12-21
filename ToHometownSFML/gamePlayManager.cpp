#include "GamePlayManager.h"
#include <iostream>

//CONSTRUCTOR
GamePlayManager::GamePlayManager()
{
}


//FUNCTION 

//Update ==============================================================================

void GamePlayManager::update()
{
	this->spawnEnemies();
	//this->detectCollision();
}

bool GamePlayManager::detectCollision()
{
	for (int i = 0; i < TOTAL_ENEMY; i++)
	{
		if (player.getPlayerData().getGlobalBounds().intersects(enemy[i].getTempEnemy().getGlobalBounds()))
		{
			if (!enemy[i].getIsDestroyed())
			{
				enemy[i].setIsDestroyed(true);
				return true;
			}
		}
	}
}

void GamePlayManager::spawnEnemies()
{
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
}

//Draw   ==============================================================================

void GamePlayManager::render(sf::RenderTarget* target)
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

void GamePlayManager::setPlayerData(sf::Sprite playerData)
{
	this->player.setPlayerSprite(playerData);
}

void GamePlayManager::setCurrentDistance(int distance)
{
	this->currentDistance = distance;
}

void GamePlayManager::setCurrentSpeed(int speed)
{
	this->enemySpeed = speed;
}


