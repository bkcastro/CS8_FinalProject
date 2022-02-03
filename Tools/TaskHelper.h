//
// Created by Brandon Castro on 12/9/21.
//

#ifndef CS8_FINALPROJECT_TASKHELPER_H
#define CS8_FINALPROJECT_TASKHELPER_H
#include "TaskSnapshot.h"
#include "AlgorithmStates.h"
#include <string>

class TaskHelper {
public:
    static void convert(TaskSnapshot& snap);
    static void convert(const float& num, TaskSnapshot& snap);
    static void convert(const bool& boo, TaskSnapshot& snap);
    static void convert(const sf::Color& color, TaskSnapshot& snap);
    static void convert(const std::string& str, TaskSnapshot& snap);
    static bool is_number(const std::string& str);
    static AlgorithmsStates string_To_Algor(const std::string& str);

};


#endif //CS8_FINALPROJECT_TASKHELPER_H
