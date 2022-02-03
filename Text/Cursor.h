//
// Created by Brandon Castro on 12/9/21.
//

#ifndef CS8_FINALPROJECT_CURSOR_H
#define CS8_FINALPROJECT_CURSOR_H
#include <SFML/System.hpp>
#include "Letter.h"
#include "../Tools/States.h"

class Cursor : public sf::Drawable, public States{
private:

    Letter cursor;
    sf::Clock clock;

public:
    Cursor();

    void update();
    void setPosition(sf::Vector2f pos);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif //CS8_FINALPROJECT_CURSOR_H
