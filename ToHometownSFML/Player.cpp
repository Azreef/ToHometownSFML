#include "Player.h"

//Constructor
Player::Player()
{
	this->setSprite();
    this->initVariable();
}

Player::Player(float posX, float posY)
{

}

//Function

//void Player::setSprite()
//{
//    this->playerSprite.setSize(sf::Vector2f(300, 100));
//    this->playerSprite.setPosition(sf::Vector2f(100, 700));
//
//   
//
//}

void Player::setSprite()
{
	
	if (!this->texture.loadFromFile("Asset/Player2.png"))
	{
		std::cout << "ERROR TEXTURE";
	}

	this->playerSprite.setTexture(this->texture);
	this->playerSprite.setPosition(this->position);
    this->playerSprite.setScale(sf::Vector2f(0.2, 0.2));
	
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->playerSprite);
}


void Player::update()
{
    this->moveUpdate();
    //std::cout << playerSprite.getGlobalBounds().top << std::endl;;
}



void Player::moveUpdate()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->playerSprite.move(0, -this->movementSpeed);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->playerSprite.move(0, this->movementSpeed);
        
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->playerSprite.move(-this->movementSpeed, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->playerSprite.move(this->movementSpeed, 0);
    }
}

void Player::initVariable()
{
    this->movementSpeed = 10;
}

sf::Sprite Player::getPlayerData()
{
    return this->playerSprite;
}

