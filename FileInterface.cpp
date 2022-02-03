//
// Created by Brandon Castro on 12/10/21.
//

#include "FileInterface.h"

FileInterface::FileInterface() {
    fileTree.push(Images::image::FILE, "Files", "testData.txt");

    filePrompt.setString("Directory: ");
    filePrompt.setPosition({100, 800});

    currentFile.setString("Files");
    currentFile.setPosition({filePrompt.getPosition().x+filePrompt.getGlobalBounds().width+10, 800});

    import.setString("Import");
    import.setPosition({800, 800});
}

void FileInterface::run(Grid& grid)
{
    sf::RenderWindow window(windowSize, "Files");
    sf::Color background = Colors::getColor(Colors::GRAY);

    bool run = true;

    while (window.isOpen() && run)
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            fileTree.addEventHandler(window,event);

            if (import.checkCLick(window,event))
            {
                importData(grid);
                run = false;
            }

            import.addEventHandler(window, event);
        }

        if (hack::currentFile != currentFile.getString())
        {
            currentFile.setString(hack::currentFile);
        }

        fileTree.update();

        window.clear(background);
        window.draw(filePrompt);
        window.draw(currentFile);
        window.draw(import);
        window.draw(fileTree);
        window.display();
    }
}

void FileInterface::importData(Grid &grid)
{
    std::ifstream file;
    file.open(currentFile.getString());

    if(file.is_open())
    {
        grid.clear();

        std::string input;
        while(file >> input)
        {
            grid.add(std::stof(input));
        }

        file.close();
    }
}

void FileInterface::exportGrid(const Grid &grid)
{
    std::ofstream file;
    std::string fileName = "Files/";
    fileName += currentDataTime();
    fileName += ".txt";

    if (grid.getSize() > 0)
    {
        file.open(fileName);

        if (file.is_open())
        {
            std::cout << "File is open" << std::endl;

            for (int i = 0; i < grid.getSize(); i++)
            {
                file << grid.getValues()[i] << std::endl;
            }
        }


        file.close();
    }
}

std::string FileInterface::currentDataTime() const {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}