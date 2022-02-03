//
// Created by Brandon Castro on 12/6/21.
//

#ifndef CS8_FINALPROJECT_STATES_H
#define CS8_FINALPROJECT_STATES_H
#include <map>
#include "ObjectStates.h"

class States {

private:
    std::map<ObjectStates, bool> states;

public:
    States();
    bool checkState(ObjectStates state) const;
    void disableState(ObjectStates state);
    void enableState(ObjectStates state);
};

#endif //CS8_FINALPROJECT_STATES_H
