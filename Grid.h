//
// Created by Brandon Castro on 11/28/21.
//

#ifndef CS8_FINALPROJECT_GRID_H
#define CS8_FINALPROJECT_GRID_H
#include "Bar.h"
#include "GridBox.h"
#include <vector>

class Grid: public sf::Drawable {
private:
    std::vector<Bar> grid;
    GridBox background;
    float width;

public:
    Grid();
    Grid(int value);

    void Shuffle();
    void Randomize();

    std::vector<Bar>& getGrid();
    int getSize() const;
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    void update();
};


#endif //CS8_FINALPROJECT_GRID_H
