#include "MechanicManager.h"
#include <iostream>
#include <string>
//CONSTRUCTOR
MechanicManager::MechanicManager()
{
	setFont();
	initVariable();
	
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
	minScore = abs(currentDistance / 100);
	
	gearBar.setSize(sf::Vector2f(currentGear*40, 40));
	if (currentGear <= 2)
	{
		gearBar.setFillColor(sf::Color::Green);
	}
	else if (currentGear >= 4 && currentGear < 5)
	{
		gearBar.setFillColor(sf::Color::Yellow);
	}
	else if (currentGear == 5)
	{
		gearBar.setFillColor(sf::Color::Red);
	}

	livesText.setString("Lives: " + std::to_string(lives));
	scoreText.setString("Score: " + std::to_string(abs(minScore)));

	if (isInvi)
	{
		inviTimerText.setString("Invincibility: ");
		inviBorder.setSize(sf::Vector2f(500, 45));
		inviBar.setSize(sf::Vector2f(abs(inviTimer.asSeconds() - 5) *100, 40));
	}
	else if (!isInvi)
	{
		inviBorder.setSize(sf::Vector2f(0, 0));
		inviTimerText.setString("");
		inviBar.setSize(sf::Vector2f(0, 0));
	}

	timeLimitText.setString("Time: " + std::to_string((int)abs(timeLimitStart.asSeconds() - timeLimitEnd.asSeconds())));

	
	float percent = currentDistance  / maxDistance;
	destinationBar.setSize(sf::Vector2f(1280 * (percent/100), 30));

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
	target->draw(destinationBar);

	target->draw(livesText);
	target->draw(scoreText);
	target->draw(gearText);
	target->draw(inviTimerText);
	target->draw(timeLimitText);

	target->draw(gearBorder);
	target->draw(gearBar);

	target->draw(inviBorder);
	target->draw(inviBar);
	
}


//Setter ==============================================================================
void MechanicManager::initVariable()
{
	minScore = 0;
	lives = 5;
	isInvi = false;

	destinationBar.setFillColor(sf::Color(144, 238, 144,180));
	destinationBar.setPosition(sf::Vector2f(0, 0));

	gearBar.setFillColor(sf::Color::Green);
	gearBar.setPosition(sf::Vector2f(gearText.getPosition().x + gearText.getCharacterSize() + 30 , gearText.getPosition().y + gearText.getCharacterSize() - 35));
	gearBar.setSize(sf::Vector2f(40, 40));

	gearBorder.setFillColor(sf::Color(0, 0, 0, 30));
	gearBorder.setPosition(sf::Vector2f(gearText.getPosition().x + gearText.getCharacterSize() - 2.5 + 30, gearText.getPosition().y + gearText.getCharacterSize() - 35 - 2.5));
	gearBorder.setSize(sf::Vector2f(205, 45));


	inviBar.setFillColor(sf::Color::Green);
	inviBar.setPosition(sf::Vector2f(inviTimerText.getPosition().x + inviTimerText.getCharacterSize() + 200, inviTimerText.getPosition().y + inviTimerText.getCharacterSize() - 35));
	inviBar.setSize(sf::Vector2f(40, 40));

	inviBorder.setFillColor(sf::Color(0,0,0,30));
	inviBorder.setPosition(sf::Vector2f(inviTimerText.getPosition().x + inviTimerText.getCharacterSize() - 2.5 + 200, inviTimerText.getPosition().y + inviTimerText.getCharacterSize() - 35 - 2.5));
	inviBorder.setSize(sf::Vector2f(205, 45));
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
	livesText.setString("Lives: 00");
	livesText.setPosition(sf::Vector2f(20, -50));
	livesText.setOutlineColor(sf::Color::Black);
	livesText.setOutlineThickness(4);

	scoreText.setFont(font);
	scoreText.setCharacterSize(150);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setString("Distance: 00");
	scoreText.setPosition(sf::Vector2f(sf::Vector2f(1280 / 2 - scoreText.getGlobalBounds().width /2, -50)));
	scoreText.setOutlineColor(sf::Color::Black);
	scoreText.setOutlineThickness(4);

	gearText.setFont(font);
	gearText.setCharacterSize(150);
	gearText.setFillColor(sf::Color::White);
	gearText.setString("Speed: ");
	gearText.setPosition(sf::Vector2f(20, 50));
	gearText.setOutlineColor(sf::Color::Black);
	gearText.setOutlineThickness(4);

	inviTimerText.setFont(font);
	inviTimerText.setCharacterSize(150);
	inviTimerText.setFillColor(sf::Color::White);
	inviTimerText.setString("Invincible: 00");
	inviTimerText.setPosition(sf::Vector2f(20, 150));
	inviTimerText.setOutlineColor(sf::Color::Black);
	inviTimerText.setOutlineThickness(4);

	timeLimitText.setFont(font);
	timeLimitText.setCharacterSize(150);
	timeLimitText.setFillColor(sf::Color::White);
	timeLimitText.setString("Time: 00");
	timeLimitText.setPosition(sf::Vector2f(1280 - timeLimitText.getGlobalBounds().width - 30, -50));
	timeLimitText.setOutlineColor(sf::Color::Black);
	timeLimitText.setOutlineThickness(4);

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


int MechanicManager::getMinScore()
{
	return minScore;
}


