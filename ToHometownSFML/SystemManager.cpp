#include "SystemManager.h"


//CONSTRUCTOR
SystemManager::SystemManager()
{
    setData();
}

//FUNCTION 

//Update ==============================================================================
void SystemManager::update()
{
	player.update();
	GamePlayManager.update();
    level.update();
    mechanicManager.update();
    updateData();
}

//Draw   ==============================================================================
void SystemManager::render(sf::RenderTarget* target)
{
    level.render(target);
    player.render(target);
	GamePlayManager.render(target);
    
    mechanicManager.render(target);
}

//Setter ==============================================================================
void SystemManager::updateData()
{
    GamePlayManager.setPlayerData(player.getPlayerData());
    GamePlayManager.setCurrentDistance(level.getCurrentDistance());
    GamePlayManager.setCurrentSpeed(level.getRoadSpeed());
    mechanicManager.setCurrentDistance(level.getCurrentDistance());

}

void SystemManager::setData()
{
    GamePlayManager.setEnemiesData();
}

//Getter ==============================================================================






