//
// Created by Brandon Castro on 12/7/21.
//

#include "MenuBar.h"
#include <utility>

MenuBar::MenuBar() {}

void MenuBar::add(const std::string& title)
{
    MenuBox temp;

    float x = position.x+(size.x*(static_cast<float>(bar.size())));
    float y = position.y;

    temp.setSize({size});
    temp.setPosition({x,y});

    temp.setText(title);

    bar[title] = temp;
}

void MenuBar::addToBar(const std::string& title, std::string recipient) {
    bar[title].add(std::move(recipient));
}

void MenuBar::setPosition(sf::Vector2f newPosition){
    position = newPosition;

    float x = position.x;
    float y = position.y;

    for(auto iter = bar.begin(); iter!=bar.end(); ++iter)
    {
        iter->second.setPosition({x,y});
        x += size.x;
    }
}

void MenuBar::setSize(sf::Vector2f newSize) {
    size = newSize;

    float x = position.x;
    float y = position.y;

    for(auto iter = bar.begin(); iter!=bar.end(); ++iter)
    {
        iter->second.setSize(size);
        iter->second.setPosition({x,y});

        x += newSize.x;
    }
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    for(auto iter = bar.begin(); iter!=bar.end(); ++iter)
    {
        window.draw(iter->second);
    }
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for(auto iter = bar.begin(); iter!=bar.end(); ++iter)
    {
        iter->second.addEventHandler(window,event);
    }
}

void MenuBar::update() {
    for(auto iter = bar.begin(); iter!=bar.end(); ++iter)
    {
        iter->second.update();
    }
}