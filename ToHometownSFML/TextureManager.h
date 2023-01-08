#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>

class TextureManager
{
private:
	sf::Texture* carTexture = new sf::Texture;
	sf::Texture* busTexture = new sf::Texture;;
	sf::Texture* fuelTexture = new sf::Texture;;
	sf::Texture* repairTexture = new sf::Texture;;


public:
	TextureManager();

	void setTexture();

	sf::Texture* getTexture(int type, int id);
};

