//
// Created by Brandon Castro on 12/2/21.
//

#include "Letter.h"

Letter::Letter()
{
    this->setFont(Fonts::getFont());
    this->setFillColor(sf::Color::Black);
}

Letter::Letter(char c)
{
    this->setString(c);
    this->setFont(Fonts::getFont());
    this->setFillColor(sf::Color::Black);
}