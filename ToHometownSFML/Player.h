#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Player
{
private:
	
	sf::Texture texture;
	
	sf::Vector2f position;
	
	


	float posX;
	float posY;

	float movementSpeed;


public:
	
	sf::Sprite playerSprite;

	//Constructor
	Player();
	Player(float posX, float pos);

	//Function
	void setSprite();
	void render(sf::RenderTarget* target);
	void update();
	void moveUpdate();
	void initVariable();
	sf::Sprite getPlayerData();

	//void setPosition();
};

