#include "Enemy.h"
#include <iostream>

//CONSTRUCTOR
Enemy::Enemy(float x, float y, int enemyType)
{
	//Enemy Type Car
	if (enemyType == 0)
	{
		this->initVariable(x, y);
		this->setTempCar();
	}


	//Enemy Type Bus
	if (enemyType == 1)
	{
		this->initVariable(x, y);
		this->setTempBus();
	}

}

Enemy::Enemy()
{
	this->position = { 0,0 };
	this->setTempBus();
}

//FUNCTION 

//Update ==============================================================================

void Enemy::update()
{
	this->enemyScroll();
}

void Enemy::enemyScroll()
{
	this->tempEnemy.move(-this->enemySpeed + 3, 0);

}


//Draw   ==============================================================================

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->tempEnemy);
}


//Setter ==============================================================================

void Enemy::setSprite()
{

}

void Enemy::setTempBus()
{
	this->tempEnemy.setSize(sf::Vector2f(300, 100));
	this->tempEnemy.setPosition(this->position);
}

void Enemy::setTempCar()
{
	this->tempEnemy.setSize(sf::Vector2f(100, 100));
	this->tempEnemy.setPosition(this->position);
}

void Enemy::initVariable(float x, float y)
{
	this->position = { x,y };
	this->isDestroyed = false;

}

void Enemy::setIsDestroyed(bool isDestoyed)
{
	this->isDestroyed = isDestoyed;
}

void Enemy::setEnemySpeed(int enemySpeed)
{
	this->enemySpeed = enemySpeed;

}

//Getter ==============================================================================

sf::RectangleShape Enemy::getTempEnemy()
{
	return tempEnemy;
}

bool Enemy::getIsDestroyed()
{

	return this->isDestroyed;

}
