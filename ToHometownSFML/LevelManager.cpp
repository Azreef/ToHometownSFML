#include "LevelManager.h"

LevelManager::LevelManager()
{
	//levelSelect();
}

void LevelManager::levelSelect()
{
	if (currentLevel == 1)
	{
		systemManager = SystemManager(1);
	}
}

void LevelManager::setCurrentLevel(int currentLevel)
{
	this->currentLevel = currentLevel;
}

void LevelManager::update()
{
	systemManager.update();
}

void LevelManager::render(sf::RenderTarget* target)
{
	systemManager.render(target);
}
