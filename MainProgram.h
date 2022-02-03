//
// Created by Brandon Castro on 12/6/21.
//

#ifndef CS8_FINALPROJECT_MAINPROGRAM_H
#define CS8_FINALPROJECT_MAINPROGRAM_H
#include "Grid.h"
#include "Delay.h"
#include "SelectionSort.h"
#include "Tools/Colors.h"
#include "Dropdown/ContainMenus.h"
#include "Algorithms.h"
#include "FileInterface.h"

class MainProgram {
private:
    Grid stage;
    Algorithms algorithms;
    FileInterface interface;
public:
    MainProgram();

    void run();
    void update();
};


#endif //CS8_FINALPROJECT_MAINPROGRAM_H
