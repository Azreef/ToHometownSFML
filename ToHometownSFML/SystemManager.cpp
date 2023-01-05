#include "SystemManager.h"


//CONSTRUCTOR

SystemManager::SystemManager()
{
    setData();
}

SystemManager::SystemManager(int currentLevel)
{
    if (currentLevel == 0)
    {
        gamePlayManager = new GamePlayManager(1000, 300, 0);
        maxDistance = 50;

        timeLimit = sf::seconds(60);
        mechanicManager.setTimeLimit(timeLimit);
        mechanicManager.setMaxDistance(maxDistance);

        setData();
    }
    if (currentLevel == 1)
    {
        gamePlayManager = new GamePlayManager(800, 1 , 1);
        maxDistance = 600;

        timeLimit = sf::seconds(80);
        mechanicManager.setTimeLimit(timeLimit);
        mechanicManager.setMaxDistance(maxDistance);

        setData();
    }

}

SystemManager::~SystemManager()
{
}
//FUNCTION 

//Update ==============================================================================
void SystemManager::update()
{
	player.update();
	gamePlayManager->update();
    level.update();
    mechanicManager.update();
    updateLive();
    updateData();
}

void SystemManager::updateData()
{
    gamePlayManager->setPlayerData(player.getPlayerData());
    gamePlayManager->setCurrentDistance(level.getCurrentDistance());
    gamePlayManager->setCurrentSpeed(level.getRoadSpeed());

    mechanicManager.setCurrentDistance(level.getCurrentDistance());
    mechanicManager.setCurrentGear(level.getCurrentGear());
}


void SystemManager::updateLive()
{
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

void SystemManager::updateGameValue(int* gameState, sf::Time* remainingTime, int* remainingLive)
{
    
    if (mechanicManager.getDistance() >= maxDistance * 100)
    {
        *gameState  = 1;
    }
    else if (mechanicManager.getLive() <= 0)
    {
        *gameState = 2;
    }
    else if (mechanicManager.getTimeLimit().asSeconds() >= timeLimit.asSeconds())
    {
        *gameState = 3;
    }
    else
    {
        *gameState = 0;
    }

    *remainingTime = mechanicManager.getTimeLimit();
    *remainingLive = mechanicManager.getLive();
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


void SystemManager::setData()
{
    gamePlayManager->setEnemiesData();
}



//Getter ==============================================================================






