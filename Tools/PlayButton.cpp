//
// Created by Brandon Castro on 12/7/21.
//

#include "PlayButton.h"

PlayButton::PlayButton() {
    play.setTexture(Images::getImage(Images::PLAY));
    pause.setTexture(Images::getImage(Images::PAUSE));

    //both pause and play png are 80x80
    sf::Vector2f middle = {40,40};

    play.setOrigin(middle);
    pause.setOrigin(middle);

    enableState(PAUSESTATES); // default to play
}

void PlayButton::setPosition(sf::Vector2f pos)
{
    play.setPosition(pos);
    pause.setPosition(pos);
}

void PlayButton::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (checkState(PLAYSTATES))
    {
        window.draw(play);
    }
    else
    {
        window.draw(pause);
    }
}

void PlayButton::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<sf::Sprite>::mouseClicked(play, window))
    {
        TaskSnapshot temp;
        temp.task = function;

        if (checkState(PLAYSTATES))
        {
            disableState(PLAYSTATES);
            enableState(PAUSESTATES);
            TaskHelper::convert(false, temp);
        }
        else
        {
            disableState(PAUSESTATES);
            enableState(PLAYSTATES);
            TaskHelper::convert(true, temp);
        }

        Task::toDoList.push(temp);
    }
}

void PlayButton::setTask(TaskObjects obj)
{
    function = obj;
}
