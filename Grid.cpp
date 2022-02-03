//
// Created by Brandon Castro on 11/28/21.
//

#include "Grid.h"

Grid::Grid() : Grid(0){}

Grid::Grid(int value)
{
    size = value;
    Randomize(value);

    min.setString(std::to_string(minimum));
    min.setOrigin({min.getGlobalBounds().width, min.getGlobalBounds().height});
    min.setPosition(background.getPosition().x-5, background.getPosition().y);
}

void Grid::changeValue(int index, float value)
{
    grid[index].setValue(value);
}

void Grid::Shuffle()
{
    std::random_shuffle(gridValues.begin(), gridValues.end());

    for (int i = 0; i < gridValues.size(); i++)
    {
        //std::cout << gridValues[i] << " " << std::endl;
        grid[i].setValue(gridValues[i]);
    }
}

void Grid::setWidth(float num)
{
    width = num;
    for (int i = 0; i < gridValues.size(); i++)
    {
        grid[i].setWidth(num);
    }
}

void Grid::setColor(sf::Color color)
{
    for (int i = 0; i < gridValues.size(); i++)
    {
        grid[i].setFillColor(color);
    }
}

void Grid::Randomize()
{
    Randomize(size);
}

void Grid::Randomize(int num)
{
    size = num;
    sf::Vector2f pos = background.getPosition();
    width = 2000/static_cast<float>(num);
    grid.clear();

    for (int i = 0; i < num; i++)
    {
        int num = rand()%980+10;

        Bar bar(static_cast<float>(num));
        bar.setPosition({pos.x, pos.y-num});
        bar.setWidth(width);

        grid.push_back(bar);
        gridValues.push_back(static_cast<float>(num));
        pos.x += width;
    }
}

void Grid::add()
{
    int ran = rand()%980+10;
    add(static_cast<float>(ran));
}

void Grid::add(float num)
{

    size++;
    sf::Vector2f pos = background.getPosition();
    float displacement = 2000/static_cast<float>(size);

    Bar bar(static_cast<float>(num));
    bar.setPosition({pos.x, pos.y-num});
    bar.setWidth(width);

    grid.push_back(bar);
    gridValues.push_back(num);

    if (width > displacement)
    {
        width = displacement;
    }

    for (int i = 0; i < size; i++)
    {
        grid[i].setPosition({pos.x, grid[i].getPosition().y});
        grid[i].setWidth(width);
        pos.x += displacement;
    }
}

void Grid::pop()
{
    size--;
    sf::Vector2f pos = background.getPosition();
    float displacement = 2000/static_cast<float>(size);


    grid.pop_back();
    gridValues.pop_back();

    for (int i = 0; i < size; i++)
    {
        grid[i].setPosition({pos.x, grid[i].getPosition().y});
        //grid[i].setWidth(width);
        pos.x += displacement;
    }
}

void Grid::clear()
{
    grid.clear();
    gridValues.clear();
    size = 0;
}



void Grid::updateMaxSize(int num)
{
    if (num > size)
    {
        for (int i = 0; i < num; i++)
        {
            add();
        }
    }
    else if (num < size)
    {
        int diff = size - num;

        for (int i = 0; i < diff; i++)
        {
            pop();
        }
    }
}

void Grid::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(background);
    window.draw(min);
    window.draw(max);
    window.draw(mid);

    for (int i = 0; i < grid.size(); i++)
    {
        window.draw(grid[i]);
        window.draw(grid[i]);
    }
}

void Grid::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Grid::update() {

}

std::vector<Bar> &Grid::getGrid() {
    return grid;
}

int Grid::getSize() const
{
    return size;
}

std::vector<float>& Grid::getValues()
{
    return gridValues;
}

std::vector<float> Grid::getValues() const {
    return gridValues;
}
