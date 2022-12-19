#include "Level.h"
#include <iostream>

//CONSTRUCTOR
Level::Level()
{
	this->setPosition();
	this->initVariable();
	this->setSprite();
}

//FUNCTION 

//Update ==============================================================================
void Level::update()
{
	this->scrollRoad();
	this->roadSpeedControl();
	this->setCurrentDistance();
}

void Level::scrollRoad()
{
	this->roadSprite.move(-this->roadSpeed, 0);

	if (roadSprite.getPosition().x <= -1550)
	{
		roadSprite.setPosition(sf::Vector2f(0, 350));
	}
}

void Level::roadSpeedControl()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if (this->roadSpeed < this->maxSpeed)
		{
			this->roadSpeed = this->roadSpeed + 1;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		if (this->roadSpeed > this->minSpeed)
		{
			this->roadSpeed = this->roadSpeed - 1;
		}
	}
}
//Draw   ==============================================================================

void Level::render(sf::RenderTarget* target)
{
	target->draw(this->roadSprite);
}

//Setter ==============================================================================

void Level::setSprite()
{

	if (!this->texture.loadFromFile("Asset/road3.png"))
	{
		std::cout << "ERROR TEXTURE";
	}
	this->roadSprite.setTexture(this->texture);
	this->roadSprite.setScale(sf::Vector2f(0.6, 0.6));
	this->roadSprite.setPosition(this->position);
}

void Level::setPosition()
{
	position = { 0,350 };
}

void Level::initVariable()
{
	this->roadSpeed = 10;
	this->maxSpeed = 30;
	this->minSpeed = 5;
	this->currentDistance = 0;
}

void Level::setCurrentDistance()
{
	this->currentDistance = this->currentDistance + this->roadSpeed;
}

//Getter ==============================================================================

float Level::getRoadSpeed()
{
	this->roadSpeedControl();
	return this->roadSpeed;
}

int Level::getCurrentDistance()
{
	this->setCurrentDistance();
	return this->currentDistance;
}
