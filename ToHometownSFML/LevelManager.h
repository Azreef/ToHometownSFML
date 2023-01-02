#pragma once
#include "SystemManager.h"

class LevelManager
{
private:
	SystemManager* systemManager = new SystemManager();
	
public:
	LevelManager();
	LevelManager(int currentLevel);
	void update();
	void render(sf::RenderTarget* target);

};

