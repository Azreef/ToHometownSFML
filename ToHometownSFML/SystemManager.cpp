#include "SystemManager.h"


//CONSTRUCTOR

SystemManager::SystemManager()
{
}

SystemManager::SystemManager(int currentLevel)
{
    float enemyInterval;
    int spawnPickupRate;
    int spawnEnemyType;

    //Set Level Variable
    if (currentLevel == 0)
    {
        //Road Type
        levelType = 0;

        //Destination Distance
        maxDistance = 500;
        mechanicManager.setMaxDistance(maxDistance);

        //Time Limit
        timeLimit = sf::seconds(60);
        mechanicManager.setTimeLimit(timeLimit);

        //Enemy spawn frequency 
        enemyInterval = 10000;

        //Item Spawn frequency
        spawnPickupRate = 1;

        //Enemy Spawn Type (0 - Cars Only/ 1 - Cars and Bus)
        spawnEnemyType = 1;
       
    }
    else if (currentLevel == 1)
    {


    }
    else if (currentLevel == 2)
    {


    }

    //Create Gameplay
    std::shared_ptr<GamePlayManager> gamePlayManager(new GamePlayManager(enemyInterval, spawnPickupRate, spawnEnemyType, levelType));
    this->gamePlayManager = gamePlayManager;

    //Create Level
    std::shared_ptr<Level> level(new Level(levelType));
    this->level = level;

    //Create Player
    std::shared_ptr<Player> player(new Player(levelType));
    this->player = player;

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

void SystemManager::updateGameValue(int* gameState, sf::Time* remainingTime, int* remainingLive, int* remainingDistance,int* score)
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
    *score = mechanicManager.getMinScore() + (mechanicManager.getTimeLimit().asSeconds() * 10);
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






