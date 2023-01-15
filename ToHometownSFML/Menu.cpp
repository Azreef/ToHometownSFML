#include "Menu.h"


Menu::Menu()
{
	refreshText();
	refreshButton();
	hasClicked = true;
	timerStarted = false;
}


void Menu::mainMenu(sf::RenderWindow *window,bool *isInMenu, int* currentLevel, int* currentMenu)
{
	refreshText();
	refreshButton();
	stopDoubleClick();

	backGroundTexture = resourceManager.getTexture("Asset/UI/mainMenu.png");
	backGroundImage.setTexture(*backGroundTexture);

	//setText(0, sf::Vector2f(0, 0), 100, "Main Menu");
	button[0] = Button(sf::Vector2f(800, 600), sf::Vector2f(400, 150), "Play", 100, &font);

	stopDoubleClick();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false) 
	{
		sf::RenderWindow& w = *window;
		sf::Vector2i mousePos = sf::Mouse::getPosition(w);

		if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //go to select level
		{
			*currentMenu = 1;
			*isInMenu = true;
			std::cout << "CLICK" << std::endl;
		}
		hasClicked = true;
	}
}

void Menu::selectMenu(sf::RenderWindow* window, bool* isInMenu, int* currentLevel, int* currentMenu, int completedLevel)
{
	refreshText();
	refreshButton();
	stopDoubleClick();

	backGroundTexture = resourceManager.getTexture("Asset/UI/selectScreen.png");
	backGroundImage.setTexture(*backGroundTexture);


	//setText(0, sf::Vector2f(0, 0), 100, "Select Level");

	button[0] = Button(sf::Vector2f(400, 250), sf::Vector2f(400, 150), "Level 1-1", 100,&font);

	//Lock Unfinished Levels
	if (completedLevel >= 1)
	{
		button[1] = Button(sf::Vector2f(400, 450), sf::Vector2f(400, 150), "Level 1-2", 100, &font);
	}
	if (completedLevel >= 2)
	{
		button[2] = Button(sf::Vector2f(400, 650), sf::Vector2f(400, 150), "Level 2-1", 100, &font);
	}
	if (completedLevel >= 3)
	{
		button[3] = Button(sf::Vector2f(400, 850), sf::Vector2f(400, 150), "Level 2-2", 100, &font);
	}

	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)
	{
		sf::RenderWindow& w = *window;
		sf::Vector2i mousePos = sf::Mouse::getPosition(w);

		
		if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //go to level 1
		{
			*currentLevel = 0;
			*currentMenu = 2;
			*isInMenu = true;	
		}
		if (button[1].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //go to level 2
		{
			*currentLevel = 1;
			*currentMenu = 2;
			*isInMenu = true;
		}
		if (button[2].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //go to level 2
		{
			*currentLevel = 2;
			*currentMenu = 2;
			*isInMenu = true;
		}
		if (button[3].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //go to level 2
		{
			*currentLevel = 3;
			*currentMenu = 2;
			*isInMenu = true;
		}
		hasClicked = true;
		
	}
}

void Menu::stageMenu(sf::RenderWindow* window, bool* isInMenu, int* currentLevel)
{
	refreshText();
	refreshButton();
	stopDoubleClick();


	//Stage Information
	if (*currentLevel == 0)
	{
		backGroundTexture = resourceManager.getTexture("Asset/UI/stage1.png");
		backGroundImage.setTexture(*backGroundTexture);
		
	}
	else if (*currentLevel == 1)
	{
		backGroundTexture = resourceManager.getTexture("Asset/UI/stage2.png");
		backGroundImage.setTexture(*backGroundTexture);
		
	}
	if (*currentLevel == 2)
	{
		backGroundTexture = resourceManager.getTexture("Asset/UI/stage3.png");
		backGroundImage.setTexture(*backGroundTexture);
	}
	else if (*currentLevel == 3)
	{
		backGroundTexture = resourceManager.getTexture("Asset/UI/stage4.png");
		backGroundImage.setTexture(*backGroundTexture);

	}


	button[0] = Button(sf::Vector2f(450, 600), sf::Vector2f(400, 150), "Continue", 100, &font);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)//Continue to Gameplay
	{
		sf::RenderWindow& w = *window;
		sf::Vector2i mousePos = sf::Mouse::getPosition(w);
		if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos)))
		{
			backGroundTexture = resourceManager.getTexture("Asset/UI/transition.png");
			backGroundImage.setTexture(*backGroundTexture);
			
			
			*isInMenu = false;
			//refreshButton();

		}
		hasClicked = true;
	}
	
}



void Menu::resultMenu(sf::RenderWindow* window, bool* isInMenu, int* currentLevel, int* currentMenu, int gameState, int remainingLive, sf::Time remainingTime, int remainingDistance, int* completedLevel,int* currentScore)
{

	refreshText();
	refreshButton();
	stopDoubleClick();

	sf::RenderWindow& w = *window;
	sf::Vector2i mousePos = sf::Mouse::getPosition(w);

	if (gameState == 1) //Successfull
	{
		*completedLevel = *currentLevel + 1; //Set level as completed

		backGroundTexture = resourceManager.getTexture("Asset/UI/levelComplete.png");
		backGroundImage.setTexture(*backGroundTexture);


		setText(0, sf::Vector2f(0, 0), 100, "Stage Completed!");
		setText(1, sf::Vector2f(0, 200), 100, "Time Left:" + std::to_string(remainingTime.asSeconds()));

		button[0] = Button(sf::Vector2f(150, 750), sf::Vector2f(400, 150), "Continue", 100, &font);
		button[1] = Button(sf::Vector2f(750, 750), sf::Vector2f(400, 150), "Return To Menu", 100, &font);
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)
		{
			if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Continue
			{
				backGroundTexture = resourceManager.getTexture("Asset/UI/transition.png");
				backGroundImage.setTexture(*backGroundTexture);
				
				*currentLevel = *currentLevel + 1;
				*currentMenu = 2;
				*isInMenu = true;
			}
			if (button[1].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Return to Main Menu
			{
				*currentMenu = 0;
				*isInMenu = true;
			}

			hasClicked = true;
		}
		
	}
	else if (gameState == 2 || gameState == 3) //Out if Lives & Time
	{
		setText(0, sf::Vector2f(0, 0), 100, "Stage Failed!");
		if (gameState == 2)
		{
			
			backGroundTexture = resourceManager.getTexture("Asset/UI/levelCarBroken.png");
			backGroundImage.setTexture(*backGroundTexture);
			
			setText(1, sf::Vector2f(0, 200), 100, "Out of Lives");
		}
		else if (gameState == 3)
		{
			backGroundTexture = resourceManager.getTexture("Asset/UI/levelOutTime.png");
			backGroundImage.setTexture(*backGroundTexture);
			
			setText(1, sf::Vector2f(0, 200), 100, "Out of Time");
		}
		
		setText(2, sf::Vector2f(0, 300), 100, "Distance Left: " + std::to_string(remainingDistance));

		button[0] = Button(sf::Vector2f(150, 750), sf::Vector2f(400, 150), "Retry", 100, &font);
		button[1] = Button(sf::Vector2f(750, 750), sf::Vector2f(400, 150), "Return To Menu", 100, &font);


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)
		{
			if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Retry
			{
				backGroundTexture = resourceManager.getTexture("Asset/UI/transition.png");
				backGroundImage.setTexture(*backGroundTexture);
				
				*currentLevel = *currentLevel;
				*currentMenu = 2;

				refreshButton();
				*isInMenu = true;
				
			}
			if (button[1].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Return to Main Menu
			{
				*currentMenu = 0;
				*isInMenu = true;
			}

			hasClicked = true;
		}

	}
}


void Menu::render(sf::RenderTarget* target)
{
	target->draw(backGroundImage);
	for (int i = 0; i < 10; i++)
	{
		button[i].render(target);
		target->draw(text[i]);
	}

}

void Menu::stopDoubleClick()
{
	if (timerStarted == false)
	{
		clock.restart();
		timerStarted = true;
	}

	if (hasClicked == true)
	{
		clickTimer = clock.getElapsedTime();
		//std::cout << clickTimer.asSeconds() << std::endl;
		if (clickTimer.asSeconds() > 1)
		{
			hasClicked = false;
			timerStarted = false;
		}
	}
}

void Menu::refreshText()
{
	font.loadFromFile("Asset/game_over.ttf");

	for (int i = 0; i < 10; i++)
	{
		text[i].setFont(font);
		text[i].setCharacterSize(0);
	}
}


void Menu::refreshButton()
{
	for (int i = 0; i < 10; i++)
	{
		button[i] = Button();
	}
}

void Menu::setText(int id, sf::Vector2f position, int size, sf::String content)
{
	text[id].setPosition(position);
	text[id].setCharacterSize(size);
	text[id].setString(content);
}




