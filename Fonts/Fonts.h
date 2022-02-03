//
// Created by Brandon Castro on 12/2/21.
//

#ifndef CS8_FINALPROJECT_FONTS_H
#define CS8_FINALPROJECT_FONTS_H
#include "SFML/Graphics.hpp"

class Fonts
{
private:
    static sf::Font font;
    static bool loaded;
    static void loadFont();
public:
    static sf::Font& getFont();
};

#endif //CS8_FINALPROJECT_FONTS_H
