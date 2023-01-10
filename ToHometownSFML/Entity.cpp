#include "Entity.h"


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
		}

		//Entity Type Bus
		else if (entitySubtype == 1)
		{
			initVariable(x, y);
			setBus();
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
	
	std::shared_ptr<sf::Texture> tex = textureManager.getTexture("Asset/car2.png");
	entitySprite.setTexture(*tex);
	
	entitySprite.setScale(sf::Vector2f(0.06, 0.06));
	entitySprite.setPosition(position);
	entityType = 0;
	entitySubType = 0;
	
}

void Entity::setBus()
{
	std::shared_ptr<sf::Texture> tex = textureManager.getTexture("Asset/bus.png");
	entitySprite.setTexture(*tex);

	entitySprite.setScale(sf::Vector2f(0.13, 0.13));
	entitySprite.setPosition(position);
	entityType = 0;
	entitySubType = 1;
}


void Entity::setRepair()
{
	std::shared_ptr<sf::Texture> tex = textureManager.getTexture("Asset/repairKit.png");
	entitySprite.setTexture(*tex);

	entitySprite.setScale(sf::Vector2f(0.05, 0.05));
	entitySprite.setPosition(position);

	entityType = 1;
	entitySubType = 0;
	
}

void Entity::setFuel()
{
	std::shared_ptr<sf::Texture> tex = textureManager.getTexture("Asset/fuel.png");
	entitySprite.setTexture(*tex);

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
