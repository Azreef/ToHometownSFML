#pragma once
#include "SystemManager.h"

class LevelManager
{
private:
	SystemManager systemManager;
	int currentLevel = 1;

public:
	LevelManager();
	void levelSelect();
	void setCurrentLevel(int currentLevel);
	void update();
	void render(sf::RenderTarget* target);
};

