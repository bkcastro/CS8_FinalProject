#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Delay.h"
#include "SelectionSort.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(2200, 1500), "SFML Application");

    sf::Color backgroundColor(240,238,238);
    Grid stage(100);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(backgroundColor);
        window.draw(stage);
        window.display();

        if(!SelectionSort::getState())
        {
            SelectionSort::sort(stage);
            Delay::delay(10);
        }
    }
}