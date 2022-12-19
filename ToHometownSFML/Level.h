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
	int currentDistance;
	int roadSpeed;
	int maxSpeed;
	int minSpeed;
	

public:
	
	//Constructor
	Level();
	
	void render(sf::RenderTarget* target);
	void update();
	void setSprite();
	void scrollRoad();
	void setPosition();
	void initVariable();
	void roadSpeedControl();
	float getRoadSpeed();
	void setCurrentDistance();
	void setCurrentDistance(int distance);

	int getCurrentDistance();


};

