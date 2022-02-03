//
// Created by Brandon Castro on 11/29/21.
//

#ifndef CS8_FINALPROJECT_SELECTIONSORT_H
#define CS8_FINALPROJECT_SELECTIONSORT_H
#include "Grid.h"

class SelectionSort {
private:
    int i = 0;
    int j = i+1;
    int hold = i;
    bool sorted = false;

    sf::Color targetColor = sf::Color::Red;
    sf::Color barColor;

public:
    SelectionSort();

    void setTargetColor(sf::Color color);
    void setBarColor(sf::Color color);

    bool checkSorted() const;
    void sort(Grid& grid);
    void sortFaster(Grid& grid);
    void swap(Bar* bar1, Bar* bar2, float* num1, float* num2);
    void reset();
    void reset(Grid& grid);
};



#endif //CS8_FINALPROJECT_SELECTIONSORT_H
