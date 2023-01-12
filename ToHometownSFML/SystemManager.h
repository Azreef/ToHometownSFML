#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>
#include <memory>

#include "Level.h"
#include "Player.h"

#include "GamePlayManager.h"
#include "MechanicManager.h"


class SystemManager
{
private:
	
	std::shared_ptr <GamePlayManager> gamePlayManager;

	MechanicManager mechanicManager;

	std::shared_ptr <Player> player;
	std::shared_ptr <Level> level;
	

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
	void updateGameValue(int* gameState,sf::Time* remainingTime, int* remainingLive, int* remainingDistance,int* score); //0-Not Finished | 1-Completed |  2-Out of Lives | 3-Out of time

};

