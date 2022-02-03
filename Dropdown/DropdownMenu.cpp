//
// Created by Brandon Castro on 12/7/21.
//

#include "DropdownMenu.h"

#include <utility>

DropdownMenu::DropdownMenu() {

}

void DropdownMenu::add(std::string title, TaskObjects objects) {

    list.add(std::move(title), objects, main);
}

void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(main);

    if (main.checkState(RECIPIENT))
    {
        window.draw(list);
    }
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    main.addEventHandler(window, event);


    if (main.checkState(RECIPIENT))
    {
        list.addEventHandler(window, event, main);
    }

    if (MouseEvents<Item>::mouseClicked(main, window))
    {
        main.enableState(RECIPIENT);
    }
    else if (MouseEvents<Item>::mouseClicked(window,event))
    {

        main.disableState(RECIPIENT);
    }
}

void DropdownMenu::update() {

    main.update();

    if (main.checkState(RECIPIENT))
    {
        list.update();
    }
}

void DropdownMenu::setPosition(sf::Vector2f position) {
    main.setPosition(position);
    list.setPosition(main);
}

void DropdownMenu::setSize(sf::Vector2f size) {
    main.setSize(size);
    list.setSize(main);
}

void DropdownMenu::setTextColor(sf::Color color)
{
    main.setTextColor(color);
    list.setTextColor(color);
}

void DropdownMenu::setBoxColor(sf::Color color)
{
    main.setBoxColor(color);
    list.setBoxColor(color);
}