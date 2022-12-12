#include "Player.h"

Player::Player()
{
	this->setSprite();
}

//Constructor
Player::Player(sf::Vector2f position)
{
	this->position = position;
}

//Function
void Player::setSprite()
{
	{
		if (!this->texture.loadFromFile("Asset/Player2.png"))
		{
			std::cout << "ERROR TEXTURE";
		}

		this->playerSprite.setTexture(this->texture);
		this->playerSprite.setPosition(this->position);
	}
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->playerSprite);
}


void Player::update()
{

}


