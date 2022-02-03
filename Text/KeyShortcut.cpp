//
// Created by Brandon Castro on 12/9/21.
//

#include "KeyShortcut.h"

bool KeyShortcut::isUndo() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem))
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            //std::cout << "Command Z pressed" << std::endl;
            return true;
        }
    }
    return false;
}