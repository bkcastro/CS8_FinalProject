//
// Created by Brandon Castro on 12/7/21.
//

#include "Algorithms.h"

Algorithms::Algorithms() {}


void Algorithms::setPlay(bool boo) {
    play = boo;
}

bool Algorithms::getPlay() const {
    return play;
}

void Algorithms::setAlgorithm(AlgorithmsStates state) {
    // reset algorithms
    switch (current) {
        case SELECTIONSORT : selection.reset();
        break;
        case MERGESORT :
            break;
        case BUBBLESORT :   bubble.reset();
            break;
        default:
            break;
    }

    current = state;
}

void Algorithms::sort(Grid& grid) {

    switch (current) {
        case SELECTIONSORT :
            if (!selection.checkSorted())
            {
                selection.sort(grid);
            }
            break;
        case MERGESORT :
            break;
        case BUBBLESORT :
            if(!bubble.checkSorted())
            {
                bubble.sort(grid);
            }
            break;
        default:
            break;
    }
}

void Algorithms::setTargetColor(sf::Color color) {
    targetColor = color;
    selection.setTargetColor(color);
    bubble.setTargetColor(color);
}

void Algorithms::setBarColor(sf::Color color) {
    barColor = color;
    selection.setBarColor(color);
    bubble.setBarColor(color);
}

void Algorithms::restAlgorithms()
{
    switch (current) {
        case SELECTIONSORT : selection.reset();
            break;
        case MERGESORT :
            break;
        case BUBBLESORT :   bubble.reset();
            break;
        default:
            break;
    }
}

void Algorithms::restAlgorithms(Grid& grid)
{
    switch (current) {
        case SELECTIONSORT : selection.reset(grid);
            break;
        case MERGESORT :
            break;
        case BUBBLESORT :   bubble.reset(grid);
            break;
        default:
            break;
    }
}

