//
// Created by Brandon Castro on 11/28/21.
//

#ifndef CS8_FINALPROJECT_BAR_H
#define CS8_FINALPROJECT_BAR_H
#include <SFML/Graphics.hpp>
#include "Box.h"

class Bar : public Box{
private:
    float width;
    float value;

public:
    Bar();
    Bar(float data);

    void setValue(float data);
    void setWidth(float data);
    float getValue() const;
};


#endif //CS8_FINALPROJECT_BAR_H
