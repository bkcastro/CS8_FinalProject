//
// Created by Brandon Castro on 12/8/21.
//

#include "ContainMenus.h"

ContainMenus::ContainMenus() {

    playButton.setPosition({1000,1200});
    playButton.setTask(PLAYBUTTON);

    files.setPosition({0,0});
    files.setSize({250,50});
    files.setTextColor(Colors::getColor(Colors::YELLOW));
    files.setBoxColor(Colors::getColor(Colors::GRAY));
    files.setText("File");
    files.add("Save Data", EXPORT);
    files.add("Import", IMPORT);

    system.setPosition({250,0});
    system.setSize({250,50});
    system.setTextColor(Colors::getColor(Colors::YELLOW));
    system.setBoxColor(Colors::getColor(Colors::GRAY));
    system.setText("System");
    system.add("Shuffle", SHUFFLE);
    system.add("Add", ADD);
    system.add("Sub", SUB);

    algorithms.setPosition({500,0});
    algorithms.setSize({250,50});
    algorithms.setTextColor(Colors::getColor(Colors::YELLOW));
    algorithms.setBoxColor(Colors::getColor(Colors::GRAY));
    algorithms.add("SelectionSort", ALGORITHM);
    algorithms.add("BubbleSort", ALGORITHM);
    algorithms.add("MergeSort", ALGORITHM);

    delay.setTitle("Delay");
    delay.setMin(0);
    delay.setMax(100);
    delay.setTask(DELAY);
    delay.setPosition({100,1200});
    Delay::delay = static_cast<long long>(delay.getValue());

    width.setTitle("Width");
    width.setMin(1);
    width.setMax(50);
    width.setTask(WIDTH);
    width.setPosition({100,1300});

    colorPicker.setPosition({1100, 1200});
    colorPicker.setTask(COLOR);

    textBox.setPosition({1600, 1200});
    textBox.setSize({200, 50});
    textBox.setLabel("Set Max : ");
    textBox.setTask(MAXSIZE);
}

void ContainMenus::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(playButton);
    window.draw(files);
    window.draw(system);
    window.draw(algorithms);
    window.draw(delay);
    window.draw(width);
    window.draw(colorPicker);
    window.draw(textBox);
}

void ContainMenus::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    playButton.addEventHandler(window, event);
    files.addEventHandler(window, event);
    system.addEventHandler(window, event);
    algorithms.addEventHandler(window, event);
    delay.addEventHandler(window,event);
    width.addEventHandler(window,event);
    colorPicker.addEventHandler(window,event);
    textBox.addEventHandler(window,event);
}

void ContainMenus::update() {
    system.update();
    files.update();
    algorithms.update();
    textBox.update();
}
