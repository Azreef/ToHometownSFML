#include "Level.h"
#include <iostream>

//CONSTRUCTOR
Level::Level()
{
	//setPosition();
	initVariable(0);
	setSprite(0);
}

Level::Level(int levelType)
{
	//setPosition();
	initVariable(levelType);
	setSprite(levelType);
}

//FUNCTION 

//Update ==============================================================================
void Level::update()
{
	scrollRoad();
	roadSpeedControl();
	setCurrentDistance();
}

void Level::scrollRoad()
{
	roadSprite.move(-roadSpeed, 0);
	backGroundSprite.move(-roadSpeed * 0.005, 0);

	if (roadSprite.getPosition().x <= -1550)
	{
		roadSprite.setPosition(sf::Vector2f(0, roadYPos));
	}
}

void Level::roadSpeedControl()
{
	//Set Gear
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if (currentGear < maxGear && !keyIsPressed)
		{
			currentGear++;
			keyIsPressed = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		if (currentGear > minGear && !keyIsPressed)
		{
			currentGear--;
			keyIsPressed = true;
		}
	}

	if (!((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))))
	{
		keyIsPressed = false;
	}


	//Set Speed
	if (currentGear == 1)
	{
		roadSpeed = 10;
	}
	else if (currentGear == 2)
	{
		roadSpeed = 15;
	}
	else if (currentGear == 3)
	{
		roadSpeed = 20;
	}
	else if (currentGear == 4)
	{
		roadSpeed = 25;
	}
	else if (currentGear == 5)
	{
		roadSpeed = 30;
	}
}
//Draw   ==============================================================================

void Level::render(sf::RenderTarget* target)
{
	target->draw(backGroundSprite);
	target->draw(roadSprite);
}

//Setter ==============================================================================

void Level::setSprite(int levelType)
{
	if (levelType == 0)
	{
		if (!roadTexture.loadFromFile("Asset/road3.png"))
		{
			std::cout << "ERROR TEXTURE";
		}

		if (!backGroundTexture.loadFromFile("Asset/cityBackground.png"))
		{
			std::cout << "ERROR TEXTURE";
		}
		
	}
	else if (levelType == 1)
	{
		if (!roadTexture.loadFromFile("Asset/road4.png"))
		{
			std::cout << "ERROR TEXTURE";
		}
		if (!backGroundTexture.loadFromFile("Asset/cityBackground.png"))
		{
			std::cout << "ERROR TEXTURE";
		}
	}

	roadSprite.setTexture(roadTexture);
	roadSprite.setScale(sf::Vector2f(0.6, 0.6));
	roadSprite.setPosition(position);

	backGroundSprite.setTexture(backGroundTexture);
	backGroundSprite.setScale(sf::Vector2f(1.2, 1.2));
	backGroundSprite.setPosition(backgroundPos);

}

//void Level::setPosition()
//{
//	
//}

void Level::initVariable(int levelType)
{
	
	roadSpeed = 10;
	maxGear = 5;
	minGear = 1;
	currentDistance = 0;
	currentGear = 1;
	if (levelType == 0)
	{
		roadYPos = 350;
		backgroundYPos = -300;
		
	}
	else if (levelType == 1)
	{
		roadYPos = 175;
		backgroundYPos = -300;
	}

	position = { 0,roadYPos};
	backgroundPos = { 0,backgroundYPos };
}

void Level::setCurrentDistance()
{
	currentDistance = currentDistance + roadSpeed;
}

void Level::setCurrentDistance(float distance)
{
	currentDistance = distance;
}

//Getter ==============================================================================

float Level::getRoadSpeed()
{
	return roadSpeed;
}

float Level::getCurrentDistance()
{
	return currentDistance;
}

int Level::getCurrentGear()
{
	return currentGear;
}


