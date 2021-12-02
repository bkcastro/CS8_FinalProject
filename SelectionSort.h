//
// Created by Brandon Castro on 11/29/21.
//

#ifndef CS8_FINALPROJECT_SELECTIONSORT_H
#define CS8_FINALPROJECT_SELECTIONSORT_H
#include "Delay.h"
#include "Grid.h"

class SelectionSort {
private:
    static int i;
    static int j;
    static int hold;

    static bool sorted;

public:
    static void sort(Grid& grid);
    static void sortFaster(Grid& grid);
    static void swap(Bar* num1, Bar* num2);
    static bool getState();
};



#endif //CS8_FINALPROJECT_SELECTIONSORT_H
