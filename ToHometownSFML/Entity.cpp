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
			initVariable(x, y);
			setTempCar();
		}

		//Entity Type Bus
		else if (entitySubtype == 1)
		{
			initVariable(x, y);
			setTempBus();
		}
	}

	else if (entityType == 1)
	{
		//Entity Type Repair Kit
		if (entitySubtype == 0)
		{
			initVariable(x, y);
			setTempRepair();
		}
		else if (entitySubtype == 1)
		{
			initVariable(x, y);
			setTempFuel();
		}

	}
	
}

Entity::Entity()
{
	position = { 0,0 };
	setTempBus();
}

//FUNCTION 

//Update ==============================================================================

void Entity::update()
{
	entityScroll();
}

void Entity::entityScroll()
{
	tempEntity.move(-entitySpeed + 1, 0);

}


//Draw   ==============================================================================

void Entity::render(sf::RenderTarget* target)
{
	target->draw(tempEntity);
}


//Setter ==============================================================================

void Entity::setSprite()
{

}

void Entity::setTempBus()
{
	tempEntity.setSize(sf::Vector2f(300, 100));
	tempEntity.setPosition(position);
	entityType = 0;
	entitySubType = 1;
}

void Entity::setTempCar()
{
	tempEntity.setSize(sf::Vector2f(100, 100));
	tempEntity.setPosition(position);
	entityType = 0;
	entitySubType = 0;
}

void Entity::setTempRepair()
{
	tempEntity.setSize(sf::Vector2f(50, 50));
	tempEntity.setPosition(position);
	entityType = 1;
	entitySubType = 0;
	tempEntity.setFillColor(sf::Color::Green);
}

void Entity::setTempFuel()
{
	tempEntity.setSize(sf::Vector2f(50, 50));
	tempEntity.setPosition(position);
	entityType = 1;
	entitySubType =1;
	tempEntity.setFillColor(sf::Color::Yellow);
}

void Entity::initVariable(float x, float y)
{
	position = { x,y };
	isDestroyed = false;
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

	return isDestroyed;

}
