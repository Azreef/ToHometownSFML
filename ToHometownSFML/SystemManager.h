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
	GamePlayManager* gamePlayManager;
	MechanicManager mechanicManager;
	Player* player;
	Level* level;
	bool isInvi;
	
	int maxDistance;
	sf::Time timeLimit;
	int levelType;

public:
	SystemManager();
	~SystemManager();
	SystemManager(int currentLevel);
	
	

	void update();
	void render(sf::RenderTarget* target);
	void updateData();
	void setData();
	void updateLive();
	void updateGameValue(int* gameState,sf::Time* remainingTime, int* remainingLive, int* remainingDistance); //0-Not Finished | 1-Completed |  2-Out of Lives | 3-Out of time

};

