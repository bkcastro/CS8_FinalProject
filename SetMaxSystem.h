//
// Created by Brandon Castro on 12/10/21.
//

#ifndef CS8_FINALPROJECT_SETMAXSYSTEM_H
#define CS8_FINALPROJECT_SETMAXSYSTEM_H
#include "Text/TextBox.h"
#include "Tools/Task.h"

class SetMaxSystem : public  sf::Drawable {
private:


public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //CS8_FINALPROJECT_SETMAXSYSTEM_H
