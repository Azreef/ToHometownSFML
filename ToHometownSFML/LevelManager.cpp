#include "LevelManager.h"



LevelManager::LevelManager()
{
}

LevelManager::LevelManager(int currentLevel)
{
	SystemManager* systemManager = new SystemManager(currentLevel);
}



void LevelManager::update()
{
	systemManager->update();
}

void LevelManager::render(sf::RenderTarget* target)
{
	systemManager->render(target);
}



