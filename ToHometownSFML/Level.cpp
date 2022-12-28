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
	//Set Gear
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if (this->currentGear < this->maxGear && !keyIsPressed)
		{
			this->currentGear++;
			this->keyIsPressed = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		if (this->currentGear > this->minGear && !keyIsPressed)
		{
			this->currentGear--;
			this->keyIsPressed = true;
		}
	}

	if (!((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))))
	{
		this->keyIsPressed = false;
	}



	//Set Speed
	if (this->currentGear == 1)
	{
		roadSpeed = 10;
	}
	else if (this->currentGear == 2)
	{
		roadSpeed = 15;
	}
	else if (this->currentGear == 3)
	{
		roadSpeed = 20;
	}
	else if (this->currentGear == 4)
	{
		roadSpeed = 25;
	}
	else if (this->currentGear == 5)
	{
		roadSpeed = 30;
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
	this->maxGear = 5;
	this->minGear = 1;
	this->currentDistance = 0;
	this->currentGear = 1;
}

void Level::setCurrentDistance()
{
	this->currentDistance = this->currentDistance + this->roadSpeed;
}

void Level::setCurrentDistance(float distance)
{
	this->currentDistance = distance;
}

//Getter ==============================================================================

float Level::getRoadSpeed()
{
	return this->roadSpeed;
}

float Level::getCurrentDistance()
{
	return this->currentDistance;
}

int Level::getCurrentGear()
{
	return this->currentGear;
}


