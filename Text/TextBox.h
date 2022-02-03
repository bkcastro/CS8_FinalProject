//
// Created by Brandon Castro on 12/10/21.
//

#ifndef CS8_FINALPROJECT_TEXTBOX_H
#define CS8_FINALPROJECT_TEXTBOX_H
#include "../Tools/Box.h"
#include "MultiText.h"
#include "../Tools/MouseEvents.h"

/*
 * This class handles making text box easy each textbox class contains one box item and one multitext item
 * the box act like a parameter for the multitext needs to stay within the box
 * make sure to keep in mind the average height of a letter/sf::text character
 * This class also needs to keep in mind if it is active or not
 * what I mean is if the mouse has clicked on the box if the mouse clicks outside the box then
 * the class is not active
 */

class TextBox : public sf::Drawable, public States{
private:
    sf::FloatRect absolute;
    bool active;
    MultiText text;
    Box box;
    Letter title;

public:
    TextBox();
    TextBox(sf::Vector2f pos, sf::Vector2f size);
    TextBox(std::string input, sf::Vector2f pos, sf::Vector2f size);

    sf::FloatRect getGlobalBounds() const;

    // functions to change the label size and position
    void setLabel(std::string label);
    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f pos);
    void setTask(TaskObjects obj);

    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

// from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

//from SnapshotInterface
//    virtual Snapshot& getSnapshot();
//    virtual void applySnapshot(const Snapshot& snapshot);
};
#endif //CS8_FINALPROJECT_TEXTBOX_H
