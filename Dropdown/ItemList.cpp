//
// Created by Brandon Castro on 12/7/21.
//

#include "ItemList.h"

#include <utility>

ItemList::ItemList() {}

void ItemList::add(std::string title, const Item& main) {
    add(std::move(title),NONE, main);
}

void ItemList::add(std::string title, TaskObjects obj, const Item &main)
{
    Item temp;
    temp.setTask(obj);
    temp.setText(std::move(title));
    temp.setTextColor(main.getTextColor());
    temp.setBoxColor(main.getBoxColor());

    float x = main.getPosition().x;
    float y = (main.getPosition().y+(main.getSize().y*static_cast<float>(list.size()+1)));

    temp.setSize({main.getSize()});
    temp.setPosition({x,y});

    list.push_back(temp);
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < list.size(); i++)
    {
        window.draw(list[i]);
    }
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event, Item &main) {
    for (int i = 0; i < list.size(); i++)
    {
        list[i].addEventHandler(window, event);
        if (MouseEvents<Item>::mouseClicked(list[i], window))
        {
            main.setText(list[i].getText());
            main.disableState(RECIPIENT);
        }
    }
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    for (int i = 0; i < list.size(); i++)
    {
        list[i].addEventHandler(window, event);
        if (MouseEvents<Item>::mouseClicked(list[i], window))
        {
            // do something else
        }
    }
}

void ItemList::update() {
    for (int i = 0; i < list.size(); i++)
    {
        list[i].update();
    }
}

void ItemList::setPosition(const Item& main) {
    float x = main.getPosition().x;
    float y = (main.getPosition().y+(main.getSize().y));

    for (int i = 0; i < list.size(); i++)
    {
        list[i].setPosition({x,y});
        y += main.getSize().y;
    }
}

void ItemList::setSize(const Item& main)
{
    float x = main.getPosition().x;
    float y = (main.getPosition().y+(main.getSize().y));

    for (int i = 0; i < list.size(); i++)
    {
        list[i].setSize(main.getSize());
        list[i].setPosition({x,y});
        y += main.getSize().y;
    }
}

void ItemList::setTextColor(sf::Color color)
{
    for (auto & i : list)
    {
        i.setTextColor(color);
    }
}

void ItemList::setBoxColor(sf::Color color)
{
    for (auto & i : list)
    {
        i.setBoxColor(color);
    }
}