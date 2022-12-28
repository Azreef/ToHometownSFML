#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>

#include "Level.h"
#include "Player.h"
#include "GamePlayManager.h"
#include "MechanicManager.h"

class SystemManager
{
private:
	GamePlayManager gamePlayManager;
	MechanicManager mechanicManager;
	Player player;
	Level level;
	bool isInvi;

public:
	SystemManager();
	
	void update();
	void render(sf::RenderTarget* target);
	void updateData();
	void setData();

};

