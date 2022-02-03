//
// Created by Brandon Castro on 12/2/21.
//

#include "Fonts.h"

sf::Font Fonts::font;
bool Fonts::loaded = false;
void Fonts::loadFont()
{
    if(!loaded)
    {
        if(!font.loadFromFile("fonts/OpenSans-Bold.ttf"))
            exit(1);
        loaded = true;
    }

}

sf::Font& Fonts::getFont()
{
    loadFont();
    return font;
}