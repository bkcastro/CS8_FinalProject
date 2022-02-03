//
// Created by Brandon Castro on 12/9/21.
//

#ifndef CS8_FINALPROJECT_TASKSNAPSHOT_H
#define CS8_FINALPROJECT_TASKSNAPSHOT_H
#include "TaskObjects.h"
#include <SFML/Graphics.hpp>
#include "AlgorithmStates.h"

 struct TaskSnapshot {
    TaskObjects task;

    bool shuffle;
    bool randomize;
    bool play;
    float delay;
    float width;
    std::string directory;
    std::string maxSize;
    sf::Color color;
    AlgorithmsStates algor;
};


#endif //CS8_FINALPROJECT_TASKSNAPSHOT_H
