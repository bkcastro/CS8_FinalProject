//
// Created by Brandon Castro on 12/8/21.
//

#ifndef CS8_FINALPROJECT_SLIDER_H
#define CS8_FINALPROJECT_SLIDER_H
#include <SFML/Graphics.hpp>
#include "Colors.h"
#include "../Text/Letter.h"
#include "../Tools/Task.h"

class Slider : public sf::Drawable{
private:
    TaskObjects object;

    Letter min;
    Letter current;
    Letter max;

    float minValue = 0;
    float maxValue = 100;
    float currentValue = 50;

    sf::RectangleShape line;
    sf::CircleShape dial;
    Letter title;

    bool dragging = false;
    void move(sf::RenderWindow& window);
public:
    Slider();

    float getValue() const;
    void setMin(float num);
    void setMax(float num);
    void setPosition(sf::Vector2f pos);
    void setSize(float x);
    void setTitle(std::string str);
    void setTask(TaskObjects obj);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
};


#endif //CS8_FINALPROJECT_SLIDER_H
