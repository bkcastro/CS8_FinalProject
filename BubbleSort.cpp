//
// Created by Brandon Castro on 12/10/21.
//

#include "BubbleSort.h"

BubbleSort::BubbleSort() {

}

void BubbleSort::sort(Grid &grid) {

    grid.getGrid()[i].setFillColor(barColor);
    grid.getGrid()[j].setFillColor(barColor);

    if(i < grid.getSize()-1)
    {
        if (j < grid.getSize()-1)
        {

            if (grid.getValues()[j] > grid.getValues()[j+1])
            {
                swap(&grid.getGrid()[j], &grid.getGrid()[j+1], &grid.getValues()[j], &grid.getValues()[j+1]);
            }
            j++;
        }
        else
        {
            // check flag
            i++;
            j = 0;
        }

        grid.getGrid()[i].setFillColor(targetColor);
        grid.getGrid()[j].setFillColor(targetColor);
    }
}

void BubbleSort::sortFaster(Grid &grid) {

}

void BubbleSort::setTargetColor(sf::Color color) {
    targetColor = color;
}

void BubbleSort::setBarColor(sf::Color color) {
    barColor = color;
}

bool BubbleSort::checkSorted() const {
    return sorted;
}

void BubbleSort::swap(Bar *bar1, Bar *bar2, float *num1, float *num2) {
    float value1 = *num1;
    float value2 = *num2;

    bar1->setValue(value2);
    bar2->setValue(value1);

    float temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void BubbleSort::reset() {
    i = 1;
    j = 0;
    sorted = false;
}

void BubbleSort::reset(Grid &grid) {
    reset();
    grid.setColor(barColor);
}
