#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "ResourceManager.h"

class Player
{
private:
	//Variable
	std::shared_ptr<sf::Texture> texture;
	sf::Vector2f position;
	sf::Sprite playerSprite;
	sf::RectangleShape playerHitbox;

	float posX;
	float posY;
	float movementSpeed;
	float maxTop;
	float maxBottom;

	ResourceManager resourceManager;

public:
	
	//Constructor
	Player();
	Player(int levelType);

	//Function
	void setSprite();
	void render(sf::RenderTarget* target);
	void update();
	void moveUpdate();
	void initVariable(int levelType);
	sf::Sprite getPlayerData();
	sf::RectangleShape getPlayerHitBox();
	void setPlayerSprite(sf::Sprite playerData);
	void updateHitbox();

};

