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
}


//Draw   ==============================================================================
void MechanicManager::render(sf::RenderTarget* target)
{
	target->draw(this->livesText);
	target->draw(this->distanceText);
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

}

void MechanicManager::setCurrentDistance(int distance)
{
	this->currentDistance = distance;
}


//Getter ==============================================================================

