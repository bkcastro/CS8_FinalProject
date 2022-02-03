//
// Created by Brandon Castro on 12/7/21.
//

#ifndef CS8_FINALPROJECT_ALGORITHMS_H
#define CS8_FINALPROJECT_ALGORITHMS_H
#include "Grid.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "BubbleSort.h"
#include "Tools/Task.h"
#include "Tools/AlgorithmStates.h"

class Algorithms {
private:
    bool play = false;
    AlgorithmsStates current;
    SelectionSort selection;
    //MergeSort merge;
    BubbleSort bubble;

    sf::Color barColor;
    sf::Color targetColor = sf::Color::Red;
public:

    Algorithms();

    void setTargetColor(sf::Color color);
    void setBarColor(sf::Color color);

    void restAlgorithms();
    void restAlgorithms(Grid& grid);
    void setAlgorithm(AlgorithmsStates state);
    void sort(Grid& grid);
    void setPlay(bool boo);
    bool getPlay() const;
};


#endif //CS8_FINALPROJECT_ALGORITHMS_H
