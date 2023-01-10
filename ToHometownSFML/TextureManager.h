#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
class TextureManager
{
private:
	sf::Texture* carTexture;
	sf::Texture* busTexture;
	sf::Texture* fuelTexture;
	sf::Texture* repairTexture;


public:
	TextureManager();
	~TextureManager();
	void setTexture();

	sf::Texture* getTexture(int type, int id);
};

