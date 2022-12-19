#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include "Level.h"
class MechanicManager
{
private:
	int score;
	int lives;
	int currentDistance;
	Level level;
public:
	
	MechanicManager();

	void initVariable();
	void removeLive();
	void setCurrentDistance(int dis);
	void update();
	

};

