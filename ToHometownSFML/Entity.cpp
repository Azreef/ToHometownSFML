#include "Entity.h"
#include <iostream>

//CONSTRUCTOR
Entity::Entity(float x, float y, int entityType, int entitySubtype)
{
	if (entityType == 0)
	{
		//Entity Type Car
		if (entitySubtype == 0)
		{
			this->initVariable(x, y);
			this->setTempCar();
		}

		//Entity Type Bus
		else if (entitySubtype == 1)
		{
			this->initVariable(x, y);
			this->setTempBus();
		}
	}

	else if (entityType == 1)
	{
		//Entity Type Repair Kit
		if (entitySubtype == 0)
		{
			this->initVariable(x, y);
			this->setTempRepair();
		}
		else if (entitySubtype == 1)
		{
			this->initVariable(x, y);
			this->setTempFuel();
		}

	}
	
}

Entity::Entity()
{
	this->position = { 0,0 };
	this->setTempBus();
}

//FUNCTION 

//Update ==============================================================================

void Entity::update()
{
	this->entityScroll();
}

void Entity::entityScroll()
{
	this->tempEntity.move(-this->entitySpeed + 1, 0);

}


//Draw   ==============================================================================

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->tempEntity);
}


//Setter ==============================================================================

void Entity::setSprite()
{

}

void Entity::setTempBus()
{
	this->tempEntity.setSize(sf::Vector2f(300, 100));
	this->tempEntity.setPosition(this->position);
	this->entityType = 0;
	this->entitySubType = 1;
}

void Entity::setTempCar()
{
	this->tempEntity.setSize(sf::Vector2f(100, 100));
	this->tempEntity.setPosition(this->position);
	this->entityType = 0;
	this->entitySubType = 0;
}

void Entity::setTempRepair()
{
	this->tempEntity.setSize(sf::Vector2f(50, 50));
	this->tempEntity.setPosition(this->position);
	this->entityType = 1;
	this->entitySubType = 0;
	this->tempEntity.setFillColor(sf::Color::Green);
}

void Entity::setTempFuel()
{
	this->tempEntity.setSize(sf::Vector2f(50, 50));
	this->tempEntity.setPosition(this->position);
	this->entityType = 1;
	this->entitySubType =1;
	this->tempEntity.setFillColor(sf::Color::Yellow);
}

void Entity::initVariable(float x, float y)
{
	this->position = { x,y };
	this->isDestroyed = false;
}

void Entity::setIsDestroyed(bool isDestoyed)
{
	this->isDestroyed = isDestoyed;
}

void Entity::setEntitySpeed(int entitySpeed)
{
	this->entitySpeed = entitySpeed;

}

void Entity::setEntityPosition(int x,int y)
{
	tempEntity.setPosition((sf::Vector2f(x, y)));
}

//Getter ==============================================================================

sf::RectangleShape Entity::getTempEntity()
{
	return tempEntity;
}

bool Entity::getIsDestroyed()
{

	return this->isDestroyed;

}
