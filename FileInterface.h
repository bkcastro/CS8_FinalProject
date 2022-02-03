//
// Created by Brandon Castro on 12/10/21.
//

#ifndef CS8_FINALPROJECT_FILEINTERFACE_H
#define CS8_FINALPROJECT_FILEINTERFACE_H
#include "Dropdown/FileTree.h"
#include "Tools/Box.h"
#include "Text/HighLightText.h"
#include "Images/Images.h"
#include "Tools/Colors.h"
#include "Grid.h"
#include <string>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include "Dropdown/hack.h"

class FileInterface {
private:
    sf::VideoMode windowSize = {1000, 1000};
    FileTree fileTree;

    Letter filePrompt;
    Letter currentFile;
    HighLightText import;

    void importData(Grid& grid);

public:
    FileInterface();

    void run(Grid& grid);

    std::string currentDataTime() const;
    void exportGrid(const Grid& grid);
};


#endif //CS8_FINALPROJECT_FILEINTERFACE_H
