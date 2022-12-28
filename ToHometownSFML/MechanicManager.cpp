#include "MechanicManager.h"
#include <iostream>
#include <string>
//CONSTRUCTOR
MechanicManager::MechanicManager()
{
	this->initVariable();
	this->setFont();
}


//FUNCTION 

//Update ==============================================================================
void MechanicManager::update()
{
	this->updateText();
	inviTimerUpdate();
	
}

void MechanicManager::updateText()
{
	this->livesText.setString("Lives: " + std::to_string(lives));
	this->distanceText.setString("Distance: " + std::to_string(currentDistance/100));
	this->gearText.setString("Gear: " + std::to_string(currentGear));
	if (isInvi)
	{
		this->inviTimerText.setString("Invincibility: " + std::to_string(abs(inviTimer.asSeconds() - 5)));
	}
	else if (!isInvi)
	{
		this->inviTimerText.setString("");
	}
		
}

void MechanicManager::inviTimerUpdate()
{
	inviTimer = clock.getElapsedTime();
	if (inviTimer.asSeconds() >= 5)
	{
		isInvi = false;
	}
}


//Draw   ==============================================================================
void MechanicManager::render(sf::RenderTarget* target)
{
	target->draw(this->livesText);
	target->draw(this->distanceText);
	target->draw(this->gearText);
	target->draw(this->inviTimerText);
}


//Setter ==============================================================================
void MechanicManager::initVariable()
{
	this->score = 0;
	this->lives = 5;
	this->isInvi = false;
}
void MechanicManager::removeLive()
{
	this->lives--;
	
}
void MechanicManager::addLive()
{
	this->lives++;
}
void MechanicManager::setInvi()
{
	isInvi = true;
	clock.restart();
}

void MechanicManager::setFont()
{
	if (!this->font.loadFromFile("Asset/game_over.ttf"))
	{
		std::cout << "CANT LOAD FONT";
	}

	this->livesText.setFont(font);
	this->livesText.setCharacterSize(150);
	this->livesText.setFillColor(sf::Color::White);
	this->livesText.setString("Lives: ");
	this->livesText.setPosition(sf::Vector2f(20, -80));


	this->distanceText.setFont(font);
	this->distanceText.setCharacterSize(150);
	this->distanceText.setFillColor(sf::Color::White);
	this->distanceText.setString("Distance: ");
	this->distanceText.setPosition(sf::Vector2f(400, -80));

	this->gearText.setFont(font);
	this->gearText.setCharacterSize(150);
	this->gearText.setFillColor(sf::Color::White);
	this->gearText.setString("Distance: ");
	this->gearText.setPosition(sf::Vector2f(20, 50));

	this->inviTimerText.setFont(font);
	this->inviTimerText.setCharacterSize(150);
	this->inviTimerText.setFillColor(sf::Color::White);
	this->inviTimerText.setString("Invincible: ");
	this->inviTimerText.setPosition(sf::Vector2f(20, 200));


}

void MechanicManager::setCurrentDistance(int distance)
{
	this->currentDistance = distance;
}

void MechanicManager::setCurrentGear(int gear)
{
	this->currentGear = gear;
}


//Getter ==============================================================================

bool MechanicManager::getIsInvi()
{
	return isInvi;
}


