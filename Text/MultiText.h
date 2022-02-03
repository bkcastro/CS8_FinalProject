//
// Created by Brandon Castro on 12/9/21.
//

#ifndef CS8_FINALPROJECT_MULTITEXT_H
#define CS8_FINALPROJECT_MULTITEXT_H
#include "../GUI_Components.h"
#include "../LinkList/LinkList.h"
#include "Letter.h"
#include "Cursor.h"
#include "KeyShortcut.h"
#include "SpecialWords.h"
#include "TempHistory.h"
#include "../Tools/Task.h"

/*
 * This class handles text input along with commands
 * We can set the position and parameter we want the text to happen
 * We can activate and deactivate certain commands to fit our environment
 */


class MultiText : public GUI_Components{
private:
    Linklist<Letter> list;
    Cursor cursor;
    TempHistory history;

    sf::FloatRect dimensions;

    sf::Vector2f position;
    sf::Vector2f parameter;

    sf::Vector2f origin;
    // These commands are able to be changed to fit their environment
    // For example if we want to put multitext in a box that does not give the text enough space
    // to enter a new line then we would just disable enter.

    TaskObjects function;
public:
    MultiText();
    MultiText(sf::Vector2f pos, sf::Vector2f par);

    void setTask(TaskObjects obj);
    void setPosition(sf::Vector2f pos);  // make sure position is aligned with parameter
    void setParameter(sf::Vector2f par); // you would pass in the parameter of window for example
    void disableCursor();
    void enableCursor();

    void tab();
    void enter();

    bool push_back(char c);
    bool pop();
    void clear();
    void addString(std::string text);
    std::string getString() const;

    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

// from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    Snapshot& getSnapshot() override;

// this function will apply a snapshot to the object.
//This will revert the object back to the state that has been recorded in the snapshot
    void applySnapshot(const Snapshot& snapshot) override;
};
#endif //CS8_FINALPROJECT_MULTITEXT_H
