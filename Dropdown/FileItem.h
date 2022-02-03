//
// Created by Brandon Castro on 12/7/21.
//

#ifndef CS8_FINALPROJECT_FILEITEM_H
#define CS8_FINALPROJECT_FILEITEM_H
#include "Item.h"
#include "../Images/Images.h"
#include "Helper.h"

class FileItem : public Item
{
public:
    //Constructors
    FileItem();
    //FileItem(Images::image icon, std::string text, sf::Vector2f position);
    FileItem(Images::image icon, std::string text, sf::Vector2f size, sf::Vector2f position);

    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    virtual void update();
    //Returns the bounds of the item
    sf::FloatRect getGlobalBounds() const;
    //returns the size of the item
    sf::Vector2f getSize() const;
    //returns the size of the item
    sf::Vector2f getPosition() const;
    //sets the position of the item
    virtual void setPosition(sf::Vector2f pos);
    // sets the size of the tiem
    virtual void setSize(sf::Vector2f size);
    // set the text
    virtual void setText(std::string text);
    //uses an enum to change the icon to a folder or file
    void setIcon(Images::image icon);


    std::string getAddress() const;
private:
    //this is the folder or file icon
    sf::Sprite icon;
    std::string parent;
    std::string addressString;
    std::vector<std::string> address;
    float padding = 5;
};

#endif //CS8_FINALPROJECT_FILEITEM_H
