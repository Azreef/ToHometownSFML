#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Enemy.h"

class EnemyManager
{
private:
	//Variable
	Enemy enemy[5];

public:
	//Constructor
	EnemyManager();
	void spawnEnemies();
	void render(sf::RenderTarget* target);
	void update();
	void setEnemiesData();


};

