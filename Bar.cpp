//
// Created by Brandon Castro on 11/28/21.
//

#include "Bar.h"

Bar::Bar() : Bar(0){


}

Bar::Bar(float data) {

    value = data;

    this->setFillColor(sf::Color::Blue);
    this->setSize({25,data});
    this->setOrigin(0, data);
}

void Bar::setValue(float data) {
    value = data;
}

void Bar::setWidth(float data) {

    sf::Vector2f size;
    size = this->getSize();
    size.x = data;

    this->setSize(size);
}

float Bar::getValue() const
{
    return value;
}
