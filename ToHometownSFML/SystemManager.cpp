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
	gamePlayManager.update();
    level.update();
    mechanicManager.update();
    updateData();
}

//Draw   ==============================================================================
void SystemManager::render(sf::RenderTarget* target)
{
    level.render(target);
    player.render(target);
	gamePlayManager.render(target);
    
    mechanicManager.render(target);
}

//Setter ==============================================================================
void SystemManager::updateData()
{
    gamePlayManager.setPlayerData(player.getPlayerData());
    gamePlayManager.setCurrentDistance(level.getCurrentDistance());
    gamePlayManager.setCurrentSpeed(level.getRoadSpeed());
    mechanicManager.setCurrentDistance(level.getCurrentDistance());
    mechanicManager.setCurrentGear(level.getCurrentGear());

    if (gamePlayManager.detectCollision() == true)
    {
        mechanicManager.removeLive();
    }

}

void SystemManager::setData()
{
    gamePlayManager.setEnemiesData();
}

//Getter ==============================================================================






