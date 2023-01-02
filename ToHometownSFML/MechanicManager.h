#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include "Level.h"
#include <SFML/System.hpp>

class MechanicManager
{
private:
	int score;
	int lives;
	int currentDistance;
	int currentGear;
	bool isInvi;
	
	Level level;
	sf::Font font;
	sf::Text livesText;
	sf::Text distanceText;
	sf::Text gearText;
	sf::Text inviTimerText;
	sf::Text timeLimitText;

	sf::Clock clockInvi;
	sf::Time inviTimer;

	sf::Time timeLimitStart;
	sf::Time timeLimitEnd;
	sf::Clock clockTimer;

public:
	
	MechanicManager();

	void setFont();
	void initVariable();
	void removeLive();
	void addLive();
	void setCurrentDistance(int dis);
	void setCurrentGear(int gear);
	void update();
	void updateText();
	void render(sf::RenderTarget* target);
	void setInvi();
	void inviTimerUpdate();
	bool getIsInvi();
	int getLive();
	
	int getDistance();
	void setTimeLimit(sf::Time timeLimit);
	void timeLimitUpdate();
	sf::Time getTimeLimit();

};

