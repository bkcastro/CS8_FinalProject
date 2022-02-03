//
// Created by Brandon Castro on 12/6/21.
//

#ifndef CS8_FINALPROJECT_HIGHLIGHTTEXT_H
#define CS8_FINALPROJECT_HIGHLIGHTTEXT_H
#include "Letter.h"
#include "../Tools/MouseEvents.h"
#include "../Tools/States.h"
// This class it just like letter but a line underlines
// them when the mouse hovers over the letter
class HighLightText : public sf::Drawable, public States{
private:

    Letter text;
    sf::RectangleShape line; // this line it under the text
    float thickness = 2;
    void updateLine();
public:

    enum Locations
    {
        LEFT,
        CENTER,
        RIGHT
    };

    HighLightText();
    HighLightText(std::string text);

    void setPosition(sf::Vector2f pos);
    void setOrigin(Locations loc);
    void setString(std::string text);
    void setFillColor(sf::Color color);
    bool checkCLick(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    void update();

};


#endif //CS8_FINALPROJECT_HIGHLIGHTTEXT_H
