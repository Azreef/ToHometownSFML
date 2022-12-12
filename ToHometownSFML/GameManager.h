#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GameManager
{
private:
	sf::RenderWindow* window;
	sf::Event event;

public:
	
	//Function
	void openWindow();
	bool running();
	void initVariable();
	void render();
	void update();

	// Constructor
	GameManager();
	~GameManager();


};

