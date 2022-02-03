//
// Created by Brandon Castro on 12/6/21.
//

#include "MainProgram.h"

MainProgram::MainProgram() = default;

void MainProgram::run()
{
    sf::RenderWindow window(sf::VideoMode(2200, 1500), "Data Visualization");

    sf::Color background = Colors::getColor(Colors::GRAY);

    ContainMenus menu;

    sf::Clock timer;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            menu.addEventHandler(window,event);
        }

        update();
        menu.update();

        window.clear(background);
        window.draw(stage);
        window.draw(menu);
        window.display();


        if (algorithms.getPlay() && Delay::delay < timer.getElapsedTime().asMilliseconds())
        {
            algorithms.sort(stage);
            timer.restart();
        }
    }

}

void MainProgram::update()
{
    // process task to do

    while(!Task::toDoList.empty())
    {
        TaskSnapshot hold = Task::toDoList.front();

        switch(hold.task)
        {
            case DELAY : Delay::delay = static_cast<long long>(hold.delay);
                std::cout << Delay::delay << std::endl;
            break;
            case WIDTH : stage.setWidth(hold.width);
            break;
            case SHUFFLE : stage.Shuffle();
                algorithms.restAlgorithms(stage);
            break;
            case ADD : stage.add();
                algorithms.restAlgorithms(stage);
            break;
            case SUB : stage.pop();
                algorithms.restAlgorithms(stage);
            break;
            case EXPORT : interface.exportGrid(stage);
                break;
            case IMPORT : interface.run(stage);
                break;
            case RANDOMIZE : stage.Randomize();
            break;
            case PLAYBUTTON : algorithms.setPlay(hold.play);
            break;
            case ALGORITHM : algorithms.setAlgorithm(hold.algor);
                break;
            case MAXSIZE : // gotta make sure input is valid
                        if(TaskHelper::is_number(hold.maxSize))
                        {
                            if (std::stoi(hold.maxSize) >= 0) {
                                stage.updateMaxSize(std::stoi(hold.maxSize));
                                algorithms.restAlgorithms(stage);
                            }
                        }
                break;
            case COLOR : stage.setColor(hold.color);
                algorithms.setBarColor(hold.color);
            break;
            case NONE :
            default: break;
        }

        Task::toDoList.pop();
    }
}


