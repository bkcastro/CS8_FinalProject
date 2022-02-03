//
// Created by Brandon Castro on 12/9/21.
//

#ifndef CS8_FINALPROJECT_SPECIALWORDS_H
#define CS8_FINALPROJECT_SPECIALWORDS_H
#include "Letter.h"
#include "../LinkList/LinkList.h"
#include <string>

/*
 * this class changes the colors of special words
 *
 * if a dataTypes the color is set to blue
 */

class SpecialWords {
private:
    static std::string dataTypes[4];
public:

    static void parse(Linklist<Letter>& list);

};
#endif //CS8_FINALPROJECT_SPECIALWORDS_H
