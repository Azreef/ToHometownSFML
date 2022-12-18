#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include "EnemyManager.h"
#include "Player.h"

class MechanicManager
{
private:
	EnemyManager enemyManager;
	Player player;

public:
	MechanicManager();

	void detectCollision();

	void update();
	

};

