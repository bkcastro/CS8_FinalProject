//
// Created by Brandon Castro on 12/8/21.
//

#include "Slider.h"

Slider::Slider() {
    line.setSize({500, 5});
    line.setPosition({10,70});
    line.setFillColor(sf::Color::Black);

    dial.setRadius(10);
    dial.setOrigin({10,10});
    dial.setFillColor(Colors::getColor(Colors::YELLOW));
    dial.setPosition({line.getPosition().x+line.getGlobalBounds().width/2, line.getPosition().y+line.getGlobalBounds().height/2});

    current.setString(std::to_string(currentValue));
    current.setOrigin({0, current.getGlobalBounds().height/2+3});
    current.setPosition({line.getPosition().x+line.getGlobalBounds().width+5,line.getPosition().y-5});
}

void Slider::setPosition(sf::Vector2f pos) {
    title.setPosition(pos);
    line.setPosition({pos.x+title.getGlobalBounds().width, pos.y});
    dial.setPosition({line.getPosition().x+line.getGlobalBounds().width/2, line.getPosition().y+line.getGlobalBounds().height/2});
    current.setPosition({line.getPosition().x+line.getGlobalBounds().width+5,title.getPosition().y});

    float c = line.getPosition().x;
    float a = dial.getPosition().x-c;
    float b = line.getPosition().x+line.getGlobalBounds().width-c;

    std::cout << c << " " << a << " " << b << std::endl;
}

void Slider::setSize(float x) {
    line.setSize({x, line.getSize().y});
    dial.setPosition({line.getPosition().x+line.getGlobalBounds().width/2, line.getPosition().y+line.getGlobalBounds().height/2});
    current.setPosition({line.getPosition().x+line.getGlobalBounds().width+5,title.getPosition().y});
}

void Slider::setTitle(std::string str)
{
    str += ":  ";
    title.setString(str);
    title.setOrigin({0, title.getGlobalBounds().height/2+3});
    setPosition(line.getPosition());
}

void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(title);
    window.draw(line);
    window.draw(dial);
    window.draw(current);
}

void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && dial.getGlobalBounds().contains(mpos))
    {
        dragging = true;
    }
    else if (dragging && event.type == sf::Event::MouseButtonReleased)
    {
        dragging = false;
    }

    if (dragging)
    {
        move(window);
    }
}

void Slider::move(sf::RenderWindow &window)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    if (mpos.x < line.getPosition().x+line.getSize().x && mpos.x >= line.getPosition().x)
    {
        dial.setPosition({mpos.x, dial.getPosition().y});

        float c = line.getPosition().x;
        float a = dial.getPosition().x-c;
        float b = line.getPosition().x+line.getGlobalBounds().width-c;
        float d = (maxValue-minValue)/(b/a);
        d += minValue;

        currentValue = d;
        current.setString(std::to_string(d));
    }
    else if (mpos.x <= line.getPosition().x)
    {
        currentValue = minValue;
        current.setString(std::to_string(minValue));
    }
    else if (mpos.x >= line.getPosition().x+line.getSize().x)
    {
        currentValue = maxValue;
        current.setString(std::to_string(maxValue));
    }

    TaskSnapshot temp;
    temp.task = object;
    TaskHelper::convert(currentValue, temp);
    Task::toDoList.push(temp);
}

float Slider::getValue() const
{
return currentValue;
}

void Slider::setMin(float num)
{
    minValue = num;

    float h = (maxValue-minValue)/2;
    h+= minValue;

    current.setString(std::to_string(h));
    currentValue = h;

    float a = currentValue/(maxValue+minValue);
    float b = line.getPosition().x;
    float c = line.getPosition().x+line.getGlobalBounds().width-b;
    float d = a*c;

    dial.setPosition({b+d, dial.getPosition().y});
}

void Slider::setMax(float num)
{
    maxValue = num;

    float h = (maxValue-minValue)/2;
    h+= minValue;

    current.setString(std::to_string(h));
    currentValue = h;

    float a = currentValue/(maxValue+minValue);
    float b = line.getPosition().x;
    float c = line.getPosition().x+line.getGlobalBounds().width-b;
    float d = a*c;

    dial.setPosition({b+d, dial.getPosition().y});
}

void Slider::setTask(TaskObjects obj)
{
    object = obj;
}