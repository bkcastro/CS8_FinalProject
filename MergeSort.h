//
// Created by Brandon Castro on 12/10/21.
//

#ifndef CS8_FINALPROJECT_MERGESORT_H
#define CS8_FINALPROJECT_MERGESORT_H
#include "Grid.h"

class MergeSort {
private:
    bool sorted = false;

public:
    MergeSort();

    void sort(Grid& grid);
    void sortFaster(Grid& grid);
    void swap(Bar* num1, Bar* num2);
    bool getState();
    void reset();
};


#endif //CS8_FINALPROJECT_MERGESORT_H
