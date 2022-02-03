//
// Created by Brandon Castro on 12/7/21.
//

#ifndef CS8_FINALPROJECT_ITEMLIST_H
#define CS8_FINALPROJECT_ITEMLIST_H
#include "Item.h"
#include <vector>

class ItemList : public sf::Drawable{
private:
    std::vector<Item> list;

public:
    ItemList();

    void setPosition(const Item& main);
    void setSize(const Item& main);
    void setTextColor(sf::Color color);
    void setBoxColor(sf::Color color);
    void add(std::string title, const Item& main);
    void add(std::string title, TaskObjects obj, const Item& main);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void addEventHandler(sf::RenderWindow& window, sf::Event event, Item& main);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //CS8_FINALPROJECT_ITEMLIST_H
