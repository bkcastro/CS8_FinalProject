//
// Created by Brandon Castro on 12/7/21.
//

#include "Item.h"


Item::Item() {

}

void Item::setPosition(sf::Vector2f position) {
    box.setPosition(position);

    sf::FloatRect textSize = text.getGlobalBounds();

    float x = textSize.width/2;
    float y = (textSize.height/2)+5;

    text.setOrigin({x,y});

    x = position.x + (box.getSize().x/2);
    y = position.y + (box.getSize().y/2);

    text.setPosition({x,y});
}

void Item::setSize(sf::Vector2f size) {
    box.setSize(size);
    setPosition(box.getPosition());
}

void Item::setText(std::string data) {
    text.setString(data);

    sf::FloatRect textSize = text.getGlobalBounds();

    float x = textSize.width/2;
    float y = (textSize.height/2)+5;

    text.setOrigin({x,y});
}

std::string Item::getText() const {
    return text.getString();
}

sf::Vector2f Item::getPosition() const {
    return box.getPosition();
}

sf::Vector2f Item::getSize() const {
    return box.getSize();
}

sf::FloatRect Item::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    if (!States::checkState(HIDDEN))
    {
        window.draw(box);
        window.draw(text);
    }
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    if (MouseEvents<Box>::hovered(box, window))
    {
        States::enableState(HIGHLIGHTED);

        if(MouseEvents<Box>::mouseClicked(box, window) && object != NONE)
        {
            std::cout << "Clicked" << std::endl;
            TaskSnapshot temp;
            temp.task = object;
            TaskHelper::convert(text.getString(),temp);

            // Push to stack
            Task::toDoList.push(temp);
        }
    }
    else
    {
        States::disableState(HIGHLIGHTED);
    }
}

void Item::update() {
    if (States::checkState(HIGHLIGHTED))
    {
        box.setFillColor(sf::Color::Magenta);
        text.setScale({1.1,1.1});
    }
    else
    {
        box.setFillColor(sf::Color::White);
        text.setScale({1,1});
    }
}

sf::Vector2f Item::getFitSize (std::string str)
{
    Letter test;
    test.setString(str);

    sf::FloatRect testbounds = test.getLocalBounds();

    sf::Vector2f temp;
    temp.x = test.getGlobalBounds().width+20;
    temp.y = 50;

    return temp;
}

void Item::activateBorder()
{
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(1);
}

void Item::deactivateBorder()
{
    box.setOutlineThickness(0);
}

void Item::setBoxColor(sf::Color color)
{
    box.setFillColor(color);
}

void Item::setTextColor(sf::Color color)
{
    text.setFillColor(color);
}

sf::Color Item::getTextColor() const
{
    return text.getFillColor();
}

sf::Color Item::getBoxColor() const
{
    return box.getFillColor();
}

void Item::setTask(TaskObjects obj)
{
    object = obj;
}

TaskObjects Item::getTask() const {return object;}