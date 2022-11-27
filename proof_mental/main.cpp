#include <SFML/Graphics.hpp>

#include "Psyche.h"
#include "Button.h"

#include <vector>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(2000, 1600), "Psyche proof");

    Psyche* psyche = new Psyche(0, 0, 0.5);

    std::vector<Button> buttons;
    buttons.push_back(Button("New game", sf::Color::White, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(200.0f, 50.0f)));
    buttons.push_back(Button("Good action", sf::Color::Green, sf::Vector2f(50.0f, 150.0f), sf::Vector2f(200.0f, 50.0f)));
    buttons.push_back(Button("Bad action", sf::Color::Red, sf::Vector2f(300.0f, 150.0f), sf::Vector2f(200.0f, 50.0f)));
    buttons.push_back(Button("Chilling", sf::Color::Blue, sf::Vector2f(550.0f, 150.0f), sf::Vector2f(200.0f, 50.0f)));

    sf::Font font;
    font.loadFromFile("Impact.ttf");

    sf::Text psycheLabel("Psyche", font);
    psycheLabel.setPosition(50.0f, 1100.0f);
    sf::Text moodLabel("Mood", font);
    moodLabel.setPosition(550.0f, 1100.0f);
    sf::Text excitementLabel("Excitement", font);
    excitementLabel.setPosition(1550.0f, 1100.0f);

    bool isClick = false;
    while (window.isOpen())
    {
        window.clear();
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (auto b: buttons)
            b.draw(window);

        if (!isClick && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            isClick = true;
            sf::Vector2i i = sf::Mouse::getPosition(window);
            sf::Vector2f p(i.x, i.y);
            if (buttons[0].check(p))
            {
                delete psyche;
                psyche = new Psyche(0, 0, 0.5);
            }
            if (buttons[1].check(p))
            {
                psyche->action(1.0);
            }
            if (buttons[2].check(p))
            {
                psyche->action(-1.0);
            }
            if (buttons[3].check(p))
            {
                psyche->naturalDecay();
            }

            psycheLabel.setString("Psyche " + std::to_string(psyche->getPsyche()));
            moodLabel.setString("Mood " + std::to_string(psyche->getMood()));
            excitementLabel.setString("Excitement " + std::to_string(psyche->getExcitement()));

        }
        if (isClick && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            isClick = false;
        }
        window.draw(psycheLabel);
        window.draw(moodLabel);
        window.draw(excitementLabel);
        window.display();
    }

    return 0;
}
