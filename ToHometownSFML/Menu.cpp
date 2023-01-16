#include "Menu.h"


Menu::Menu()
{
	refreshText();
	refreshButton();
	hasClicked = false;
	timerStarted = false;

	std::shared_ptr<sf::SoundBuffer> clickSo = resourceManager.getSound("Asset/sound/button.ogg");
	clickSound.setBuffer(*clickSo);
	clickSound.setVolume(50);
}


void Menu::mainMenu(sf::RenderWindow *window,bool *isInMenu, int* currentLevel, int* currentMenu)
{
	stopDoubleClick();
	clickTimer = sf::seconds(0);
	refreshText();
	refreshButton();
	
	backGroundTexture = resourceManager.getTexture("Asset/UI/mainMenu.png");
	backGroundImage.setTexture(*backGroundTexture);


	button[0] = Button(sf::Vector2f(400, 550), sf::Vector2f(400, 100), "Play", 100, &font);
	button[1] = Button(sf::Vector2f(400, 700), sf::Vector2f(400, 100), "How To Play", 100, &font);
	button[2] = Button(sf::Vector2f(400, 850), sf::Vector2f(400, 100), "High Score", 100, &font);
	button[3] = Button(sf::Vector2f(100, 900), sf::Vector2f(250, 100), "Exit", 80, &font);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false) 
	{
		sf::RenderWindow& w = *window;
		sf::Vector2i mousePos = sf::Mouse::getPosition(w);

		if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //go to select level
		{
			clickSound.play();
			*currentMenu = 1;
			*isInMenu = true;
		}
		if (button[1].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //go to how to play
		{
			clickSound.play();
			*currentMenu = 5;
			*isInMenu = true;
		}
		if (button[2].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //go to score
		{
			clickSound.play();
			*currentMenu = 6;
			*isInMenu = true;
		}
		if (button[3].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //go to score
		{
			clickSound.play();
			window->close();
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

	button[4] = Button(sf::Vector2f(900, 900), sf::Vector2f(250, 100), "Back", 80, &font);
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)
	{
		sf::RenderWindow& w = *window;
		sf::Vector2i mousePos = sf::Mouse::getPosition(w);

		
		if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //go to level 1
		{
			clickSound.play();
			*currentLevel = 0;
			*currentMenu = 2;
			*isInMenu = true;	
		}
		if (button[1].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //go to level 2
		{
			clickSound.play();
			*currentLevel = 1;
			*currentMenu = 2;
			*isInMenu = true;
		}
		if (button[2].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //go to level 2
		{
			clickSound.play();
			*currentLevel = 2;
			*currentMenu = 2;
			*isInMenu = true;
		}
		if (button[3].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //go to level 2
		{
			clickSound.play();
			*currentLevel = 3;
			*currentMenu = 2;
			*isInMenu = true;
		}
		if (button[4].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //go to level 2
		{
			clickSound.play();
			*currentMenu = 0;
			*isInMenu = true;
		}
		hasClicked = true;
		stopDoubleClick();
		
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
			clickSound.play();
			backGroundTexture = resourceManager.getTexture("Asset/UI/transition.png");
			backGroundImage.setTexture(*backGroundTexture);
			
			refreshButton();
			*isInMenu = false;
			

		}
		hasClicked = true;
		stopDoubleClick();
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
		if (*completedLevel < *currentLevel + 1)
		{
			*completedLevel = *currentLevel + 1;
		}
		 //Set level as completed

		backGroundTexture = resourceManager.getTexture("Asset/UI/levelComplete.png");
		backGroundImage.setTexture(*backGroundTexture);


		setText(0, sf::Vector2f(400, 430), 180, "Time Taken: " + std::to_string((int)remainingTime.asSeconds()) + " sec");
		setText(1, sf::Vector2f(400, 530), 180, "Total Score: " + std::to_string(*currentScore));


		button[0] = Button(sf::Vector2f(150, 750), sf::Vector2f(400, 150), "Continue", 100, &font);
		button[1] = Button(sf::Vector2f(750, 750), sf::Vector2f(400, 150), "Return To Menu", 100, &font);
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)
		{
			if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Continue
			{
				clickSound.play();
				backGroundTexture = resourceManager.getTexture("Asset/UI/transition.png");
				backGroundImage.setTexture(*backGroundTexture);
				
				if (*currentLevel < 3)
				{
					*currentLevel = *currentLevel + 1;
					*currentMenu = 2;
					*isInMenu = true;
				}
				else if (*currentLevel >= 3)
				{
					*currentMenu = 4;
					*isInMenu = true;
				}
				
			}
			if (button[1].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Return to Main Menu
			{
				clickSound.play();
				clickTimer = sf::seconds(0);
				*currentMenu = 0;
				*isInMenu = true;
			}

			hasClicked = true;
		}
		
	}
	else if (gameState == 2 || gameState == 3) //Out if Lives & Time
	{
		if (gameState == 2)
		{
			
			backGroundTexture = resourceManager.getTexture("Asset/UI/levelCarBroken.png");
			backGroundImage.setTexture(*backGroundTexture);
			
		}
		else if (gameState == 3)
		{
			backGroundTexture = resourceManager.getTexture("Asset/UI/levelOutTime.png");
			backGroundImage.setTexture(*backGroundTexture);
			
		}
		
		button[0] = Button(sf::Vector2f(150, 750), sf::Vector2f(400, 150), "Retry", 100, &font);
		button[1] = Button(sf::Vector2f(750, 750), sf::Vector2f(400, 150), "Return To Menu", 100, &font);


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)
		{
			if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Retry
			{
				clickSound.play();

				backGroundTexture = resourceManager.getTexture("Asset/UI/transition.png");
				backGroundImage.setTexture(*backGroundTexture);
				
				*currentLevel = *currentLevel;
				*currentMenu = 2;

				refreshButton();
				*isInMenu = true;
				
			}
			if (button[1].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Return to Main Menu
			{
				clickSound.play();
				clickTimer = sf::seconds(0);
				*currentMenu = 0;
				*isInMenu = true;
			}

			hasClicked = true;
			stopDoubleClick();
		}

	}
}

void Menu::endMenu(sf::RenderWindow* window, int* currentMenu)
{
	refreshText();
	refreshButton();
	stopDoubleClick();

	sf::RenderWindow& w = *window;
	sf::Vector2i mousePos = sf::Mouse::getPosition(w);

	backGroundTexture = resourceManager.getTexture("Asset/UI/endScreen.png");
	backGroundImage.setTexture(*backGroundTexture);

	button[0] = Button(sf::Vector2f(450, 750), sf::Vector2f(400, 150), "Return To Menu", 100, &font);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)
	{
		if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Continue
		{
			clickSound.play();

			*currentMenu = 0;
		}
		hasClicked = true;
		stopDoubleClick();
	}
}

void Menu::howToPlayMenu(sf::RenderWindow* window, int* currentMenu)
{
	refreshText();
	refreshButton();
	stopDoubleClick();

	sf::RenderWindow& w = *window;
	sf::Vector2i mousePos = sf::Mouse::getPosition(w);

	backGroundTexture = resourceManager.getTexture("Asset/UI/howToPlay.png");
	backGroundImage.setTexture(*backGroundTexture);

	button[0] = Button(sf::Vector2f(800, 50), sf::Vector2f(400, 150), "Return To Menu", 100, &font);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)
	{
		if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Continue
		{
			clickSound.play();

			*currentMenu = 0;
		}
		hasClicked = true;
		stopDoubleClick();
	}

}

void Menu::scoreMenu(sf::RenderWindow* window, int* currentMenu, int *highScore,bool* isResetSave)
{
	refreshText();
	refreshButton();
	stopDoubleClick();

	sf::RenderWindow& w = *window;
	sf::Vector2i mousePos = sf::Mouse::getPosition(w);

	backGroundTexture = resourceManager.getTexture("Asset/UI/score.png");
	backGroundImage.setTexture(*backGroundTexture);

	button[0] = Button(sf::Vector2f(450, 850), sf::Vector2f(400, 150), "Return To Menu", 100, &font);
	button[1] = Button(sf::Vector2f(900, 900), sf::Vector2f(250, 100), "Reset Save", 80, &font);

	setText(0, sf::Vector2f(400, 200), 180, "Level 1-1 : " + std::to_string(highScore[0]));
	setText(1, sf::Vector2f(400, 300), 180, "Level 1-2 : " + std::to_string(highScore[1]));
	setText(2, sf::Vector2f(400, 400), 180, "Level 2-1 : " + std::to_string(highScore[2]));
	setText(3, sf::Vector2f(400, 500), 180, "Level 2-2 : " + std::to_string(highScore[3]));


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)
	{
		if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Continue
		{
			clickSound.play();

			*currentMenu = 0;
		}
		if (button[1].button.getGlobalBounds().contains(sf::Vector2f(mousePos))) //Continue
		{
			clickSound.play();

			*currentMenu = 0;
			*isResetSave = true;
			

		}
		hasClicked = true;
		stopDoubleClick();
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
	
	if (hasClicked)
	{
		clickTimer = clock.getElapsedTime();
		if (clickTimer.asSeconds() > 1.2)
		{
			hasClicked = false;
			timerStarted = false;
		}
	}
	if (timerStarted == false)
	{
		clock.restart();
		timerStarted = true;
	}

	
}

void Menu::refreshText()
{
	font.loadFromFile("Asset/game_over.ttf");

	for (int i = 0; i < 10; i++)
	{
		text[i].setFont(font);
		text[i].setCharacterSize(0);
		text[i].setPosition(sf::Vector2f(3000, 3000));
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
	text[id].setOutlineColor(sf::Color::Black);
	text[id].setOutlineThickness(8);
}




