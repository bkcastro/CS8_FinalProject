//
// Created by Brandon Castro on 12/7/21.
//

#ifndef CS8_FINALPROJECT_MENUBOX_H
#define CS8_FINALPROJECT_MENUBOX_H
#include "DropdownMenu.h"

class MenuBox : public sf::Drawable{
private:
    ItemList list;
    Item main;
public:
    MenuBox();

    void add(std::string title);
    void add(std::string title, TaskObjects obj);
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    void setText(std::string title);
    void setTextColor(sf::Color color);
    void setBoxColor(sf::Color color);
    void setTask(std::string str, TaskObjects obj);

    sf::Vector2f getPosition() const;

    sf::Vector2f getSize() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);

    void update();
};

#endif //CS8_FINALPROJECT_MENUBOX_H
