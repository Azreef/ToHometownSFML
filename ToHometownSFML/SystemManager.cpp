#include "SystemManager.h"


//CONSTRUCTOR

SystemManager::SystemManager()
{
    //setData();
}

SystemManager::SystemManager(int currentLevel)
{

    if (currentLevel == 0)
    {
       //Set Gameplay
        levelType = 1;

        std::shared_ptr<GamePlayManager> gamePlayManager(new GamePlayManager(400, 1, 1, levelType));
        this->gamePlayManager = gamePlayManager;

        maxDistance = 500;

        timeLimit = sf::seconds(60);
        mechanicManager.setTimeLimit(timeLimit);
        mechanicManager.setMaxDistance(maxDistance);

        //setData();

        //Set Level
        std::shared_ptr<Level> level(new Level(levelType));
        this->level = level;

        std::shared_ptr<Player> player(new Player(levelType));
        this->player = player;
    }
    if (currentLevel == 1)
    {
        //gamePlayManager = new GamePlayManager(800, 1 , 1,0);
        maxDistance = 600;

        timeLimit = sf::seconds(80);
        mechanicManager.setTimeLimit(timeLimit);
        mechanicManager.setMaxDistance(maxDistance);

       // setData();

        //level = new Level(0);
    }

}

SystemManager::~SystemManager()
{
}
//FUNCTION 

//Update ==============================================================================
void SystemManager::update()
{
	player->update();
	gamePlayManager->update();
    level->update();
    mechanicManager.update();
    updateLive();
    updateData();
}

void SystemManager::updateData()
{
    gamePlayManager->setPlayerData(player->getPlayerData());
    gamePlayManager->setCurrentDistance(level->getCurrentDistance());
    gamePlayManager->setCurrentSpeed(level->getRoadSpeed());

    mechanicManager.setCurrentDistance(level->getCurrentDistance());
    mechanicManager.setCurrentGear(level->getCurrentGear());
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

void SystemManager::updateGameValue(int* gameState, sf::Time* remainingTime, int* remainingLive, int* remainingDistance)
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
    *remainingDistance = (maxDistance * 100) - mechanicManager.getDistance();
}
//Draw   ==============================================================================
void SystemManager::render(sf::RenderTarget* target)
{
    level->render(target);
    player->render(target);
	gamePlayManager->render(target);
    
    mechanicManager.render(target);
}


//Setter ==============================================================================


void SystemManager::setData()
{
    //gamePlayManager->setEnemiesData();
}



//Getter ==============================================================================






