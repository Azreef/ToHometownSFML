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
	text[0].setCharacterSize(100);
	text[0].setString("Main Menu");
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

void Menu::selectMenu(sf::RenderWindow* window, bool* isInMenu, int* currentLevel, int* currentMenu)
{
	refreshText();
	refreshButton();
	text[0].setCharacterSize(100);
	text[0].setString("SELECT LEVEL");

	button[0] = Button(sf::Vector2f(50, 200), sf::Vector2f(400, 150), "Level 1", 100,&font);
	button[1] = Button(sf::Vector2f(50, 400), sf::Vector2f(400, 150), "Level 2", 100, &font);
	
	stopDoubleClick();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hasClicked == false)
	{
		hasClicked = false;
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
	text[0].setCharacterSize(100);
	text[0].setString("Level " + std::to_string(*currentLevel + 1));

	if (currentLevel == 0)
	{

		text[1].setCharacterSize(100);
	}
}



void Menu::resultMenu(sf::RenderWindow* window, bool* isInMenu, int* currentLevel, int* currentMenu, int gameState, int remainingLive, sf::Time remainingTime)
{
	//std::cout << "RESULT" << std::endl;
	//createButton();
	font.loadFromFile("Asset/game_over.ttf");
	//resultText.setFont(font);

	sf::RenderWindow& w = *window;
	sf::Vector2i mousePos = sf::Mouse::getPosition(w);

	if (gameState == 1)
	{
		/*resultText[0].setFillColor(sf::Color::White);
		resultText[0].setCharacterSize(100);
		resultText[0].setString("STAGE COMPLETED");*/

		button[0] = Button(sf::Vector2f(200, 50), sf::Vector2f(400, 150), "Level 1", 100,&font);
		if (button[0].button.getGlobalBounds().contains(sf::Vector2f(mousePos)))
		{
			*currentLevel = 0;
			*isInMenu = false;
			std::cout << "CLICK" << std::endl;
		}


	}
	else if (gameState == 2)
	{

	}
	else if (gameState == 3)
	{
		
		/*resultText.setFont(font);
		resultText.setString("OUT OF TIME");
		resultText.setCharacterSize(100);
		resultText.setFillColor(sf::Color::White);*/

		/*button[0] = new Button(sf::Vector2f(50, 50), sf::Vector2f(400, 150), "Return To Menu", 100);

		sf::RenderWindow& w = *window;
		sf::Vector2i mousePos = sf::Mouse::getPosition(w);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (button[0]->button.getGlobalBounds().contains(sf::Vector2f(mousePos)))
			{
				std::cout << "CLICK" << std::endl;
				*isInMenu = true;
				*currentMenu = 0;
			}
		}*/
		
		
	}
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
		if (clickTimer.asSeconds() > 1.2)
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




