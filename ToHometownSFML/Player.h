#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Player
{
private:
	//Variable
	sf::Texture texture;
	sf::Vector2f position;
	sf::Sprite playerSprite;


	float posX;
	float posY;
	float movementSpeed;


public:
	
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
	void setPlayerSprite(sf::Sprite playerData);

};

