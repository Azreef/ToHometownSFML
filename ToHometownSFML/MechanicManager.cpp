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
	
}


//Draw   ==============================================================================
void MechanicManager::render(sf::RenderTarget* target)
{
	target->draw(this->livesText);
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

}

void MechanicManager::setCurrentDistance(int distance)
{
	this->currentDistance = distance;
}


//Getter ==============================================================================

