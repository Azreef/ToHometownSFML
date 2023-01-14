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

	sf::Vector2f backGroundPos;
	sf::Texture backGroundTexture;
	sf::Sprite backGroundSprite;

	sf::Vector2f subBackGroundPos[2];
	sf::Texture subBackGroundTexture;
	sf::Sprite subBackGroundSprite[2];
	int currentSub = 0;

	sf::Vector2f cloudBackGroundPos[2];
	sf::Texture cloudBackGroundTexture;
	sf::Sprite cloudBackGroundSprite[2];
	int currentCloud = 0;


	float currentDistance;
	float roadSpeed;
	int maxGear;
	int minGear;

	float backgroundYPos;
	float subBackgroundYPos;
	float cloudBackgroundYPos;
	float roadYPos;
	int currentGear;
	bool keyIsPressed;
	
	
public:
	
	//Constructor
	Level();
	Level(int levelType, int backGroundType);
	void render(sf::RenderTarget* target);
	void update();
	void setSprite(int levelType, int backGroundType);
	void scrollRoad();
	void scrollBackground();
	void initVariable(int levelType, int backGroundType);
	void roadSpeedControl();
	float getRoadSpeed();
	void setCurrentDistance();
	void setCurrentDistance(float distance);

	float getCurrentDistance();
	int getCurrentGear();


};

