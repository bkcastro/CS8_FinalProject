//
// Created by Brandon Castro on 12/9/21.
//

#include "Cursor.h"

Cursor::Cursor()
{
    cursor.setString('|');
}

void Cursor::setPosition(sf::Vector2f pos) {
    cursor.setPosition(pos);
}

void Cursor::update()
{
    if(clock.getElapsedTime().asSeconds() > .4)
    {
        // then we toggle the color
        if(checkState(HIDDEN))
        {
            disableState(HIDDEN);
        }
        else
        {
            enableState(HIDDEN);
        }

        clock.restart();
    }

}

void Cursor::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    if(!checkState(HIDDEN))
    {
        window.draw(cursor);
    }
}
