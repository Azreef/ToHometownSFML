#include "Player.h"

//CONSTRUCTOR
Player::Player()
{
    initVariable();
    setSprite();
}

Player::Player(float posX, float posY)
{

}


//FUNCTION 

//Update ==============================================================================

void Player::update()
{
    moveUpdate();
}

void Player::moveUpdate()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        playerSprite.move(0, -movementSpeed);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        playerSprite.move(0, movementSpeed);

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        playerSprite.move(-movementSpeed, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        playerSprite.move(movementSpeed, 0);
    }

    //Border Collision

    //Left
    if (playerSprite.getPosition().x < 0)
    {
        playerSprite.setPosition(0, playerSprite.getPosition().y);
    }

    //Top
    if (playerSprite.getPosition().y < 600)
    {
        playerSprite.setPosition(playerSprite.getPosition().x, 600);
    }

    //Right
    if (playerSprite.getPosition().x + playerSprite.getGlobalBounds().width > 1280)
    {
        playerSprite.setPosition(1280 - playerSprite.getGlobalBounds().width, playerSprite.getPosition().y);
    }

    //Bottom
    if (playerSprite.getPosition().y + playerSprite.getGlobalBounds().height > 980)
    {
        playerSprite.setPosition(playerSprite.getPosition().x, 980 - playerSprite.getGlobalBounds().height);
    }
}


//Draw ==============================================================================

void Player::render(sf::RenderTarget* target)
{
    target->draw(playerSprite);
}


//Setter ==============================================================================

void Player::setSprite()
{
 
    if (!texture.loadFromFile("Asset/Player2.png"))
    {
        std::cout << "ERROR TEXTURE";
    }

    playerSprite.setTexture(texture);
    playerSprite.setPosition(position);
    playerSprite.setScale(sf::Vector2f(0.2, 0.2));
}

void Player::initVariable()
{
    movementSpeed = 10;
    position = { 0,700 };
}

void Player::setPlayerSprite(sf::Sprite playerData)
{
    playerSprite = playerData;
}


//Getter ==============================================================================

sf::Sprite Player::getPlayerData()
{
    return playerSprite;
}
