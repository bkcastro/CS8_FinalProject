//
// Created by Brandon Castro on 12/7/21.
//

#ifndef CS8_FINALPROJECT_PLAYBUTTON_H
#define CS8_FINALPROJECT_PLAYBUTTON_H
#include <SFML/Graphics.hpp>
#include "../Images/Images.h"
#include "States.h"
#include "MouseEvents.h"
#include "Task.h"

// the default origin of the sprites are the middle
class PlayButton : public sf::Drawable, public States {
private:
    sf::Sprite play;
    sf::Sprite pause;

    TaskObjects function;
public:
    PlayButton();

    void setPosition(sf::Vector2f pos);
    void setTask(TaskObjects obj);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

};


#endif //CS8_FINALPROJECT_PLAYBUTTON_H
