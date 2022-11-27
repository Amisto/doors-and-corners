#include "Button.h"
#include <iostream>

Button::Button(std::string s, sf::Color color, sf::Vector2f pos, sf::Vector2f size) : rect(size), text()
{
    rect.setPosition(pos);
    rect.setFillColor(color);

    if (!font.loadFromFile("Impact.ttf"))
    {
        std::cout << "no font founed" << std::endl;
        exit(0);
    }
    text.setFont(font);
    text.setString(s);
    text.setCharacterSize(24); 
    text.setPosition(pos);
}

Button::~Button()
{

}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(rect);
    window.draw(text);
}


bool Button::check(sf::Vector2f mouseClick)
{
    return (   mouseClick.x > rect.getPosition().x + rect.getOrigin().x 
        && mouseClick.x < rect.getPosition().x + rect.getOrigin().x + rect.getSize().x
        && mouseClick.y > rect.getPosition().y + rect.getOrigin().y
        && mouseClick.y < rect.getPosition().y + rect.getOrigin().y + rect.getSize().y );
}