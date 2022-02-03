//
// Created by Brandon Castro on 12/8/21.
//

#include "ColorPicker.h"

ColorPicker::ColorPicker() {

    title.setString("Color Picker : ");

    colors.push_back(sf::Color::Black);
    colors.push_back(sf::Color::White);
    colors.push_back(sf::Color::Blue);
    colors.push_back(sf::Color::Red);
    colors.push_back(sf::Color::Cyan);
    colors.push_back(sf::Color::Green);
    colors.push_back(sf::Color::Magenta);
    colors.push_back(sf::Color::Yellow);

    setPosition({0,0});
}

void ColorPicker::setPosition(sf::Vector2f pos)
{
    title.setPosition({pos.x, pos.y-40});
    grid.clear();
    for (int i = 0; i < colors.size(); i++)
    {
        Box temp;
        temp.setSize({100,100});
        temp.setFillColor(colors[i]);
        if (i == 0)
        {
            temp.setPosition({pos});
        }
        else if (i < 4)
        {
            temp.setPosition(grid[i-1].getPosition().x+temp.getSize().x+paddingV,grid[i-1].getPosition().y);
        }
        else if (i == 4)
        {
            temp.setPosition(grid[0].getPosition().x,grid[0].getPosition().y+temp.getSize().y+paddingV);
        }
        else
        {
            temp.setPosition(grid[i-1].getPosition().x+temp.getSize().x+paddingV,grid[i-1].getPosition().y);
        }


        grid.push_back(temp);
    }
}

void ColorPicker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(title);
    for (int i = 0; i < grid.size(); i++)
    {
        window.draw(grid[i]);
    }
}

void ColorPicker::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    for (int i = 0; i < grid.size(); i++)
    {
        if (MouseEvents<Box>::mouseClicked(grid[i], window))
        {
            TaskSnapshot temp;
            temp.task = function;
            TaskHelper::convert(grid[i].getFillColor(), temp);

            Task::toDoList.push(temp);
        }
    }
}

void ColorPicker::setTask(TaskObjects obj) {
    function = obj;
}


