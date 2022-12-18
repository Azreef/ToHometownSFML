#include "EnemyManager.h"
#include <iostream>


//Constructor
EnemyManager::EnemyManager()
{
}

//Function
void EnemyManager::spawnEnemies()
{

}

void EnemyManager::setEnemiesData()
{
	
	std::cout << "Loading Enemies" << std:: endl;
	std::uniform_int_distribution<int> dist(650, 850);
	std::mt19937 randomNum;

	for (int i = 0; i < TOTAL_ENEMY; i++)
	{
		std::cout << i << std::endl;
		enemy[i] = Enemy(1300, dist(randomNum),0);
		
	}
	std::cout << "Done Loading" << std::endl;
	/*enemy[0] = Enemy(1300, 650);
	
	enemy[1] = Enemy(1300, 700);
	enemy[2] = Enemy(1300, 750);
	enemy[3] = Enemy(1300, 800);
	enemy[4] = Enemy(1300, 850);*/
}

void EnemyManager::setPlayerData(sf::Sprite playerData)
{
	this->player.playerSprite = playerData;
}


void EnemyManager::detectCollision()
{
	
	for (int i = 0; i < TOTAL_ENEMY; i++)
	{
		if (player.playerSprite.getGlobalBounds().intersects(enemy[i].tempEnemy.getGlobalBounds()))
		{
			if (!enemy[i].isDestroyed)
			{
				enemy[i].isDestroyed = true;
				std::cout << "HIT" << std::endl;
			}
			
		}
	}
	
}	
void EnemyManager::render(sf::RenderTarget* target)
{

	for (int i = 0; i < this->currentEnemy; i++)
	{
		if (!enemy[i].isDestroyed)
		{
			this->enemy[i].render(target);
		}
		
	}

}	

void EnemyManager::update()
{
	//Set all enemies speed to be the same
	this->enemySpeed = enemy[0].level.roadSpeed;


	//Set current distance
	currentDistance = enemy[0].level.getCurrentDistance();

	//Find current number of enemy spawn
	for (int i = 0; i < TOTAL_ENEMY; i++)
	{
		enemy[i].level.roadSpeed = enemySpeed;
	}

	if (this->currentDistance/this->currentEnemy > 1000 && this->currentEnemy < TOTAL_ENEMY)
	{
		this->currentEnemy++;
	}
	//this->detectCollision();
	for (int i = 0; i < this->currentEnemy; i++)
	{
		this->enemy[i].update();
	}

	this->detectCollision();
	//std::cout << enemy[0].level.getCurrentDistance()<< std::endl;
}


