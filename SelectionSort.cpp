//
// Created by Brandon Castro on 11/29/21.
//

#include "SelectionSort.h"

int SelectionSort::i = 0;
int SelectionSort::j = i+1;
int SelectionSort::hold = i;
bool SelectionSort::sorted = false;

void SelectionSort::sort(Grid& grid)
{

    if (i < grid.getSize())
    {

        if (grid.getGrid()[j-1].getFillColor() == sf::Color::Red)
        {
            grid.getGrid()[j-1].setFillColor(sf::Color::Blue);
        }

        if (grid.getGrid()[i].getFillColor() != sf::Color::Red)
        {
            grid.getGrid()[i].setFillColor(sf::Color::Red);
        }

        if (j < grid.getSize())
        {
            grid.getGrid()[j].setFillColor(sf::Color::Red);

            if(grid.getGrid()[j].getValue() < grid.getGrid()[hold].getValue())
            {
                hold = j;
            }

            j++;
        }
        else
        {
            swap(&grid.getGrid()[hold], &grid.getGrid()[i]);

            grid.getGrid()[i].setFillColor(sf::Color::Blue);
            grid.getGrid()[hold].setFillColor(sf::Color::Blue);

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
            if(grid.getGrid()[j].getValue() < grid.getGrid()[hold].getValue())
            {
                hold = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(&grid.getGrid()[hold], &grid.getGrid()[i]);
        i++;
    }
    else
    {
        sorted = true;
    }
}

bool SelectionSort::getState()
{
    return sorted;
}
void SelectionSort::swap(Bar *num1, Bar *num2)
{
    sf::Vector2f location1 = num1->getPosition();
    sf::Vector2f location2 = num2->getPosition();

    Bar temp = *num1;
    *num1 = *num2;
    *num2 = temp;

    num1->setPosition(location1);
    num2->setPosition(location2);
}