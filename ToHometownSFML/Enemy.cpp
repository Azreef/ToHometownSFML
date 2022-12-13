#include "Enemy.h"
#include <iostream>

//Constructor
Enemy::Enemy(float x, float y)
{
	this->initVariable(x,y);
	this->setTemp();
}

Enemy::Enemy()
{
	this->initVariable(-4000, -4000);
	this->setTemp();
}



//Function
void Enemy::setSprite()
{
	
}

void Enemy::setTemp()
{
	this->tempEnemy.setSize(sf::Vector2f(300, 100));
	this->tempEnemy.setPosition(this->position);
}

void Enemy::initVariable(float x, float y)
{
	this->position = { x,y };
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->tempEnemy);
}

void Enemy::update()
{
	this->enemyScroll();
}

void Enemy::enemyScroll()
{
	this->tempEnemy.move(-level.getRoadSpeed() + 8,0);
	
	if (this->tempEnemy.getPosition().x < -300)
	{
		this->tempEnemy.setPosition(this->position);
	}
}



