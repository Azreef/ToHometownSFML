#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Player
{
private:
	
	sf::Texture texture;
	sf::Sprite playerSprite;
	sf::Vector2f position;


public:
	//Constructor
	Player();
	Player(sf::Vector2f);

	//Function
	void setSprite();
	void render(sf::RenderTarget* target);
	void update();
	//void setPosition();


};

