//
// Created by Brandon Castro on 12/8/21.
//

#ifndef CS8_FINALPROJECT_COLORPICKER_H
#define CS8_FINALPROJECT_COLORPICKER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Box.h"
#include "Task.h"
#include "MouseEvents.h"
#include "../Text/Letter.h"

class ColorPicker : public sf::Drawable{
private:
    std::vector<sf::Color> colors;
    std::vector<Box> grid;
    sf::Color current = sf::Color::Yellow;
    float paddingV = 5;
    float paddingH = 5;

    Letter title;
    TaskObjects function;
public:
    ColorPicker();

    void setPosition(sf::Vector2f pos);
    void setTask(TaskObjects obj);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);

};


#endif //CS8_FINALPROJECT_COLORPICKER_H
