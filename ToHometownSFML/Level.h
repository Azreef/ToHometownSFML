#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
class Level
{
private:
	sf::Texture roadTexture;
	sf::Sprite roadSprite;
	sf::Vector2f position;
	sf::Vector2f backgroundPos;
	sf::Texture backGroundTexture;
	sf::Sprite backGroundSprite;
	float currentDistance;
	float roadSpeed;
	int maxGear;
	int minGear;

	float backgroundYPos;
	float roadYPos;
	int currentGear;
	bool keyIsPressed;
	
	

public:
	
	//Constructor
	Level();
	Level(int levelType);
	void render(sf::RenderTarget* target);
	void update();
	void setSprite(int levelType);
	void scrollRoad();
	//void setPosition(int levelType);
	void initVariable(int levelType);
	void roadSpeedControl();
	float getRoadSpeed();
	void setCurrentDistance();
	void setCurrentDistance(float distance);

	float getCurrentDistance();
	int getCurrentGear();


};

