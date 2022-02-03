//
// Created by Brandon Castro on 12/7/21.
//

#ifndef CS8_FINALPROJECT_MENUBAR_H
#define CS8_FINALPROJECT_MENUBAR_H
#include "MenuBox.h"

class MenuBar : public sf::Drawable {
private:
    std::map<std::string, MenuBox> bar;

    sf::Vector2f size = {200, 50};
    sf::Vector2f position = {0,0}; // default;

public:
    MenuBar();



    void add(const std::string& title);
    void addToBar(const std::string& title, std::string recipient);

    void setPosition(sf::Vector2f newPosition);
    void setSize(sf::Vector2f newSize); // sets the size of each individual box

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //CS8_FINALPROJECT_MENUBAR_H
