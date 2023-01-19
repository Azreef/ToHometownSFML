#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Main.hpp>

#include "Level.h"
#include "Player.h"

#include "GamePlayManager.h"
#include "MechanicManager.h"
#include "ResourceManager.h"


class SystemManager
{
private:
	
	std::shared_ptr <GamePlayManager> gamePlayManager;

	MechanicManager mechanicManager;
	ResourceManager resourceManager;

	std::shared_ptr <Player> player;
	std::shared_ptr <Level> level;
	

	bool isInvi;
	
	int maxDistance;
	sf::Time timeLimit;
	int levelType;

	sf::Sound hitSound;
	sf::Sound fuelSound;
	sf::Sound fuelDoneSound;
	sf::Sound repairSound;
	sf::Sound trafficSound;

	bool inviSoundPlayed = false;

public:
	SystemManager();
	~SystemManager();
	SystemManager(int currentLevel);
	
	
	
	void update();
	void render(sf::RenderTarget* target);
	void updateData();
	void updateLive();
	void setSoundFX();
	void updateGameValue(int* gameState,sf::Time* remainingTime, int* remainingLive, int* remainingDistance,int* score); //0-Not Finished | 1-Completed |  2-Out of Lives | 3-Out of time

};

