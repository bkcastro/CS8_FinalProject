//
// Created by Brandon Castro on 12/8/21.
//

#ifndef CS8_FINALPROJECT_CONTAINMENUS_H
#define CS8_FINALPROJECT_CONTAINMENUS_H
#include "../Tools/PlayButton.h"
#include "DropdownMenu.h"
#include "MenuBar.h"
#include "../Tools/Colors.h"
#include "FileTree.h"
#include "../Tools/Slider.h"
#include "../Tools/ColorPicker.h"
#include "../Text/TextBox.h"
#include "../Delay.h"

class ContainMenus : public sf::Drawable{
private:
    DropdownMenu algorithms;
    MenuBox files;
    MenuBox system;

    PlayButton playButton;
    Slider delay;
    Slider width;

    ColorPicker colorPicker;

    TextBox textBox;

public:
    ContainMenus();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //CS8_FINALPROJECT_CONTAINMENUS_H
