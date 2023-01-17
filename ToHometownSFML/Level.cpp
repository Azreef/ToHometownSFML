#include "Level.h"
#include <iostream>

//CONSTRUCTOR
Level::Level()
{
	initVariable(0,0);
	setSprite(0,0);
}

Level::Level(int levelType,int backGroundType)
{
	initVariable(levelType,backGroundType);
	setSprite(levelType,backGroundType);
}

//FUNCTION 

//Update ==============================================================================
void Level::update()
{
	scrollRoad();
	scrollBackground();
	roadSpeedControl();
	setCurrentDistance();
}

void Level::scrollRoad()
{
	roadSprite.move(-roadSpeed, 0);
	
	if (roadSprite.getPosition().x <= -1550)
	{
		roadSprite.setPosition(sf::Vector2f(0, roadYPos));
	}

}

void Level::scrollBackground()
{
	subBackGroundSprite[0].move(-roadSpeed * 0.2, 0);
	subBackGroundSprite[1].move(-roadSpeed * 0.2, 0);

	cloudBackGroundSprite[0].move(-roadSpeed * 0.02, 0);
	cloudBackGroundSprite[1].move(-roadSpeed * 0.02, 0);

	backGroundSprite.move(-roadSpeed * 0.008, 0);

	if (subBackGroundSprite[currentSub].getPosition().x <= -subBackGroundSprite[currentSub].getGlobalBounds().width)
	{
		if (currentSub == 0)
		{
			subBackGroundSprite[currentSub].setPosition(sf::Vector2f(subBackGroundSprite[currentSub].getGlobalBounds().width, subBackgroundYPos));
			currentSub = 1;
		}
		else if (currentSub == 1)
		{
			subBackGroundSprite[currentSub].setPosition(sf::Vector2f(subBackGroundSprite[currentSub].getGlobalBounds().width, subBackgroundYPos));
			currentSub = 0;
		}
	}

	if (cloudBackGroundSprite[currentCloud].getPosition().x <= -cloudBackGroundSprite[currentCloud].getGlobalBounds().width)
	{
		if (currentCloud == 0)
		{
			cloudBackGroundSprite[currentCloud].setPosition(sf::Vector2f(cloudBackGroundSprite[currentCloud].getGlobalBounds().width, cloudBackgroundYPos));
			currentCloud = 1;
		}
		else if (currentCloud == 1)
		{
			cloudBackGroundSprite[currentCloud].setPosition(sf::Vector2f(cloudBackGroundSprite[currentCloud].getGlobalBounds().width, cloudBackgroundYPos));
			currentCloud = 0;
		}
	}
}

void Level::roadSpeedControl()
{
	//Set Gear
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (currentGear < maxGear && !keyIsPressed)
		{
			currentGear++;
			keyIsPressed = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (currentGear > minGear && !keyIsPressed)
		{
			currentGear--;
			keyIsPressed = true;
		}
	}

	if (!((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))))
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

	target->draw(cloudBackGroundSprite[0]);
	target->draw(cloudBackGroundSprite[1]);

	target->draw(subBackGroundSprite[0]);
	target->draw(subBackGroundSprite[1]);
	target->draw(roadSprite);
}

//Setter ==============================================================================

void Level::setSprite(int levelType,int backGroundType)
{
	//Set Road Sprite
	if (levelType == 0)
	{
		if (!roadTexture.loadFromFile("Asset/road3.png"))
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
	}

	roadSprite.setTexture(roadTexture);
	roadSprite.setScale(sf::Vector2f(0.6, 0.6));
	roadSprite.setPosition(position);

	
	//Set Background
	if (backGroundType == 0)
	{
		if (!backGroundTexture.loadFromFile("Asset/cityBackground.png"))
		{
			std::cout << "ERROR TEXTURE";
		}

		if (!subBackGroundTexture.loadFromFile("Asset/building.png"))
		{
			std::cout << "ERROR TEXTURE";
		}

		if (!cloudBackGroundTexture.loadFromFile("Asset/cloud.png"))
		{
			std::cout << "ERROR TEXTURE";
		}

		for (int i = 0; i < 2; i++)
		{
			subBackGroundSprite[i].setTexture(subBackGroundTexture);
			subBackGroundSprite[i].setScale(sf::Vector2f(0.5, 0.5));

			cloudBackGroundSprite[i].setTexture(cloudBackGroundTexture);
			cloudBackGroundSprite[i].setScale(sf::Vector2f(0.4, 0.4));
		}

		backGroundSprite.setTexture(backGroundTexture);
		backGroundSprite.setScale(sf::Vector2f(1.2, 1.2));
		backGroundSprite.setPosition(backGroundPos);

		subBackGroundSprite[0].setPosition((sf::Vector2f(0, subBackgroundYPos)));
		subBackGroundSprite[1].setPosition((sf::Vector2f(subBackGroundSprite[0].getGlobalBounds().width, subBackgroundYPos)));

		cloudBackGroundSprite[0].setPosition((sf::Vector2f(0, cloudBackgroundYPos)));
		cloudBackGroundSprite[1].setPosition((sf::Vector2f(cloudBackGroundSprite[0].getGlobalBounds().width, cloudBackgroundYPos)));

		
	}

	else if (backGroundType == 1)
	{
		if (!backGroundTexture.loadFromFile("Asset/countryBackground.png"))
		{
			std::cout << "ERROR TEXTURE";
		}

		if (!subBackGroundTexture.loadFromFile("Asset/tree.png"))
		{
			std::cout << "ERROR TEXTURE";
		}

		if (!cloudBackGroundTexture.loadFromFile("Asset/cloud.png"))
		{
			std::cout << "ERROR TEXTURE";
		}

		for (int i = 0; i < 2; i++)
		{
			subBackGroundSprite[i].setTexture(subBackGroundTexture);
			subBackGroundSprite[i].setScale(sf::Vector2f(0.8, 0.8));

			cloudBackGroundSprite[i].setTexture(cloudBackGroundTexture);
			cloudBackGroundSprite[i].setScale(sf::Vector2f(0.4, 0.4));
		}

		backGroundSprite.setTexture(backGroundTexture);
		backGroundSprite.setScale(sf::Vector2f(0.5, 0.5));
		backGroundSprite.setPosition(backGroundPos);

		subBackGroundSprite[0].setPosition((sf::Vector2f(0, subBackgroundYPos)));
		subBackGroundSprite[1].setPosition((sf::Vector2f(subBackGroundSprite[0].getGlobalBounds().width, subBackgroundYPos)));

		cloudBackGroundSprite[0].setPosition((sf::Vector2f(0, cloudBackgroundYPos)));
		cloudBackGroundSprite[1].setPosition((sf::Vector2f(cloudBackGroundSprite[0].getGlobalBounds().width, cloudBackgroundYPos)));

	}

}

void Level::initVariable(int levelType, int backGroundType)
{
	roadSpeed = 10;
	maxGear = 5;
	minGear = 1;
	currentDistance = 0;
	currentGear = 1;

	//Set road variable
	if (levelType == 0)
	{
		roadYPos = 400;

		//Set background Variable
		if (backGroundType == 0)
		{
			backgroundYPos = -250;
			subBackgroundYPos = 30;
			cloudBackgroundYPos = 0;
		}
		else if (backGroundType == 1)
		{
			backgroundYPos = -300;
			subBackgroundYPos = 200;
			cloudBackgroundYPos = 0;
		}
		
	}
	else if (levelType == 1)
	{
		roadYPos = 175;

		//Set background Variable
		if (backGroundType == 0)
		{
			backgroundYPos = -400;
			subBackgroundYPos = -80;
			cloudBackgroundYPos = 0;
		}
		else if (backGroundType == 1)
		{
			backgroundYPos = -520;
			subBackgroundYPos = 20;
			cloudBackgroundYPos = 0;
		}
		
	}

	

	position = { 0,roadYPos};
	backGroundPos = { 0,backgroundYPos };
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

float Level::getCurrentGear()
{
	return currentGear;
}
