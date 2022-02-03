//
// Created by Brandon Castro on 12/2/21.
//

#ifndef CS8_FINALPROJECT_MENU_H
#define CS8_FINALPROJECT_MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Images/Images.h"
#include "Text/HighLightText.h"
#include "Tools/Colors.h"

class Menu {
private:
    bool active = true;

public:
    Menu();

    bool checkActive();
    void run();
};

#endif //CS8_FINALPROJECT_MENU_H
