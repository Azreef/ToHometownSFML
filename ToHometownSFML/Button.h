#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>


class Button
{
private:
	sf::RectangleShape button;
	sf::Font font;
	sf::Text text;
	


public:
	Button();
	Button(sf::Vector2f position, sf::Vector2f size, sf::String textContent, int textSize);
	void handleInput(sf::RenderWindow& window);
	void draw(sf::RenderTarget* target);

	void setButton(sf::Vector2f position, sf::Vector2f size, sf::String text, int textSize);
	void setTextPos();

	bool isExist;

};

