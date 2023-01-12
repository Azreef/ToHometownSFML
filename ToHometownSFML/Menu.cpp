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

	setText(0, sf::Vector2f(0, 0), 100, "Main Menu");
	button[0] = Button(sf::Vector2f(50, 200), sf::Vector2f(400, 150), "Select Level", 100, &font);

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

	setText(0, sf::Vector2f(0, 0), 100, "Select Level");

	button[0] = Button(sf::Vector2f(50, 200), sf::Vector2f(400, 150), "Level 1", 100,&font);

	//Lock Unfinished Levels
	if (completedLevel >= 1)
	{
		button[1] = Button(sf::Vector2f(50, 400), sf::Vector2f(400, 150), "Level 2", 100, &font);
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
		setText(1, sf::Vector2f(0, 0), 100, "Level 1-1");
		setText(2, sf::Vector2f(0, 300), 100, "City");
	}
	else if (*currentLevel == 1)
	{
		setText(1, sf::Vector2f(0, 0), 100, "Level 1-2");
		setText(2, sf::Vector2f(0, 300), 100, "City");
	}


	button[0] = Button(sf::Vector2f(50, 200), sf::Vector2f(400, 150), "Continue", 100, &font);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)//Continue to Gameplay
	{
		sf::RenderWindow& w = *window;
		sf::Vector2i mousePos = sf::Mouse::getPosition(w);
		if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos)))
		{
			*isInMenu = false;
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

		setText(0, sf::Vector2f(0, 0), 100, "Stage Completed!");
		setText(1, sf::Vector2f(0, 200), 100, "Time Left:" + std::to_string(remainingTime.asSeconds()));

		button[0] = Button(sf::Vector2f(50, 300), sf::Vector2f(400, 150), "Continue", 100, &font);
		button[1] = Button(sf::Vector2f(50, 500), sf::Vector2f(400, 150), "Return To Menu", 100, &font);
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)
		{
			if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Continue
			{
				*currentLevel = *currentLevel + 1;
				*isInMenu = false;
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
			setText(1, sf::Vector2f(0, 200), 100, "Out of Lives");
		}
		else if (gameState == 3)
		{
			setText(1, sf::Vector2f(0, 200), 100, "Out of Time");
		}
		
		setText(2, sf::Vector2f(0, 300), 100, "Distance Left: " + std::to_string(remainingDistance));

		button[0] = Button(sf::Vector2f(50, 300), sf::Vector2f(400, 150), "Retry", 100, &font);
		button[1] = Button(sf::Vector2f(50, 500), sf::Vector2f(400, 150), "Return To Menu", 100, &font);


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)
		{
			if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Retry
			{
				*currentLevel = *currentLevel;
				*isInMenu = false;
			}
			if (button[1].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Return to Main Menu
			{
				*currentMenu = 0;
				*isInMenu = true;
			}

			hasClicked = true;
		}

	}
	//else if (gameState == 3) //Out if Time
	//{
	//	setText(0, sf::Vector2f(0, 0), 100, "Stage Failed!");
	//	
	//	setText(2, sf::Vector2f(0, 300), 100, "Distance Left: " + std::to_string(remainingDistance));

	//	button[0] = Button(sf::Vector2f(50, 300), sf::Vector2f(400, 150), "Retry", 100, &font);
	//	button[1] = Button(sf::Vector2f(50, 500), sf::Vector2f(400, 150), "Return To Menu", 100, &font);


	//	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)
	//	{
	//		if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Retry
	//		{
	//			*currentLevel = *currentLevel;
	//			*isInMenu = false;
	//		}
	//		if (button[1].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Return to Main Menu
	//		{
	//			*currentMenu = 0;
	//			*isInMenu = true;
	//		}

	//		hasClicked = true;
	//	}
	//	
	//}
}


void Menu::render(sf::RenderTarget* target)
{
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
		std::cout << clickTimer.asSeconds() << std::endl;
		if (clickTimer.asSeconds() > 0.5)
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




