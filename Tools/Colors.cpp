//
// Created by Brandon Castro on 12/2/21.
//

#include "Colors.h"

sf::Color Colors::getColor(color color)
{
    switch(color)
    {
        case YELLOW : return {242,169,59};
        case BLACK : return sf::Color::Black;
        case GRAY : return {240,238,238};
        default : return sf::Color::Black;
    }
}