#include "MechanicManager.h"
#include <iostream>
#include <string>
//CONSTRUCTOR
MechanicManager::MechanicManager()
{
	initVariable();
	setFont(); 
}


//FUNCTION 

//Update ==============================================================================
void MechanicManager::update()
{
	updateText();
	inviTimerUpdate();
	timeLimitUpdate();
}

void MechanicManager::updateText()
{
	livesText.setString("Lives: " + std::to_string(lives));
	distanceText.setString("Distance: " + std::to_string(abs(currentDistance / 100 - maxDistance)));
	gearText.setString("Gear: " + std::to_string(currentGear));

	if (isInvi)
	{
		inviTimerText.setString("Invincibility: " + std::to_string((int)abs(inviTimer.asSeconds() - 5)));
	}
	else if (!isInvi)
	{
		inviTimerText.setString("");
	}

	timeLimitText.setString("Time: " + std::to_string((int)abs(timeLimitStart.asSeconds() - timeLimitEnd.asSeconds())));
}

void MechanicManager::inviTimerUpdate()
{
	inviTimer = clockInvi.getElapsedTime();
	if (inviTimer.asSeconds() >= 5)
	{
		isInvi = false;
	}
}


//Draw   ==============================================================================
void MechanicManager::render(sf::RenderTarget* target)
{
	target->draw(livesText);
	target->draw(distanceText);
	target->draw(gearText);
	target->draw(inviTimerText);
	target->draw(timeLimitText);
}


//Setter ==============================================================================
void MechanicManager::initVariable()
{
	score = 0;
	lives = 5;
	isInvi = false;
}
void MechanicManager::removeLive()
{
	lives--;
	
}
void MechanicManager::addLive()
{
	lives++;
}
void MechanicManager::setInvi()
{
	isInvi = true;
	clockInvi.restart();
}

void MechanicManager::setFont()
{
	if (!font.loadFromFile("Asset/game_over.ttf"))
	{
		std::cout << "CANT LOAD FONT";
	}

	livesText.setFont(font);
	livesText.setCharacterSize(150);
	livesText.setFillColor(sf::Color::White);
	livesText.setString("Lives: ");
	livesText.setPosition(sf::Vector2f(20, -80));


	distanceText.setFont(font);
	distanceText.setCharacterSize(150);
	distanceText.setFillColor(sf::Color::White);
	distanceText.setString("Distance: ");
	distanceText.setPosition(sf::Vector2f(400, -80));

	gearText.setFont(font);
	gearText.setCharacterSize(150);
	gearText.setFillColor(sf::Color::White);
	gearText.setString("Distance: ");
	gearText.setPosition(sf::Vector2f(20, 50));

	inviTimerText.setFont(font);
	inviTimerText.setCharacterSize(150);
	inviTimerText.setFillColor(sf::Color::White);
	inviTimerText.setString("Invincible: ");
	inviTimerText.setPosition(sf::Vector2f(20, 200));

	timeLimitText.setFont(font);
	timeLimitText.setCharacterSize(150);
	timeLimitText.setFillColor(sf::Color::White);
	timeLimitText.setString("Time: ");
	timeLimitText.setPosition(sf::Vector2f(400, 50));

}

void MechanicManager::setCurrentDistance(int distance)
{
	currentDistance = distance;
}

void MechanicManager::setCurrentGear(int gear)
{
	currentGear = gear;
}


//Getter ==============================================================================

bool MechanicManager::getIsInvi()
{
	return isInvi;
}

int MechanicManager::getLive()
{
	return lives;
}

int MechanicManager::getDistance()
{
	return currentDistance;
}

void MechanicManager::timeLimitUpdate()
{
	timeLimitStart = clockTimer.getElapsedTime();
}

sf::Time MechanicManager::getTimeLimit()
{
	return timeLimitStart;
}

void MechanicManager::setMaxDistance(int maxDistance)
{
	this->maxDistance = maxDistance;
}


void MechanicManager::setTimeLimit(sf::Time timeLimit)
{
	this->timeLimitEnd = timeLimit;
	clockTimer.restart();
}




