//
// Created by Brandon Castro on 12/9/21.
//

#include "SpecialWords.h"

std::string SpecialWords::dataTypes[4] = {"int", "char", "float", "double"};

void SpecialWords::parse(Linklist<Letter> &list) {
    Linklist<Letter>::iterator iter;
    std::string check;
    std::string current;

    for (iter = list.begin(); iter != list.end(); ++iter)
    {
        current = (*iter).getString();

        if (current != " ")
        {
            check += current;

            if (check.size() > 2)
            {

                for (int i = 0; i < 4; i++)
                {
                    if (check == dataTypes[i])
                    {
                        Linklist<Letter>::iterator hold = iter;
                        for (int j = 0; j < dataTypes[i].size(); j++)
                        {
                            (*hold).setFillColor(sf::Color::Blue);
                            --hold;
                        }
                    }
                }
            }
        }
        else
        {
            check.clear();
        }
    }
}