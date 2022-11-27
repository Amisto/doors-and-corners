#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <SFML/Graphics.hpp>

class Button
{
public:
    Button(std::string s, sf::Color color, sf::Vector2f pos, sf::Vector2f size);
    ~Button();

    void draw(sf::RenderWindow &window);
    bool check(sf::Vector2f mouseClick);

private:
    sf::RectangleShape rect;
    sf::Font font;
    sf::Text text;
};

#endif