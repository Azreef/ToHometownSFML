#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>

class MechanicManager
{
private:
	int score;
	int lives;

public:
	
	MechanicManager();

	void initVariable();
	void removeLive();

};

