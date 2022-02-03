//
// Created by Brandon Castro on 12/9/21.
//

#ifndef CS8_FINALPROJECT_TASK_H
#define CS8_FINALPROJECT_TASK_H
#include "TaskSnapshot.h"
#include "TaskHelper.h"
#include <queue>

class Task {
public:
    static std::queue<TaskSnapshot> toDoList;
};


#endif //CS8_FINALPROJECT_TASK_H
