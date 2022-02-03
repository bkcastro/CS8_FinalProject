//
// Created by Brandon Castro on 12/7/21.
//

#ifndef CS8_FINALPROJECT_DROPDOWNMENU_H
#define CS8_FINALPROJECT_DROPDOWNMENU_H
#include "ItemList.h"


class DropdownMenu : public sf::Drawable{
private:
    ItemList list;
    Item main;

public:
    DropdownMenu();

    void add(std::string title, TaskObjects objects);
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    void setTextColor(sf::Color color);
    void setBoxColor(sf::Color color);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};

#endif //CS8_FINALPROJECT_DROPDOWNMENU_H
