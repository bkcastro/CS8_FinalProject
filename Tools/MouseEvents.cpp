//
// Created by Brandon Castro on 12/6/21.
//

#ifndef CS8_FINALPROJECT_MOUSEEVENTS_CPP
#define CS8_FINALPROJECT_MOUSEEVENTS_CPP
#include "MouseEvents.h"

template<class T>
sf::Clock MouseEvents<T>::clock;

template<class T>
int MouseEvents<T>::clicks = 0;

template<class T>
void MouseEvents<T>::countClicks(sf::Event event)
{

}

// call this after you called mouse clicked with window and event parameters
template<class T>
bool MouseEvents<T>::mouseClicked(const T& object, sf::RenderWindow& window)
{
    sf::Vector2f mPos = (sf::Vector2f ) sf::Mouse::getPosition(window);
    sf::FloatRect bounds = object.getGlobalBounds();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (bounds.contains(mPos))
        {
            return true;
        }
    }

    return false;
}

// returns true if the mouse clicks anywhere in the window
template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow& window, sf::Event event)
{
    if (clock.getElapsedTime().asSeconds() > 1)
    {
        clicks = 0;
    }

    sf::Vector2i mPos = sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {

        clicks++;
        clock.restart();

        return true;
    }
    return false;
}

// returns true if the mouse has been double clicked use with mouseClicked with windows and event parameters
template<class T>
bool MouseEvents<T>::mouseDoubleClicked()
{
    if (clicks == 2)
    {
        std::cout << "Double clicked" << std::endl;
        clicks = 0;
        return true;
    }

    return false;
}

//returns true if the mouse has been triple clicked use with mouseClicked with windows and event parameters
template<class T>
bool MouseEvents<T>::mouseTripleClicked()
{
    if (clicks == 3) {
        std::cout << "Triple clicked" << std::endl;
        clicks = 0;
        return true;
    }

    return false;
}


// returns if the object has been clicked and the mouse has dragged over the object
template<class T>
bool MouseEvents<T>::draggedOver(const T& object, sf::RenderWindow& window, sf::Event event)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (hovered(object, window))
        {
            return true;
        }
    }
    return false;
}

// returns tru if the mouse is hovered over the object
// same as mouseClick object just make sure to use wisely
template<class T>
bool MouseEvents<T>::hovered(const T& object, sf::RenderWindow& window)
{
    sf::Vector2f mPos = (sf::Vector2f ) sf::Mouse::getPosition(window);
    sf::FloatRect bounds = object.getGlobalBounds();

    if (bounds.contains(mPos))
    {
        return true;
    }

    return false;
}

#endif
