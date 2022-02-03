//
// Created by Brandon Castro on 12/10/21.
//

#ifndef CS8_FINALPROJECT_BUBBLESORT_H
#define CS8_FINALPROJECT_BUBBLESORT_H
#include "Grid.h"

class BubbleSort {
private:
    int i = 1;
    int j = 0;
    bool sorted = false;

    sf::Color targetColor = sf::Color::Red;
    sf::Color barColor;
public:
    BubbleSort();

    void setTargetColor(sf::Color color);
    void setBarColor(sf::Color color);

    bool checkSorted() const;
    void sort(Grid& grid);
    void sortFaster(Grid& grid);
    void swap(Bar* bar1, Bar* bar2, float* num1, float* num2);
    void reset();
    void reset(Grid& grid);
};


#endif //CS8_FINALPROJECT_BUBBLESORT_H
