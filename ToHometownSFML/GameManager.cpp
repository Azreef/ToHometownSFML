#include "GameManager.h"
#include <iostream>

//CONSTRUCTOR

GameManager::GameManager()
{
    initVariable();
    openWindow();
    
    loadSave();

    loadingImage.setTexture(*loadingTexture);
}   

GameManager::~GameManager()
{
    delete window;
}

//FUNCTION 

//Update ==============================================================================

void GameManager::update()
{
    //Menu
   
    //Menu UI
    if (isInmenu)
    {
        levelIsSet = false;
       
       
        if (currentMenu == 0)
        {
            //Main Menu
               
            menu.mainMenu(window, &isInmenu, &currentLevel, &currentMenu);

        }
        else if (currentMenu == 1)
        {
            //Select Level
            menu.selectMenu(window, &isInmenu, &currentLevel, &currentMenu,completedLevel);

        }
        else if (currentMenu == 2)
        {
            //Stage Screen
            menu.stageMenu(window, &isInmenu, &currentLevel);
        }
        else if (currentMenu == 3)
        {
            //Result Screen
            menu.resultMenu(window, &isInmenu, &currentLevel, &currentMenu, gameState, remainingLive, remainingTime, remainingDistance, &completedLevel,&currentScore);
        }
        else if (currentMenu == 4)
        {
            //End Screen
            menu.endMenu(window, &currentMenu);
        }
        else if (currentMenu == 5)
        {
            menu.howToPlayMenu(window, &currentMenu);
        }
        //std::cout << currentMenu << std::endl;;
        if (musicIsPlaying == false || currentMusic != currentMenu)
        {
            loadBGM();
            
        }
        
    }
    
    //Load Levels
    if (!isInmenu)
    { 
        if (!levelIsSet)
        {
            //backgroundMusic.stop();
            musicIsPlaying = false;
            if (musicIsPlaying == false)
            {
                loadGameMusic();
            }

            loadingWindow = new sf::RenderWindow(sf::VideoMode(1280, 1080), "Loading", sf::Style::None);

            loadingWindow->draw(loadingImage);
            loadingWindow->display();


            std::shared_ptr<SystemManager> systemManager(new SystemManager(currentLevel));
            this->systemManager = systemManager;
           

            levelIsSet = true;
        }
        
    }
    

    //Update Levels
    if (!isInmenu)
    {
        systemManager->update();

        //Update Levels Variable
        systemManager->updateGameValue(&gameState, &remainingTime, &remainingLive, &remainingDistance,&currentScore);

        //Gameplay Finished (Stop Gameplay loop)
        if (gameState != 0) 
        {
           currentMenu = 3;
           isInmenu = true;
        }
 
    }

    pollEvent();
}

void GameManager::pollEvent()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                window->close();
            break;

        }
    }
}

void GameManager::loadSave()
{
    // Create a text string, which is used to output the text file
   std::string myText;

    // Read from the text file
    std::ifstream saveFile("save.txt");

    int currentLine = 0;
    // Use a while loop together with the getline() function to read the file line by line
    while (std::getline(saveFile, myText)) 
{
        // Output the text from the file
        if (currentLine == 0)
        {
            completedLevel = std::stoi(myText);
        }
        else if (currentLine == 1)
        {
            highScore[0] = std::stoi(myText);
        }
        else if (currentLine == 2)
        {
            highScore[1] = std::stoi(myText);
        }
        else if (currentLine == 3)
        {
            highScore[2] = std::stoi(myText);
        }
        else if (currentLine == 4)
        {
            highScore[3] = std::stoi(myText);
        }

        currentLine++;
    }
   
    saveFile.close();
}

void GameManager::setSave()
{
    //set save.txt
    std::ofstream saveFile("save.txt"); // open the file

    if (saveFile.is_open())
    {
        saveFile << completedLevel <<std::endl;
        saveFile << highScore[0] << std::endl;
        saveFile << highScore[1] << std::endl;
        saveFile << highScore[2] << std::endl;
        saveFile << highScore[3] << std::endl;
        saveFile.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
}

void GameManager::resetSave()
{
    //Reset save.txt
    std::ofstream saveFile("save.txt"); // open the file

    if (saveFile.is_open())
    {
        saveFile << 0 << std::endl;
        saveFile << 0 << std::endl;
        saveFile << 0 << std::endl;
        saveFile << 0 << std::endl;
        saveFile << 0 << std::endl;
        saveFile.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }

    //Reset Variable
    completedLevel = 0;
    highScore[0] = 0;
    highScore[1] = 0;
    highScore[2] = 0;
    highScore[3] = 0;
}

void GameManager::loadBGM()
{
    backgroundMusic.stop();
    if (currentMenu == 0) //main Theme
    {
        if (!backgroundMusic.openFromFile("Asset/sound/mainTheme.wav"))
        {
            std::cout << "Cant Open Music Files";
        }

        backgroundMusic.setVolume(25);
    }
    else if (currentMenu == 1) //select Level
    {
        if (!backgroundMusic.openFromFile("Asset/sound/selectScreen.wav"))
        {
            std::cout << "Cant Open Music Files";
        }
        backgroundMusic.setVolume(25);
    }
    else if (currentMenu == 2) //Stage Screen
    {
        if (!backgroundMusic.openFromFile("Asset/sound/stageScreen.wav"))
        {
            std::cout << "Cant Open Music Files";
        }
        backgroundMusic.setVolume(25);
    }
    else if (currentMenu == 3) //result
    {
        if (gameState == 1) // win
        {
            if (!backgroundMusic.openFromFile("Asset/sound/resultSuccess.wav"))
            {
                std::cout << "Cant Open Music Files";
            }
        }
        else if(gameState == 2 || gameState == 3)// lose
        {
            if (!backgroundMusic.openFromFile("Asset/sound/resultFailed.wav"))
            {
                std::cout << "Cant Open Music Files";
            }
        }
        backgroundMusic.setVolume(25);
    }
    else if (currentMenu == 4) //end
    {
        if (!backgroundMusic.openFromFile("Asset/sound/endScreen.wav"))
        {
            std::cout << "Cant Open Music Files";
        }
    }
    else if (currentMenu == 5) //How To Play
    {
        if (!backgroundMusic.openFromFile("Asset/sound/howToPlay.wav"))
        {
            std::cout << "Cant Open Music Files";
        }
    }
    else if (currentMenu == 6) //Score
    {
        if (!backgroundMusic.openFromFile("Asset/sound/scoreScreen.wav"))
        {
            std::cout << "Cant Open Music Files";
        }
    }
        backgroundMusic.play();
        musicIsPlaying = true;
        currentMusic = currentMenu;
   
}

void GameManager::loadGameMusic()
{
    if (currentLevel == 0) //main Theme
    {
        if (!backgroundMusic.openFromFile("Asset/sound/cityStage.wav"))
        {
            std::cout << "Cant Open Music Files";
        }

        backgroundMusic.setVolume(25);
    }
    else if (currentLevel == 1) //select Level
    {
        if (!backgroundMusic.openFromFile("Asset/sound/cityStage2.wav"))
        {
            std::cout << "Cant Open Music Files";
        }
    }
    else if (currentLevel == 2) //Stage Screen
    {
        if (!backgroundMusic.openFromFile("Asset/sound/countryStage.wav"))
        {
            std::cout << "Cant Open Music Files";
        }
    }
    else if (currentLevel == 3) //Stage Screen
    {
        if (!backgroundMusic.openFromFile("Asset/sound/countryStage2.wav"))
        {
            std::cout << "Cant Open Music Files";
        }
    }
    backgroundMusic.play();
    musicIsPlaying = true;
}

bool GameManager::running()
{
    return window->isOpen();
}

//Draw   ==============================================================================

void GameManager::render()
{
    window->clear();

    
    if (isInmenu)//Render Menu UI
    {       
        menu.render(window);      
    }
    else //Render Gameplay
    {
        systemManager->render(window);
        loadingWindow->close();
    }

    window->display();

}

//Setter ==============================================================================
void GameManager::openWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(1280, 1080), "To Hometown", sf::Style::None);
    
    window->setFramerateLimit(60);
}

void GameManager::initVariable()
{
    window = nullptr;

    currentMenu = 0;
    currentLevel = 0;
    completedLevel = 0;
    highScore[0] = 0;
    highScore[1] = 0;
    highScore[2] = 0;
    highScore[3] = 0;

    musicIsPlaying = false;
    levelIsSet = false;
    isInmenu = true;
}


