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
	Level level;
	sf::Font font;
	sf::Text livesText;

public:
	
	MechanicManager();

	void setFont();
	void initVariable();
	void removeLive();
	void setCurrentDistance(int dis);
	void update();
	void updateText();
	void render(sf::RenderTarget* target);

};

