//
// Created by Brandon Castro on 12/7/21.
//

#include "Helper.h"

std::vector<std::string> Helper::split(std::string basicString)
{
    std::vector<std::string> strs;
    int idx = 0;
    while(basicString.length() > 0 && idx != std::string::npos)
    {
        //std::cout << "s is " << basicString << std::endl;
        idx = basicString.find('/');
        if(idx != std::string::npos)
        {
            std::string t = basicString.substr(0, idx);
            strs.push_back(t);
            basicString = basicString.substr(idx+1);

        }
    }
    strs.push_back(basicString);
    return strs;
}

std::string Helper::getTitle(std::string basicString)
{
    std::vector<std::string> hold = split(basicString);
    return hold[hold.size()-1];
}

std::string Helper::getParent(std::string basicString)
{
    std::vector<std::string> hold = split(basicString);
    hold.pop_back();
    std::string parent = "";

    for (int i = 0; i < hold.size(); i++)
    {
        parent += hold[i]+"/";
    }

    return parent;
}