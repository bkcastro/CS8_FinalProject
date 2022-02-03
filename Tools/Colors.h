//
// Created by Brandon Castro on 12/2/21.
//

#ifndef CS8_FINALPROJECT_COLORS_H
#define CS8_FINALPROJECT_COLORS_H
#include <SFML/Graphics.hpp>

class Colors {
public:
    enum color
    {
        YELLOW = 0, BLACK, GRAY, LAST
    };

    static sf::Color getColor(color color);
};


#endif //CS8_FINALPROJECT_COLORS_H
