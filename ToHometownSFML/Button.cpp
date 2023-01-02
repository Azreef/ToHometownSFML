#include "Button.h"

Button::Button()
{
    isExist = false;
}

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::String textContent, int textSize)
{
    // Create the button's shape
    button.setPosition(position);
    button.setSize(size);
    button.setFillColor(sf::Color::White);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(2);

    // Create the button's text label
    font.loadFromFile("Asset/game_over.ttf");

    text.setFont(font);
    text.setString(textContent);
    text.setCharacterSize(textSize);
    text.setFillColor(sf::Color::Black);

    // Position the text relative to the button
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    text.setPosition(sf::Vector2f(button.getSize().x / 2.0f + button.getPosition().x, button.getSize().y / 2.0f + button.getPosition().y));
    isExist = true;
}

void Button::handleInput(sf::RenderWindow& window)
{
    // Check if the mouse cursor is hovering over the button
    if (button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
    {
        button.setFillColor(sf::Color::Blue); // Change button color
    }
        
    else
    {
        button.setFillColor(sf::Color::White); // Reset button color
    }
        
}

void Button::draw(sf::RenderTarget* target)
{
    // Draw the button and text
 
    target->draw(button);
    target->draw(text);
} 
