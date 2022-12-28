#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Level.h"

class Entity
{
private:
	//Variable
	sf::Vector2f position;
	sf::RectangleShape tempEntity;
	bool isDestroyed;
	int entitySpeed;
	int entityType; // 0 = enemy , 1 = power ups
	int entitySubType; 
	
	
public:
	
	//Constructor
	Entity(float x, float y,int type,int subtype);
	Entity();
		
	//Function
	void setSprite();
	void setTempCar();
	void setTempBus();
	void setTempRepair();
	void setTempFuel();
	void initVariable(float x, float y);
	void render(sf::RenderTarget* target);
	void update();
	void entityScroll();
	sf::RectangleShape getTempEntity();
	bool getIsDestroyed();
	void setIsDestroyed(bool isDestoyed);
	void setEntitySpeed(int enemySpeed);
	void setEntityPosition(int x, int y);
	
};

