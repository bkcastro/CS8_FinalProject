//
// Created by Brandon Castro on 12/6/21.
//

#include "HighLightText.h"

#include <utility>

HighLightText::HighLightText() : HighLightText(""){}

HighLightText::HighLightText(std::string text)
{
    setString(std::move(text));
    line.setFillColor(sf::Color::Black);
}

void HighLightText::updateLine()
{
    float width = text.getGlobalBounds().width;
    sf::Vector2f linePos;

    linePos.x = text.getPosition().x;
    linePos.y = text.getPosition().y+(text.getGlobalBounds().height);

    line.setSize({width, thickness});
    line.setOrigin({text.getOrigin().x, 0});
    line.setPosition(linePos);
}

void HighLightText::setPosition(sf::Vector2f pos)
{
    text.setPosition(pos);
    updateLine();
}

void HighLightText::setOrigin(Locations loc)
{
    sf::Vector2f position;

    if (loc == LEFT)
    {
        position = {0,0};
    }
    else if (loc == CENTER)
    {
        position.x = text.getGlobalBounds().width/2;
        position.y = text.getGlobalBounds().height/2;
    }
    else
    {
        position.x = text.getGlobalBounds().width;
        position.y = text.getGlobalBounds().height;
    }

    text.setOrigin(position);
    updateLine();
}

void HighLightText::setString(std::string text)
{
    this->text.setString(text);
    updateLine();
}

void HighLightText::setFillColor(sf::Color color)
{
    text.setFillColor(color);
}

void HighLightText::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(text);

    if (checkState(HIGHLIGHTED))
    {
        window.draw(line);
    }
}

void HighLightText::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if (MouseEvents<Letter>::hovered(text, window))
    {
        if (!checkState(HIGHLIGHTED))
        {
            enableState(HIGHLIGHTED);
        }
    }
    else
    {
        if (checkState(HIGHLIGHTED))
        {
            disableState(HIGHLIGHTED);
        }
    }
}

bool HighLightText::checkCLick(sf::RenderWindow &window, sf::Event event)
{
    if (MouseEvents<Letter>::mouseClicked(text, window))
    {
        return true;
    }

    return false;
}

void HighLightText::update()
{

}
