#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Level.h"

class Enemy
{
private:
	//Variable

	
	
	int enemySpeed;
	
public:
	Level level;
	sf::Vector2f position;
	sf::RectangleShape tempEnemy;
	bool isDestroyed;

	//Constructor
	Enemy(float x, float y,int type);
	Enemy();
		
	//Function
	void setSprite();
	void setTempCar();
	void setTempBus();
	void initVariable(float x, float y);
	void render(sf::RenderTarget* target);
	void update();
	void enemyScroll();
	sf::RectangleShape getTempEnemy();
	
	
};

