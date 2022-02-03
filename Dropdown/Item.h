//
// Created by Brandon Castro on 12/7/21.
//

#ifndef CS8_FINALPROJECT_ITEM_H
#define CS8_FINALPROJECT_ITEM_H
#include "../Tools/Box.h"
#include "../Text/Letter.h"
#include "../Tools/MouseEvents.h"
#include "../Tools/States.h"
#include "../Tools/Task.h"
#include <iostream>
#include "../Tools/Task.h"

class Item : public sf::Drawable , public States {
private:
    Letter text;
    Box box;
    TaskObjects object = NONE;

public:
    Item();

    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    void setText(std::string data);
    void activateBorder();
    void deactivateBorder();
    void setBoxColor(sf::Color color);
    void setTextColor(sf::Color color);
    void setTask(TaskObjects obj);
    TaskObjects getTask() const;
    sf::Color getTextColor() const;
    sf::Color getBoxColor() const;

    std::string getText() const;

    virtual sf::Vector2f getPosition() const;

    virtual sf::Vector2f getSize() const;
    static sf::Vector2f getFitSize (std::string str);

    virtual sf::FloatRect getGlobalBounds() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};

#endif //CS8_FINALPROJECT_ITEM_H
