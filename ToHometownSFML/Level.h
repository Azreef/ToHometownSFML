#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
class Level
{
private:
	sf::Texture texture;
	sf::Sprite roadSprite;
	sf::Vector2f position;
	int maxSpeed;
	int minSpeed;
	
	

public:
	int currentDistance;
	int roadSpeed;

	//Constructor
	Level();
	


	void render(sf::RenderTarget* target);
	void update();
	void setSprite();
	void scrollRoad();
	void setPosition();
	void initVariable();
	void initVariable(int speed);
	void roadSpeedControl();
	float getRoadSpeed();
	void setCurrentDistance();
	int getCurrentDistance();


};

