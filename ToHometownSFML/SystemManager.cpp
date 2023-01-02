#include "SystemManager.h"


//CONSTRUCTOR
SystemManager::SystemManager(int currentLevel)
{
    if (currentLevel == 0)
    {
        gamePlayManager = new GamePlayManager(1000,1,0);
        maxDistance = 400;
        setData();
    }
    if (currentLevel == 1)
    {
        gamePlayManager = new GamePlayManager(1000, 1, 1);
        maxDistance = 600;
        setData();
    }
   
}
SystemManager::SystemManager()
{
    setData();
}

//FUNCTION 

//Update ==============================================================================
void SystemManager::update()
{
	player.update();
	gamePlayManager->update();
    level.update();
    mechanicManager.update();
    updateData();
}

//Draw   ==============================================================================
void SystemManager::render(sf::RenderTarget* target)
{
    level.render(target);
    player.render(target);
	gamePlayManager->render(target);
    
    mechanicManager.render(target);
}

//Setter ==============================================================================
void SystemManager::updateData()
{
    gamePlayManager->setPlayerData(player.getPlayerData());
    gamePlayManager->setCurrentDistance(level.getCurrentDistance());
    gamePlayManager->setCurrentSpeed(level.getRoadSpeed());
    mechanicManager.setCurrentDistance(level.getCurrentDistance());
    mechanicManager.setCurrentGear(level.getCurrentGear());
    
    int detectType = gamePlayManager->detectCollision();
    isInvi = mechanicManager.getIsInvi();

    if (!isInvi)
    {
        if (detectType == 1)
        {
            mechanicManager.removeLive();
        }
    }
   
    if (detectType == 2)
    {
        mechanicManager.addLive();
    }

    if (detectType == 3)
    {
        mechanicManager.setInvi();
    }

}

void SystemManager::setData()
{
    gamePlayManager->setEnemiesData();
}

//Getter ==============================================================================






