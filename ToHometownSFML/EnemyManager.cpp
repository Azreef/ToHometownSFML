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
	this->enemy[0].initVariable(1300, 600);
	this->enemy[1].initVariable(1300, 650);
	this->enemy[2].initVariable(1300, 700);
	this->enemy[3].initVariable(1300, 750);
	this->enemy[4].initVariable(1300, 800);
}
void EnemyManager::render(sf::RenderTarget* target)
{
	this->enemy[1].render(target);
	this->enemy[3].render(target);
	
	/*for (int i = 0; i < 5; i++)
	{
		this->enemy[i].render(target);
		std::cout << i << std::endl;
	}*/
	
	//this->enemy.render(target);
}

void EnemyManager::update()
{
	this->enemy[1].update();
	this->enemy[3].update();
	
	//for (int i = 0; i < 5; i++)
	//{
	//	this->enemy[i].update();
	//	//std::cout << "U" << std::endl;
	//}
	
}


