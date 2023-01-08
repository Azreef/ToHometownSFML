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
			setCar();
			std::cout << "AA" << std::endl;
		}

		//Entity Type Bus
		else if (entitySubtype == 1)
		{
			initVariable(x, y);
			setBus();
			std::cout << "BB" << std::endl;
		}
	}

	else if (entityType == 1)
	{
		//Entity Type Repair Kit
		if (entitySubtype == 0)
		{
			initVariable(x, y);
			setRepair();
		}
		else if (entitySubtype == 1)
		{
			initVariable(x, y);
			setFuel();
		}

	}
	
}

Entity::Entity()
{
	position = { 0,0 };
	//setBus(texture);
}

//FUNCTION 

//Update ==============================================================================

void Entity::update()
{
	entityScroll();
}

void Entity::entityScroll()
{
	entitySprite.move(-entitySpeed + 1, 0);

}


//Draw   ==============================================================================

void Entity::render(sf::RenderTarget* target)
{
	target->draw(entitySprite);
}


//Setter ==============================================================================

void Entity::setCar()
{

	/*sf::Texture texture;
	texture.loadFromFile("Asset/car2.png");*/
	texture = new sf::Texture;

	texture->loadFromFile("Asset/car2.png");
	entitySprite.setTexture(*texture);


	entitySprite.setScale(sf::Vector2f(0.06, 0.06));
	entitySprite.setPosition(position);
	entityType = 0;
	entitySubType = 0;


	/*Entity.setSize(sf::Vector2f(100, 100));
	Entity.setPosition(position);
	entityType = 0;
	entitySubType = 0;*/
}

void Entity::setBus()
{
	texture = new sf::Texture;

	texture->loadFromFile("Asset/bus.png");
	entitySprite.setTexture(*texture);

	entitySprite.setScale(sf::Vector2f(0.13, 0.13));
	entitySprite.setPosition(position);
	entityType = 0;
	entitySubType = 1;
}


void Entity::setRepair()
{
	//sf::Texture texture;
	//texture.loadFromFile("Asset/repairKit.png");
	texture = new sf::Texture;

	texture->loadFromFile("Asset/repairKit.png");
	entitySprite.setTexture(*texture);

	entitySprite.setScale(sf::Vector2f(0.05, 0.05));
	entitySprite.setPosition(position);

	entityType = 1;
	entitySubType = 0;
	
}

void Entity::setFuel()
{
	//sf::Texture texture;
	//texture.loadFromFile("Asset/fuel.png");
	texture = new sf::Texture;

	texture->loadFromFile("Asset/fuel.png");
	entitySprite.setTexture(*texture);

	entitySprite.setScale(sf::Vector2f(0.05, 0.05));
	entitySprite.setPosition(position);

	entityType = 1;
	entitySubType = 1;
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
	entitySprite.setPosition((sf::Vector2f(x, y)));
}

//Getter ==============================================================================

sf::Sprite Entity::getEntity()
{
	return entitySprite;
}

bool Entity::getIsDestroyed()
{

	return isDestroyed;

}
