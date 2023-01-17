#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Level.h"
#include <memory>
#include "ResourceManager.h"



class Entity
{
private:
	//Variable
	sf::Vector2f position;
	sf::Sprite entitySprite;
	bool isDestroyed;
	float entitySpeed;
	int entityType; // 0 = enemy , 1 = power ups
	int entitySubType; 
	ResourceManager resourceManager;

	
public:
	
	//Constructor
	Entity(float x, float y, int type, int subtype, std::shared_ptr<sf::Texture> Texture);
	Entity();
		
	//Function
	void setCar();
	void setBus();
	void setRepair();
	void setFuel();
	void initVariable(float x, float y);
	void render(sf::RenderTarget* target);
	void update();
	void entityScroll();
	sf::Sprite getEntity();
	bool getIsDestroyed();
	void setIsDestroyed(bool isDestoyed);
	void setEntitySpeed(float enemySpeed);
	void setEntityPosition(float x, float y);
	
};

