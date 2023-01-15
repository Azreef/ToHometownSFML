#include "Button.h"

Button::Button()
{
    button.setPosition(sf::Vector2f(0,0));
    button.setSize(sf::Vector2f(0, 0));
    button.setFillColor(sf::Color::White);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(2);

    isExist = true;
}

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::String textContent, int textSize, sf::Font* font)
{
    // Create the button's shape
    button.setPosition(position);
    button.setSize(size);
    button.setFillColor(sf::Color::White);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(2);

    // Create the button's text label
    text.setFont(*font);
    text.setString(textContent);
    text.setCharacterSize(textSize);
    text.setFillColor(sf::Color::Black);

     //Position the text relative to the button
     sf::FloatRect textRect = text.getLocalBounds();
     text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    text.setPosition(sf::Vector2f(button.getSize().x / 2.0f + button.getPosition().x, button.getSize().y / 2.0f + button.getPosition().y));
    isExist = true;
}


void Button::render(sf::RenderTarget* target)
{
    // Draw the button and text
    target->draw(button);
    target->draw(text);
}


sf::RectangleShape Button::getButtonBox()
{
    return button;
}

//sf::Text Button::getButtonText()
//{
   // return text;
//}



