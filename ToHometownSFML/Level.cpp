#include "Level.h"


//Constructor
Level::Level()
{
	this->setPosition();
	this->setSpeed();
	this->setSprite();
}


//Function
void Level::render(sf::RenderTarget* target)
{
	target->draw(this->roadSprite);
}

void Level::update()
{
	this->scrollRoad();
	this->roadSpeedControl();
}

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

void Level::scrollRoad()
{
	this->roadSprite.move(-this->roadSpeed, 0);

	if (roadSprite.getPosition().x <= -1550)
	{
		roadSprite.setPosition(sf::Vector2f(0, 350));
	}
}

void Level::setPosition()
{
	position = {0,350};
}

void Level::setSpeed()
{
	this->roadSpeed = 10;
	this->maxSpeed = 30;
	this->minSpeed = 5;
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

float Level::getRoadSpeed()
{
	this->roadSpeedControl();
	return this->roadSpeed;
}
