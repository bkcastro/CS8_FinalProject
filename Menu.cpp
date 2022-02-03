//
// Created by Brandon Castro on 12/2/21.
//

#include "Menu.h"

Menu::Menu() {}

void Menu::run()
{
    sf::Sprite sprite;
    sprite.setTexture(Images::getImage(Images::LOGO));

    sf::Vector2f windowSize;

    windowSize.x = sprite.getGlobalBounds().width;
    windowSize.y = sprite.getGlobalBounds().height;

    HighLightText prompt;
    prompt.setString("Click To Continue");
    prompt.setOrigin(HighLightText::CENTER);
    prompt.setPosition({windowSize.x/2,windowSize.y-100});
    prompt.setFillColor(Colors::getColor(Colors::YELLOW));

    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "MenuBox");

    while (window.isOpen() && active)
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (prompt.checkCLick(window,event))
            {
                active = false;
            }
            prompt.addEventHandler(window,event);
        }

        window.clear(Colors::getColor(Colors::GRAY));
        window.draw(sprite);
        window.draw(prompt);
        window.display();

    }
}
