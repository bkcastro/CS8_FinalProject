//
// Created by Brandon Castro on 11/28/21.
//

#ifndef CS8_FINALPROJECT_GRID_H
#define CS8_FINALPROJECT_GRID_H
#include <vector>
#include "Bar.h"
#include "GridBox.h"
#include "Text/Letter.h"
#include <vector>
#include <algorithm>
#include <string>

class Grid: public sf::Drawable {
private:
    std::vector<Bar> grid;
    std::vector<float> gridValues;
    GridBox background;
    int size;
    float width;
    int maximum = 0;
    int minimum = 0;

    Letter min;
    Letter max;
    Letter mid;

public:
    Grid();
    Grid(int value);

    std::vector<Bar>& getGrid();
    std::vector<float>& getValues();
    std::vector<float> getValues() const;
    void changeValue(int index, float value);

    void Shuffle();
    void Randomize();
    void Randomize(int num);
    void setWidth(float num);
    void setColor(sf::Color color);
    void pop();
    void clear();
    void add();
    void add(float num);
    void updateMaxSize(int num);

    int getSize() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    void update();
};


#endif //CS8_FINALPROJECT_GRID_H
