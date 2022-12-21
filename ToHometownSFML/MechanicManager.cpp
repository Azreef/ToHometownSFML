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
	
}

void MechanicManager::updateText()
{
	this->livesText.setString("Lives: " + std::to_string(lives));
	this->distanceText.setString("Distance: " + std::to_string(currentDistance/100));
	this->gearText.setString("Gear: " + std::to_string(currentGear));
}


//Draw   ==============================================================================
void MechanicManager::render(sf::RenderTarget* target)
{
	target->draw(this->livesText);
	target->draw(this->distanceText);
	target->draw(this->gearText);
}


//Setter ==============================================================================
void MechanicManager::initVariable()
{
	this->score = 0;
	this->lives = 5;
}
void MechanicManager::removeLive()
{
	this->lives--;
	
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

