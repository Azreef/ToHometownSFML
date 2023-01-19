#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <iostream>



#include "Level.h"
class MechanicManager
{
private:
	int minScore;
	int lives;
	float currentDistance;
	int currentGear;
	bool isInvi;
	int maxDistance;

	Level level;
	sf::Font font;
	sf::Text livesText;
	sf::Text scoreText;
	sf::Text gearText;
	sf::Text inviTimerText;
	sf::Text timeLimitText;

	sf::Clock clockInvi;
	sf::Time inviTimer;

	sf::Time timeLimitStart;
	sf::Time timeLimitEnd;
	sf::Clock clockTimer;

	sf::RectangleShape destinationBar;
	sf::RectangleShape gearBar;
	sf::RectangleShape gearBorder;

	sf::RectangleShape inviBar;
	sf::RectangleShape inviBorder;

public:
	
	MechanicManager();

	void setFont();
	void initVariable();
	void removeLive();
	void addLive();
	void setCurrentDistance(float dis);
	void setCurrentGear(float gear);
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
	void setMaxDistance(int maxDistance);

	int getMinScore();

};

