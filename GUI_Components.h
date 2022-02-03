//
// Created by Brandon Castro on 12/7/21.
//

#ifndef CS8_FINALPROJECT_GUI_COMPONENTS_H
#define CS8_FINALPROJECT_GUI_COMPONENTS_H
#include <SFML/Graphics.hpp>
#include "Snapshot.h"
#include "Tools/States.h"
#include "SnapshotInterface.h"

class GUI_Components : public sf::Drawable , public States
{
//from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

//from SnapshotInterface
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};

#endif //CS8_FINALPROJECT_GUI_COMPONENTS_H
