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
	float maxSpeed;
	float minSpeed;
	

public:
	
	//Constructor
	Level();
	void render(sf::RenderTarget* target);
	void update();
	void setSprite();
	void scrollRoad();
	void setPosition();
	void setSpeed();
	void roadSpeedControl();
	float getRoadSpeed();



};

