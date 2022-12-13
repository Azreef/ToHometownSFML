#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Level.h"

class Enemy
{
private:
	//Variable

	sf::RectangleShape tempEnemy;
	sf::Vector2f position;
	Level level;
	

public:
	//Constructor
	Enemy(float x, float y);
	Enemy();
		
	//Function
	void setSprite();
	void setTemp();
	void initVariable(float x, float y);
	void render(sf::RenderTarget* target);
	void update();
	void enemyScroll();
	

};

