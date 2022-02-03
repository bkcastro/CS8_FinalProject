//
// Created by Brandon Castro on 12/9/21.
//

#include "TaskHelper.h"

void TaskHelper::convert(TaskSnapshot &snap) {
    switch (snap.task) {
        case SHUFFLE: snap.shuffle = true;
        break;
        case RANDOMIZE : snap.randomize = true;
        break;
        default:
            break;
    }
}

void TaskHelper::convert(const float& num, TaskSnapshot &snap)
{
    switch (snap.task) {
        case DELAY : snap.delay = num;
        break;
        case WIDTH : snap.width = num;
        break;
        default:
            break;
    }
}

void TaskHelper::convert(const bool &boo, TaskSnapshot &snap)
{
    switch (snap.task) {
        case PLAYBUTTON : snap.play = boo;
        break;
        default :
            break;
    }
}

void TaskHelper::convert(const sf::Color& color, TaskSnapshot &snap)
{
    switch (snap.task) {
        case COLOR : snap.color = color;
        break;
        default:
            break;
    }
}

void TaskHelper::convert(const std::string& str, TaskSnapshot &snap)
{
    switch (snap.task) {
        case SHUFFLE: snap.shuffle = true;
            break;
        case RANDOMIZE : snap.randomize = true;
            break;
        case MAXSIZE : snap.maxSize = str;
        break;
        case ALGORITHM : snap.algor = string_To_Algor(str);
        break;
        default :
            break;
    }
}

// straight from stack overflow lol
bool TaskHelper::is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

AlgorithmsStates TaskHelper::string_To_Algor(const std::string& str)
{
    if (str == "SelectionSort")
    {
        return SELECTIONSORT;
    }
    else if (str == "MergeSort")
    {
        return MERGESORT;
    }
    else
    {
        return BUBBLESORT;
    }
}