//
// Created by Brandon Castro on 11/29/21.
//

#include "SelectionSort.h"

SelectionSort::SelectionSort() {}

void SelectionSort::sort(Grid& grid)
{

    if (i < grid.getSize())
    {

        if (grid.getGrid()[j-1].getFillColor() == targetColor)
        {
            grid.getGrid()[j-1].setFillColor(barColor);
        }

        if (grid.getGrid()[i].getFillColor() != targetColor)
        {
            grid.getGrid()[i].setFillColor(targetColor);
        }

        if (j < grid.getSize())
        {
            grid.getGrid()[j].setFillColor(targetColor);

            if(grid.getGrid()[j].getValue() < grid.getGrid()[hold].getValue())
            {
                hold = j;
            }

            j++;
        }
        else
        {
            swap(&grid.getGrid()[hold], &grid.getGrid()[i], &grid.getValues()[hold], &grid.getValues()[i]);

            grid.getGrid()[i].setFillColor(barColor);
            grid.getGrid()[hold].setFillColor(barColor);

            i++;

            j = i+1;

            hold = i;
        }
    }
    else
    {
        sorted = true;
    }
}

void SelectionSort::sortFaster(Grid& grid)
{
    if (i < grid.getSize())
    {
//        if (i-1 >= 0)
//        {
//            if (grid.getGrid()[i-1].getFillColor() == sf::Color::Red)
//            {
//                grid.getGrid()[i-1].setFillColor(sf::Color::Blue);
//            }
//        }


        hold = i;
        for (j = i+1; j < grid.getSize(); j++)
        {
            if(grid.getValues()[j] < grid.getValues()[hold])
            {
                hold = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(&grid.getGrid()[hold], &grid.getGrid()[i], &grid.getValues()[hold], &grid.getValues()[i]);
        i++;
    }
    else
    {
        sorted = true;
    }
}

void SelectionSort::swap(Bar* bar1, Bar* bar2, float* num1, float* num2)
{
    float value1 = *num1;
    float value2 = *num2;

    bar1->setValue(value2);
    bar2->setValue(value1);

    float temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void SelectionSort::reset() {
    i = 0;
    j = i+1;
    hold = i;
    sorted = false;
}

void SelectionSort::reset(Grid& grid) {
    reset();
    grid.setColor(barColor);
}

void SelectionSort::setTargetColor(sf::Color color) {
    targetColor = color;
}

void SelectionSort::setBarColor(sf::Color color) {
    barColor = color;
}

bool SelectionSort::checkSorted() const {return sorted;}
