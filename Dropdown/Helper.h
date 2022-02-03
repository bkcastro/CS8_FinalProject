//
// Created by Brandon Castro on 12/7/21.
//

#ifndef CS8_FINALPROJECT_HELPER_H
#define CS8_FINALPROJECT_HELPER_H
#include <string>
#include <vector>

class Helper {
public:
    static std::vector<std::string> split(std::string basicString);
    static std::string getTitle(std::string basicString);
    static std::string getParent(std::string basicString);
};

#endif //CS8_FINALPROJECT_HELPER_H
