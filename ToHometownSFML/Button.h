#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>
#include <iostream>
//#include "Menu.h"

class Button
{
private:
	
	
public:
	Button();
	Button(sf::Vector2f position, sf::Vector2f size, sf::String textContent, int textSize, sf::Font *font);
	
	void render(sf::RenderTarget* target);

	bool isExist;
	sf::RectangleShape button;

	sf::RectangleShape getButtonBox();
	//sf::Text getButtonText();
	sf::Font font;
	
	sf::Text text;
};

