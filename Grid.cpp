//
// Created by Brandon Castro on 11/28/21.
//

#include "Grid.h"

Grid::Grid() : Grid(20){}

Grid::Grid(int value)
{
    sf::Vector2f pos = background.getPosition();

    width = 2000/static_cast<float>(value);

    for (int i = 0; i < value; i++)
    {
        int num = rand()%800+10;

        Bar bar(static_cast<float>(num));
        bar.setPosition(pos);
        bar.setWidth(width);

        grid.push_back(bar);

        pos.x += width;
    }
}

void Grid::Shuffle() {

}

void Grid::Randomize() {

}

void Grid::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(background);

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
    return grid.size();
}
