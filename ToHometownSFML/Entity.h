#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Level.h"
#include <memory>
#include "TextureManager.h"



class Entity
{
private:
	//Variable
	sf::Vector2f position;
	//sf::RectangleShape Entity;
	sf::Sprite entitySprite;
	bool isDestroyed;
	int entitySpeed;
	int entityType; // 0 = enemy , 1 = power ups
	int entitySubType; 
	TextureManager textureManager;

	
	//sf::Texture* texture;
	
public:
	
	//Constructor
	Entity(float x, float y,int type,int subtype);
	Entity();
		
	//Function
	void setSprite();
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
	void setEntitySpeed(int enemySpeed);
	void setEntityPosition(int x, int y);
	
};

