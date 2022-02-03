//
// Created by Brandon Castro on 12/7/21.
//

#include "MenuBox.h"

#include <utility>

MenuBox::MenuBox() = default;

void MenuBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    main.addEventHandler(window, event);


    if (main.checkState(RECIPIENT))
    {
        list.addEventHandler(window, event);
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

void MenuBox::add(std::string title) {
    add(std::move(title), NONE);
}

void MenuBox::add(std::string title, TaskObjects obj)
{
    list.add(std::move(title), obj, main);
}

void MenuBox::setPosition(sf::Vector2f position) {
    main.setPosition(position);
    list.setPosition(main);
}

void MenuBox::setSize(sf::Vector2f size) {
    main.setSize(size);
    list.setSize(main);
}

void MenuBox::setText(std::string title) {
    main.setText(std::move(title));
}

void MenuBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(main);

    if (main.checkState(RECIPIENT))
    {
        window.draw(list);
    }
}

void MenuBox::update() {
    main.update();

    if (main.checkState(RECIPIENT))
    {
        list.update();
    }
}

sf::Vector2f MenuBox::getPosition() const {
    return main.getPosition();
}

sf::Vector2f MenuBox::getSize() const {
    return main.getSize();
}

void MenuBox::setTextColor(sf::Color color)
{
    main.setTextColor(color);
    list.setTextColor(color);
}

void MenuBox::setBoxColor(sf::Color color)
{
    main.setBoxColor(color);
    list.setBoxColor(color);
}