//
// Created by Brandon Castro on 12/2/21.
//

#ifndef CS8_FINALPROJECT_LETTER_H
#define CS8_FINALPROJECT_LETTER_H
#include <SFML/Graphics.hpp>
#include "../Fonts/Fonts.h"
#include <string>
#include <cmath>
#include <iostream>

class Letter : public  sf::Text {
public:
    Letter();
    Letter(char c);
};

#endif //CS8_FINALPROJECT_LETTER_H
