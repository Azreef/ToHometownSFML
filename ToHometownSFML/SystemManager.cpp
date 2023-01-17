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
    int backGroundType;
    setSoundFX();

    trafficSound.play();

    //Set Level Variable
    if (currentLevel == 0)
    {
        //Road Type
        levelType = 0;

        //Background Type
        backGroundType = 0;

        //Destination Distance
        maxDistance = 300;
        mechanicManager.setMaxDistance(maxDistance);

        //Time Limit
        timeLimit = sf::seconds(60);
        mechanicManager.setTimeLimit(timeLimit);

        //Enemy spawn frequency 
        enemyInterval = 800;

        //Item Spawn frequency
        spawnPickupRate = 400;

        //Enemy Spawn Type (0 - Cars Only/ 1 - Cars and Bus)
        spawnEnemyType = 0;
       
    }
    else if (currentLevel == 1)
    {
        //Road Type
        levelType = 1;

        //Background Type
        backGroundType = 0;

        //Destination Distance
        maxDistance = 500;
        mechanicManager.setMaxDistance(maxDistance);

        //Time Limit
        timeLimit = sf::seconds(60);
        mechanicManager.setTimeLimit(timeLimit);

        //Enemy spawn frequency 
        enemyInterval = 600;

        //Item Spawn frequency
        spawnPickupRate = 400;

        //Enemy Spawn Type (0 - Cars Only/ 1 - Cars and Bus)
        spawnEnemyType = 0;

    }
    else if (currentLevel == 2)
    {
        //Road Type
        levelType = 0;

        //Background Type
        backGroundType = 1;

        //Destination Distance
        maxDistance = 600;
        mechanicManager.setMaxDistance(maxDistance);

        //Time Limit
        timeLimit = sf::seconds(65);
        mechanicManager.setTimeLimit(timeLimit);

        //Enemy spawn frequency 
        enemyInterval = 700;

        //Item Spawn frequency
        spawnPickupRate = 400;

        //Enemy Spawn Type (0 - Cars Only/ 1 - Cars and Bus)
        spawnEnemyType = 1;

    }
    else if (currentLevel == 3)
    {
        //Road Type
        levelType = 1;

        //Background Type
        backGroundType = 1;

        //Destination Distance
        maxDistance = 700;
        mechanicManager.setMaxDistance(maxDistance);

        //Time Limit
        timeLimit = sf::seconds(70);
        mechanicManager.setTimeLimit(timeLimit);

        //Enemy spawn frequency 
        enemyInterval = 500;

        //Item Spawn frequency
        spawnPickupRate = 300;

        //Enemy Spawn Type (0 - Cars Only/ 1 - Cars and Bus)
        spawnEnemyType = 1;

    }

    //Create Gameplay
    std::shared_ptr<GamePlayManager> gamePlayManager(new GamePlayManager(enemyInterval, spawnPickupRate, spawnEnemyType, levelType));
    this->gamePlayManager = gamePlayManager;

    //Create Level
    std::shared_ptr<Level> level(new Level(levelType, backGroundType));
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

    
    if (detectType == 1)
    {
        hitSound.play();
        if (!isInvi)
        {
            mechanicManager.removeLive();
        }
            
    }
    
    if (detectType == 2)
    {
        repairSound.play();
        mechanicManager.addLive();
    }

    if (detectType == 3)
    {
        fuelSound.play();
        inviSoundPlayed = true;
        mechanicManager.setInvi();
    }


    if (!mechanicManager.getIsInvi() && inviSoundPlayed)
    {
        fuelDoneSound.play();
        inviSoundPlayed = false;
    }
}

void SystemManager::setSoundFX()
{
    std::shared_ptr<sf::SoundBuffer> hitSo = resourceManager.getSound("Asset/sound/hitSound.wav");
    hitSound.setBuffer(*hitSo);

    std::shared_ptr<sf::SoundBuffer> fuelSo = resourceManager.getSound("Asset/sound/fuel.wav");
    fuelSound.setBuffer(*fuelSo);

    fuelSound.setVolume(25);

    std::shared_ptr<sf::SoundBuffer> repairSo = resourceManager.getSound("Asset/sound/repairKit.wav");
    repairSound.setBuffer(*repairSo);

    repairSound.setVolume(40);

    std::shared_ptr<sf::SoundBuffer> fuelDoneSo = resourceManager.getSound("Asset/sound/fuelDone.wav");
    fuelDoneSound.setBuffer(*fuelDoneSo);

    fuelDoneSound.setVolume(25);

    std::shared_ptr<sf::SoundBuffer> trafficSo = resourceManager.getSound("Asset/sound/traffic.wav");
    trafficSound.setBuffer(*trafficSo);

    trafficSound.setVolume(70);
}
void SystemManager::updateGameValue(int* gameState, sf::Time* remainingTime, int* remainingLive, int* remainingDistance,int* score)
{
    
    if (mechanicManager.getDistance() >= maxDistance * 100)
    {
        *gameState  = 1;    
        trafficSound.stop();
    }
    else if (mechanicManager.getLive() <= 0)
    {
        *gameState = 2;
        trafficSound.stop();
        
    }
    else if (mechanicManager.getTimeLimit().asSeconds() >= timeLimit.asSeconds())
    {
        *gameState = 3;
        trafficSound.stop();
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



//Getter ==============================================================================






